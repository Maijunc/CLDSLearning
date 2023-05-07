//A-B 数对
#include<iostream>
#include<algorithm>

using namespace std;
const int N=200005;
int Binary_search1(int *arr,int len,int x)
{
    int sum=0;
    int r=len+1,l=-1,m;
    while(l+1<r)
    {
        m=(l+r)/2;
        if(arr[m]<x)
        {
            l=m;
        }else {
            r=m;
        }
    }
    if(arr[r]==x)
    {
        return r;
    }else {
        return -1;
    }

}
int Binary_search2(int *arr,int len,int x)
{
    int sum=0;
    int r=len+1,l=-1,m;
    while(l+1<r)
    {
        m=(l+r)/2;
        if(arr[m]<=x)
        {
            l=m;
        }else {
            r=m;
        }
    }
    if(arr[l]==x)
    {
        return l;
    }else {
        return -1;
    }
}
int main() //2 4 5 5 5 6 7
{
    long long sum=0;
    int n,c,arr[N];
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int l,r;
    for(int i=n-1;arr[i]>c;i--)
    {
        l=Binary_search1(arr,i,arr[i]-c);
        if(l==-1)
        {
            continue;
        }
        r=Binary_search2(arr,i,arr[i]-c);
        sum+=r-l+1;
    }

    printf("%lld",sum);

    return 0;
}