#!/bin/bash

echo "=== Competitive Programming Test Suite ==="
echo "Algorithm: Maximum Subarray Sum (Kadane's Algorithm)"
echo

# Compile the C++ code
echo "Compiling mochi.cpp..."
g++ -o output/mochi mochi.cpp
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    exit 1
fi
echo "✅ Compilation successful!"
echo

# Run the program with test input
echo "Running tests..."
./output/mochi < input.txt > actual_output.txt

# Compare with expected output
echo "Comparing results..."
if diff -q expected_output.txt actual_output.txt > /dev/null; then
    echo "✅ All test cases passed!"
    echo
    echo "Test Cases:"
    echo "1. Mixed positive/negative: [-2, 1, -3, 4, 5] → Expected: 6 (subarray [4, 5])"
    echo "2. All positive: [1, 2, 3, 4, 5, 6] → Expected: 21 (entire array)"
    echo "3. All negative: [-1, -2, -3, -4] → Expected: -1 (single element)"
    echo "4. Large negative gap: [5, -10, 3] → Expected: 5 (single element [5])"
    echo "5. Complex case: [-2, -3, 4, -1, 2, 1, -5] → Expected: 6 (subarray [4, -1, 2, 1])"
else
    echo "❌ Test cases failed!"
    echo "Expected output:"
    cat expected_output.txt
    echo
    echo "Actual output:"
    cat actual_output.txt
    echo
    echo "Differences:"
    diff expected_output.txt actual_output.txt
fi

# Clean up
rm -f actual_output.txt
