class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node,vector<int> &vis,stack<int> &st,vector<int> adj[])
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,st,adj);
            }
        }
        st.push(node);
    }
    void revDfs(int node,vector<int>&vis,vector<int> adj[])
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            revDfs(it,vis,adj);
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,st,adj);
            }
        }
       
        vector<int> transpose[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }
       
        int comp=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                revDfs(node,vis,transpose);
                comp++;
            }
        }
      
        return comp;
    }
    
};
