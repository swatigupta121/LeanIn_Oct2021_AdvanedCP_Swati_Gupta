class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        queue<int>q;
        vector<bool>visited(V,false);
        q.push(0);
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            res.push_back(f);
           
            for(auto i=0;i<adj[f].size();i++)
            {
                if(!visited[adj[f][i]])
                {
                    q.push(adj[f][i]);
                    visited[adj[f][i]]=true;
                }
            }
           
        }
        return res;
    }
};
