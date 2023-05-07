//luogu
//【深基13.例1】查找
#include<iostream>

using namespace std;
const int N=1000006;
const int M=100006;
long long Binary_Search(long long *arr,long long n,long long q)
{
    long long l=0,r=n+1,m;
    while(l+1<r)
    {
        m=(l+r)/2;
        if(arr[m]<q){
            l=m;
        }else {
            r=m;
        }
    }
    if(arr[r]==q)
    {
        return r;
    }else {
        return -1;
    }
}
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long *arr=(long long *)malloc(sizeof(long long)*N);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    long long q,res[M];
    long long temp=m;
    while(temp--)
    {
        scanf("%lld",&q);
        res[temp]=Binary_Search(arr,n,q);
    }
    for(long long i=m-1;i>=0;i--)
    {
        printf("%lld ",res[i]);
    }
    return 0;
}