def main():
    import sys
    input = sys.stdin.readline
    t = int(input())
    results = []
    for _ in range(t):
        s = input().strip()
        # Replace all occurrences of 'FFT' with 'FTF'
        s = s.replace('FFT', 'FTF')
        # Replace all occurrences of 'NTT' with 'TNT'
        s = s.replace('NTT', 'TNT')
        results.append(s)
    print('\n'.join(results))

if __name__ == "__main__":
    main()