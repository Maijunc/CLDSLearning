#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000005;

//判断从这个点起前面砍下的所有的总木材长度是否能满足需要
int Cut(int *arr,int n,int m,int mid)//M 表示需要的木材总长度
{
    int total=0;
    int t;//余数
    for(int i=1;i<=n;i++)
    {
        if((t=arr[i]-mid)>0)
        {
            total+=t;
        }
        if(total>=m)return 1; //一边找一边判断，这样就不用开long long了
    }
    return 0;
}

int Binary_Search(int *arr,int n,int m)
{
    int l=-1,r=arr[n]+1,mid;
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(Cut(arr,n,m,mid))
        {
            l=mid; //向左找
        }else {
            r=mid; //向右找
        }
    }
    return l;
}
//4 26 40 42 46

int main()
{
    int *arr=(int *)malloc(sizeof(int)*N);
    int n,m;
    int res;
    scanf("%d%d",&n,&m); //N 表示树木的数量 M 表示需要的木材总长度。
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+n+1);
    res=Binary_Search(arr,n,m);
    printf("%d",res);
    return 0;

}