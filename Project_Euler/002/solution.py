for _ in range(int(input())):
    N = int(input())
    A, B, C = 1, 2, 3
    ans = 2
    while C < N:
        if not C % 2:
            ans += C
        A, B, C = B, C, B + C
    print(ans)
