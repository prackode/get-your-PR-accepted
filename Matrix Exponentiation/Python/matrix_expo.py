'''
Problem-
Given the following recurrence relation:

G(N) = G(N-1) + G(N-2) + N2
where G(1) = 1 and G(2) = 1.

Given N find G(N). Since G(N) can be very large for bigger N so output it modulo 1000000007
'''

from sys import stdin,stdout
input=stdin.readline

def inp(): return map(int,input().split())

mod=10**9+7
def multiply(a, b):
    cc = 5 #initialise as per M
    mul = [[0 for x in range(cc)] for y in range(cc)]
    for i in range(cc):
        for j in range(cc):
            mul[i][j] = 0
            for k in range(cc):
                mul[i][j] += (a[i][k] * b[k][j]) % mod
                mul[i][j] %= mod
    for i in range(cc):
        for j in range(cc):
            a[i][j] = mul[i][j]
    return a

def power(F, n, inti):
    M = [[4,-5,1,2,-1], [1,0,0,0,0], [0,1,0,0,0], [0,0,1,0,0], [0,0,0,1,0]]   #initialise M here
    if (n == 1):
        return 128
    power(F, int(n // 2),inti)
    F = multiply(F, F)
    if n&1:
        F = multiply(F, M)
    res=0
    for i in range(5):
        res += (F[0][i]*inti[i]) % mod
        res %= mod
    return res

def f(n):
    inti=[64,28,11,1,1]  #V[k] to be initialised
    if n<6:
        return inti[5-n]
    F = [[4,-5,1,2,-1], [1,0,0,0,0], [0,1,0,0,0], [0,0,1,0,0], [0,0,0,1,0]] 
    return power(F, n - 5, inti)

n=int(input())

print(f(n))
