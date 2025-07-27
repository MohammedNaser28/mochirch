def can_build(b):
    if b[0] != 1:
        return False
    s = 1
    for i in range(1, len(b)):
        if b[i] > s:
            return False
        s += b[i]
    return True

t = int(input())
for _ in range(t):
    n = int(input())
    b = list(map(int, input().split()))
    print("YES" if can_build(b) else "NO")
