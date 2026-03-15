#include <stdio.h>
#include <stdlib.h>
long long fibbonaci(long long n,long long m)
{
	long long t1=1;
	long long t2=1;
	long long s=0;
	if(n<3)
	return 1;
	for(long long i=3;i<=n;i++)
	{
	    s=t2+t1;
	    s=s%m;
	    t1=t2;
	    t2=s;
	    
	}
	return s;
}
int main()
{
	long long n,m;
	scanf("%lld %lld",&n,&m);
	long long s=fibbonaci(n,m);
	printf("%lld",s);
}

