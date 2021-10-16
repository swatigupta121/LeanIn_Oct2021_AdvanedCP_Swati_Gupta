#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int u, bool * vis) 
{
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if(!vis[v]) 
        {
            dfs(adj,v,vis);
        }
    }
}

int findConnectedComponents(vector<int> adj[], int n) 
{
    bool vis[n+1] = {false};
    int count = 0;
    for(int i = 1; i <= n; ++i) 
    {
        if(!vis[i]) 
        {
            dfs(adj,i,vis);
            count++;
        }
    }
    return count;
}

int main()
{
    int n,e; cin>>n>>e;
    vector<int> adj[n+1];
    for(int i = 0; i < e; ++i)
    {
        int u,v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<findConnectedComponents(adj,n);
    return 0;
}
