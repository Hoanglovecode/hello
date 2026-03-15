def binarysearch(a,l,r,x):
    ans=-1
    while(l<=r):
        m=(l+r)//2
        if(a[m]<=x):
            ans=a[m]
            l=m+1
        else:
            r=m-1
    return ans
n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=[int(input()) for _ in range(m)]
for i in b:
    print(binarysearch(a,0,len(a)-1,i))





