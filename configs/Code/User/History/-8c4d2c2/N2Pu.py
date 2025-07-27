MOD = 998244353

def modinv(x):
    return pow(x, MOD - 2, MOD)

import sys
import threading

def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    n, m = map(int, sys.stdin.readline().split())
    segments = []
    for _ in range(n):
        l, r, p, q = map(int, sys.stdin.readline().split())
        segments.append((l, r, p, q))

    # For each cell, keep a list of segments covering it
    cell_segments = [[] for _ in range(m + 2)]  # 1-based

    for idx, (l, r, p, q) in enumerate(segments):
        cell_segments[l].append((idx, +1))
        cell_segments[r + 1].append((idx, -1))

    # For each segment, precompute probability and its complement
    seg_prob = []
    seg_prob_comp = []
    for l, r, p, q in segments:
        prob = p * modinv(q) % MOD
        seg_prob.append(prob)
        seg_prob_comp.append((q - p) * modinv(q) % MOD)

    # For each cell, maintain the set of active segments
    from collections import defaultdict

    active = set()
    result = 1

    # For each cell 1..m
    segs_in_cell = [[] for _ in range(m + 2)]
    for i in range(1, m + 1):
        # Update active segments
        for idx, typ in cell_segments[i]:
            if typ == +1:
                active.add(idx)
            else:
                active.discard(idx)
        segs_in_cell[i] = list(active)

    for i in range(1, m + 1):
        segs = segs_in_cell[i]
        k = len(segs)
        if k == 0:
            print(0)
            return
        # For each segment, probability it is present and others are absent
        prob = 0
        for j in range(k):
            idx = segs[j]
            p1 = seg_prob[idx]
            p2 = 1
            for l in range(k):
                if l == j:
                    continue
                idx2 = segs[l]
                p2 = p2 * seg_prob_comp[idx2] % MOD
            prob = (prob + p1 * p2) % MOD
        result = result * prob % MOD

    print(result)

if __name__ == "__main__":
    threading.Thread(target=main).start()