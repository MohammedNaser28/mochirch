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
            # Initialize variables for computing LDS from position l
            # Use a list to store values in decreasing order and their counts
            stack = []  # Stores (value, count) pairs for potential LDS endings
            for r in range(l, n):
                # Current element
                curr = p[r]
                
                # If stack is empty or current element is smaller than the last in stack
                if not stack or curr < stack[-1][0]:
                    stack.append((curr, 1))
                else:
                    # Find the position where curr can be inserted
                    # Since we need decreasing sequence, find first value <= curr
                    while stack and stack[-1][0] <= curr:
                        stack.pop()
                    stack.append((curr, 1))
                
                # The length of LDS for subarray [l:r+1] is the size of stack
                total += len(stack)
                
                # If r >= l+1, use the condition max(p[r-1], p[r]) > p[r+1] if possible
                # This helps prune or optimize further, but we handle it implicitly here
                if r < n-1 and max(p[r-1], p[r]) <= p[r+1] and r-1 >= l:
                    # This should not happen due to problem constraint
                    pass
        
        print(total)

# Run the solution
solve()