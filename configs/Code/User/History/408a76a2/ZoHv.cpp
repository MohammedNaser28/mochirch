/*
One day, Sherlock and Watson were sitting next to the fire and talking.
Sherlock was telling Waston how much he likes palindromes and that he
wants everything in this world to be a palindrome.
A palindrome is a string that reads the same way backward as forward; for
example, strings 1, 111 and 101 are palindromes, but strings 110 and 10
are not.
Watson asked Sherlock if he could form a palindrome from some zeros
and ones. Sherlock solved this problem in no time. He asked Watson if he
could tell him the second lexicographically smallest palindrome that can
be formed.
A string is lexicographically smaller than a string if, in the first position
where and differ, the string has a letter that appears earlier in the
alphabet than the corresponding letter in .
Input
    The first line contains a single integer — the number of
    test cases.
    a b
    a b a
    b
    t (1 ≤ t ≤ )103
    The first and only line of each test case contains two integers and
    — the number of zeros and ones respectively.
    It's guaranteed that for each test case .
    It's guaranteed that the sum of over all test cases doesn't exceed.

Output
    For each test case, print second lexicographically smallest palindrome
    that can be formed or if there is no such palindrome.
*/