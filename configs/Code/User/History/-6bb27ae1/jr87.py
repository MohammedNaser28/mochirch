def solve():
    # Read number of test cases
    t = int(input())
    
    for _ in range(t):
        # Read n and permutation
        n = int(input())
        p = list(map(int, input().split()))
        
        # Total sum of LDS lengths for all subarrays
        total = 0
        
        # For each starting position l
        for l in range(n):
            # Use a list to simulate a stack for decreasing sequence
            # Store values in decreasing order
            stack = []
            # For each ending position r
            for r in range(l, n):
                curr = p[r]
                
                # Maintain stack in decreasing order
                while stack and stack[-1] >= curr:
                    stack.pop()
                stack.append(curr)
                
                # LDS length for subarray [l:r+1] is the size of stack
                total += len(stack)
                
                # Optimization: If stack size ≥ 3, check if we can prune
                # Due to max(p_i, p_{i+1}) > p_{i+2}, we can limit stack size
                if r < n-2 and len(stack) >= 3:
                    # If max(p_r-1, p_r) ≤ p_{r+1}, we can potentially skip
                    # But condition guarantees max(p_r-1, p_r) > p_{r+1}
                    pass
        
        print(total)

# Run the solution
solve()