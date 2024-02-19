import sys, math
def question1(R: int, A: int, B: int):
    import math
    area = R**2
    while (R > 0):
        R *= A
        area += R*R
        R //= B
        area += R*R
    return area


T = int(input())
#PI = math.atan(1)*4
print(PI)
for i in range(1, T+1): 
    R,A,B = map(int, sys.stdin.readline().split())
    ans = PI* question1(R,A,B)
    print("Case #{}: {:.10f}".format(i, ans))


