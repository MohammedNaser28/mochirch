def longest_decreasing_subsequence(arr, n):
    # For a single element, LDS length is 1
    if n == 1:
        return 1
    
    # dp[i] stores length of LDS ending at index i
    dp = [1] * n
    
    # Compute LDS for each position
    for i in range(1, n):
        for j in range(i):
            if arr[j] > arr[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    return sum(dp)

def solve():
    # Read number of test cases
    t = int(input())
    
    for _ in range(t):
        # Read n and permutation
        n = int(input())
        p = list(map(int, input().split()))
        
        # Initialize result for sum of all LDS lengths
        total = 0
        
        # For each starting position l
        for l in range(n):
            # Compute LDS for subarray starting at l
            # We can optimize by maintaining running LDS
            # But for clarity, we'll compute for each subarray
            for r in range(l, n):
                # Get subarray p[l:r+1]
                subarray = p[l:r+1]
                # Add length of LDS for this subarray
                total += longest_decreasing_subsequence(subarray, r-l+1)
        
        print(total)

# Run the solution
solve()