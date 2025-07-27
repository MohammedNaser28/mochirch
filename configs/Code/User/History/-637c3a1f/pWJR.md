# Competitive Programming Test Code

## Algorithm: Maximum Subarray Sum (Kadane's Algorithm)

This implementation solves the classic "Maximum Subarray Problem" using Kadane's algorithm with O(n) time complexity.

### Files Structure:
- `mochi.cpp` - Main C++ implementation with Kadane's algorithm
- `input.txt` - Test input cases
- `expected_output.txt` - Expected results for verification
- `test.sh` - Automated test runner script
- `output/mochi` - Compiled executable

### Algorithm Explanation:
Kadane's algorithm finds the maximum sum of any contiguous subarray in O(n) time by:
1. Maintaining a running sum of the current subarray
2. At each element, deciding whether to extend the current subarray or start a new one
3. Keeping track of the maximum sum seen so far

### Test Cases:
1. **Mixed positive/negative**: `[-2, 1, -3, 4, 5]` → `9` (subarray `[4, 5]`)
2. **All positive**: `[1, 2, 3, 4, 5, 6]` → `21` (entire array)
3. **All negative**: `[-1, -2, -3, -4]` → `-1` (single element `-1`)
4. **Large negative gap**: `[5, -10, 3]` → `5` (single element `[5]`)
5. **Complex case**: `[-2, -3, 4, -1, 2, 1, -5]` → `6` (subarray `[4, -1, 2, 1]`)

### How to Run:
```bash
# Run automated test suite
./test.sh

# Or manually compile and run
g++ -o output/mochi mochi.cpp
./output/mochi < input.txt
```

### Usage for New Problems:
1. Modify the `pewpew()` function with your algorithm
2. Update `input.txt` with your test cases
3. Update `expected_output.txt` with expected results
4. Run `./test.sh` to verify your solution

The template includes useful competitive programming macros and debugging utilities.
