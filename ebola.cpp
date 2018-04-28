#include <bits/stdc++.h>

using namespace std;
vector<int>a[100001];
vector<int>b;
int kt[100001];
int n,k;
void dfs(int u)
{
    kt[u]=1;
    for (int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if (kt[v]==0)
        {
            b.push_back(v);
            dfs(v);
        }
    }
    return;
}
int main()
{
    freopen("ebola.inp","r",stdin);
    freopen("ebola.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        int m,x;
        cin>>m;
        for (int j=1;j<=m;j++)
        {
            cin>>x;
            a[i].push_back(x);
            a[x].push_back(i);
        }
    }
    b.push_back(k);
    dfs(k);
    cout<<b.size()<<endl;
    sort(b.begin(),b.end());
    for (int i=0;i<b.size();i++) cout<<b[i]<<" ";
    return 0;
}