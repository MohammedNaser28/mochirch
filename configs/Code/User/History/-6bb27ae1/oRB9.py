class BIT:
    def __init__(self, n):
        self.tree = [0] * (n + 2)
        self.n = n

    def update(self, i, val):
        while i <= self.n:
            self.tree[i] = max(self.tree[i], val)
            i += i & -i

    def query(self, i):
        res = 0
        while i > 0:
            res = max(res, self.tree[i])
            i -= i & -i
        return res

def solve_case(p):
    n = len(p)
    bit = BIT(n)
    dp = [0] * n
    total = 0

    for i in range(n):
        # longest decreasing subsequence ending at i
        # since we want decreasing, we query values > p[i]
        dp[i] = bit.query(n) - bit.query(p[i]) + 1
        bit.update(p[i], dp[i])
        total += dp[i]
    
    return total

solve_case()