class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        vector<int> res;
        dfs(visited,0,res,adj);
        return res;
    }
    void dfs(vector<int>& visited,int v,vector<int>& res, vector<int> adj[])
    {
        visited[v]=1;
        res.push_back(v);
        for(int i=0;i<adj[v].size();i++)
        {
            if(visited[adj[v][i]]==0)
            {
                dfs(visited,adj[v][i],res,adj);
            }
        }
    }
};
