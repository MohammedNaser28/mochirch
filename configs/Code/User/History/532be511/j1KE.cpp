#define BOOST_TEST_MODULE PewPewTestSuite
#include <boost/test/included/unit_test.hpp>
#include <gmock/gmock.h>
#include <sstream>
#include <iostream>

// Forward declaration of the function under test
void pewpew();

using ::testing::_;
using ::testing::Invoke;

namespace {
    // Helper to redirect cin/cout for testing
    struct IOContext {
        std::streambuf* orig_cin;
        std::streambuf* orig_cout;
        std::istringstream in;
        std::ostringstream out;
        IOContext(const std::string& input) : in(input) {
            orig_cin = std::cin.rdbuf(in.rdbuf());
            orig_cout = std::cout.rdbuf(out.rdbuf());
        }
        ~IOContext() {
            std::cin.rdbuf(orig_cin);
            std::cout.rdbuf(orig_cout);
        }
        std::string output() const { return out.str(); }
    };
}

BOOST_AUTO_TEST_SUITE(PewPewTests)

BOOST_AUTO_TEST_CASE(test_exact_cover_no_overlap)
{
    // n = 2, m = 2
    // Segments: [1,1] with p=1,q=1 (prob=1), [2,2] with p=1,q=1 (prob=1)
    // Only one way to cover 1 and 2 exactly once: pick both segments
    std::string input = "2 2\n1 1 1 1\n2 2 1 1\n";
    IOContext io(input);
    pewpew();
    // Only one valid mask, probability = 1*1 = 1
    BOOST_CHECK_EQUAL(io.output(), "1\n");
}

BOOST_AUTO_TEST_CASE(test_overlapping_segments_valid_coverings)
{
    // n = 2, m = 2
    // Segments: [1,2] with p=1,q=2 (prob=499122177), [2,2] with p=1,q=1 (prob=1)
    // Only valid mask: pick first for [1,2], not pick second (would cover 2 twice)
    // But picking both covers 2 twice, so only mask 01 is valid (pick only second)
    // But then 1 is not covered. So no valid mask. Let's adjust:
    // Segments: [1,1] p=1,q=2, [1,2] p=1,q=2
    // Now, mask 11: covers 1 twice, invalid. mask 10: covers 1 once, 2 once, valid.
    // mask 10: pick first, not second. prob = 499122177 * 499122176 % MOD
    std::string input = "2 2\n1 1 1 2\n1 2 1 2\n";
    IOContext io(input);
    pewpew();
    // Only mask 10 is valid: pick first, not second
    // prob1 = 1/2 = 499122177, neg_prob2 = 1 - 1/2 = 499122176
    // result = 499122177 * 499122176 % 998244353 = 499122176
    BOOST_CHECK_EQUAL(io.output(), "499122176\n");
}

BOOST_AUTO_TEST_CASE(test_zero_probability_segments)
{
    // n = 2, m = 2
    // Segments: [1,1] p=0,q=1 (prob=0), [2,2] p=1,q=1 (prob=1)
    // Only way to cover both is to pick both, but first has prob 0, so result is 0
    std::string input = "2 2\n1 1 0 1\n2 2 1 1\n";
    IOContext io(input);
    pewpew();
    BOOST_CHECK_EQUAL(io.output(), "0\n");
}

BOOST_AUTO_TEST_CASE(test_impossible_cover)
{
    // n = 1, m = 2
    // Segment: [1,1] p=1,q=1
    // Can't cover both 1 and 2
    std::string input = "1 2\n1 1 1 1\n";
    IOContext io(input);
    pewpew();
    BOOST_CHECK_EQUAL(io.output(), "0\n");
}

BOOST_AUTO_TEST_CASE(test_zero_segments_or_range)
{
    // n = 0, m = 2
    std::string input1 = "0 2\n";
    IOContext io1(input1);
    pewpew();
    BOOST_CHECK_EQUAL(io1.output(), "0\n");

    // n = 2, m = 0
    std::string input2 = "2 0\n1 1 1 1\n1 1 1 1\n";
    IOContext io2(input2);
    pewpew();
    // The only valid covering is the empty covering, which is valid, so answer should be 1
    BOOST_CHECK_EQUAL(io2.output(), "1\n");
}

BOOST_AUTO_TEST_CASE(test_all_segments_probability_one)
{
    // n = 2, m = 2
    // Both segments always chosen
    std::string input = "2 2\n1 1 1 1\n2 2 1 1\n";
    IOContext io(input);
    pewpew();
    // Only one mask is valid: pick both, prob = 1
    BOOST_CHECK_EQUAL(io.output(), "1\n");
}

BOOST_AUTO_TEST_SUITE_END()