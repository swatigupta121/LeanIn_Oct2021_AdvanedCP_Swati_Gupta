class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src, int parent, vector<int> adj[], vector<bool> &vis)
    {
       vis[src]=true;
       //adj of src
       for(auto it:adj[src])
       {
           if(!vis[it])
           {
               if(dfs(it,src,adj,vis))
               {
                   return true;
               }
           }
           else if(it!=parent)
           {
               return true;
           }
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        // Code here
        vector<bool>vis(V,false);
        for(int i =0;i<V;i++)
        {
           if(!vis[i])
           {
               bool f = dfs(i,-1,adj,vis);
               if(f)
               {
                   return true;
               }
           }
        }
        return false;
    }
};
