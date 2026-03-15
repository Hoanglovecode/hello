# Hàm fibonaci
def fibo(n):
    if n==0 or n==1:
        return n
    return fibo(n-1)+fibo(n-2)
# Hàm Sum
def sum(n):
    if n==0:
        return 0
    return n+sum(n-1)
# Hàm giai thừa
def fac(n):
    if n==0:
        return 1
    return n*fac(n-1)
# Hàm tổ hợp
def nCk(n,k):
    if k==0 or k==n:
        return 1
    return nCk(n-1,k-1)+nCk(n-1,k)
# Hàm sumdigit
def sumdigit(n):
    if n<10:
        return n
    return n%10 + sumdigit(n//10)
# Ham gcd
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
# BCNN
def lcm(a,b):
    return a*b/gcd(a,b)
if __name__=='__main__':
    n=13
    print(fibo(n))
    print(gcd(10,200))
    print(lcm(10,200))
    print(sum(n))
    print(sumdigit(n))
    print(fac(n))
    print(nCk(n,4))