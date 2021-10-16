class Solution
{
	public: 
	void dfs(int src,vector<int>&vis,stack<int>&st,vector<int>adj[])
    {
        vis[src]=1;
        for(auto x:adj[src])
        {
            if(!vis[x])
            {
                dfs(x,vis,st,adj);
            }
        }
        st.push(src);
    }
     
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        // code here
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,st,adj);
            }
        }
        vector<int>topo; 
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
