def main():
    import sys
    input = sys.stdin.readline
    t = int(input())
    results = []
    for _ in range(t):
        s = input().strip()
        if "FFT" in s or "NTT" in s:
            # Rearranging by sorting guarantees no "FFT" or "NTT"
            results.append(''.join(sorted(s)))
        else:
            results.append(s)
    print('\n'.join(results))

if __name__ == "__main__":
    main()