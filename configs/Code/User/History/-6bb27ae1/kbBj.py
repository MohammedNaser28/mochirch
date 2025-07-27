def solve():
    t = int(input())  # Number of test cases
    
    for _ in range(t):
        n = int(input())  # Length of permutation
        p = list(map(int, input().split()))  # Permutation
        
        total = 0  # Sum of LDS lengths for all subarrays
        
        # For each ending position r
        for r in range(n):
            # For subarray [l,r], LDS length is determined by the number of
            # elements in a decreasing sequence ending at p[r]
            # Due to condition, LDS lengths are small, so we check recent elements
            max_lds = 1  # Minimum LDS length is 1 (p[r] itself)
            
            # Check if we can form LDS of length 2 or more
            if r >= 1:
                if p[r-1] > p[r]:
                    max_lds = 2  # Can form [p[r-1], p[r]]
                # Check for length 3, but only if r >= 2
                if r >= 2:
                    if p[r-2] > p[r-1] > p[r]:
                        max_lds = 3  # Can form [p[r-2], p[r-1], p[r]]
                    elif p[r-2] > p[r] and p[r-1] < p[r]:
                        max_lds = max(max_lds, 2)  # Can form [p[r-2], p[r]]
            
            # For each l from 0 to r, the LDS length for [l,r] is:
            # - max_lds if p[l] can start a decreasing sequence ending at p[r]
            # - Otherwise, the LDS length is determined by elements after l
            for l in range(r + 1):
                # LDS length for [l,r] is max_lds if p[l] fits in the sequence
                # Due to condition, we assume max_lds is small (≤ 3)
                lds = max_lds
                if l < r:
                    # Check if p[l] can extend the LDS
                    if p[l] <= p[r]:
                        lds = min(lds, max_lds - 1)  # p[l] can't start LDS ending at p[r]
                    elif l < r-1 and p[l] <= p[r-1] and p[r-1] > p[r]:
                        lds = min(lds, max_lds - 1)  # Adjust based on sequence
                total += lds
        
        print(total)

solve()