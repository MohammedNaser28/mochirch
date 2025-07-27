def solve():
    t = int(input())  # Number of test cases
    
    for _ in range(t):
        n = int(input())  # Length of permutation
        p = list(map(int, input().split()))  # Permutation
        
        total = 0  # Sum of LDS lengths for all subarrays
        
        # For each ending position r
        for r in range(n):
            # Initialize a list to maintain values in decreasing order
            # Use a list of (value, count) to track elements in LDS
            values = []
            # Process subarrays ending at r, starting from l = r down to 0
            for l in range(r, -1, -1):
                curr = p[l]
                
                # Binary search to find where curr fits in decreasing sequence
                left, right = 0, len(values)
                while left < right:
                    mid = (left + right) // 2
                    if values[mid][0] <= curr:
                        right = mid
                    else:
                        left = mid + 1
                
                # If inserting at end or empty, append new value
                if left == len(values):
                    values.append([curr, 1])
                else:
                    # Replace or update count
                    values[left][0] = curr
                    values[left][1] += 1
                
                # LDS length for subarray [l:r] is the number of elements in values
                total += len(values)
                
                # Optimization: If LDS length ≥ 3, check condition
                # Due to max(p_i, p_{i+1}) > p_{i+2}, LDS lengths are limited
                if r >= l + 2 and len(values) >= 3:
                    # The condition ensures that long decreasing sequences are rare
                    pass
        
        print(total)

solve()