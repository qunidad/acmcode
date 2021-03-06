/*********************** 
 c++ file 
***********************/

#include<iostream> 
#include<cstdio> 
#include<vector> 
#include<map> 
#include<algorithm> 
#include<string> 
#include<cstring> 
#include<set> 
#include<cmath> 
#include<queue> 
#include<fstream> 
#include<ctime> 
#include<iomanip> 
#include<bitset> 
#include<cstdlib> 
#include<deque> 
#include<list> 
#include<stack> 
#include<utility> 
 
#define ll long long 
#define inf 0x3f3f3f3f 
#define lb(x) (x&(-x))
 
using namespace std; 
 
const int M = 200*1000+10; 
int n,m;
int p[M];
int cnt[M]={0};
int pos[M];
int ans[M];
vector<vector<int>> pre(M);
struct qq
{
    int l,r,id;
}q[M];

bool cmp(qq a,qq b)
{
    return a.r<b.r;
}

void add(int x)
{
    while(x<=n)
        ++cnt[x],x+=lb(x);
}

void ins(int x)
{
    int val=p[x-1];
    add(x);
    for(int i=2;i*val<=n;++i)
    {
        if(pos[i*val]<x)
            add(pos[i*val]+1);
        else 
            pre[pos[i*val]].push_back(x);
    }
        
    for(int i=0;i<pre[x-1].size();++i)
        add(pre[x-1][i]);
}

int get(int x)
{
    int re=0;
    while(x)
        re+=cnt[x],x-=lb(x);
    return re;
}

int query(int l,int r)
{
    return get(r)-get(l-1);
}

void solve()
{
    int cur=0;
    for(int i=0;i<m;++i)
    {
        while(cur<q[i].r)
            ins(++cur);
        ans[q[i].id]=query(q[i].l,q[i].r);
        //if(check(q[i].l,q[i].r)!=ans[q[i].id])
            //cout<<"NO";
    }
}
 
int main() 
{ 
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for(int i=0;i<m;++i)
    {
        q[i].id=i;
        scanf("%d%d",&q[i].l,&q[i].r);
    }
    sort(q,q+m,cmp);
    solve();
    for(int i=0;i<m;++i)
        printf("%d\n",ans[i]);
    return 0; 
} 

