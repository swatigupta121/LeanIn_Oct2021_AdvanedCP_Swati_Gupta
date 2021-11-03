class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> ret(V,100000000);
        ret[S] = 0;
        for(int i = 0 ; i < V; i++)
        {
            for(auto it : adj)
            {
                if(ret[it[0]] != INT_MAX and ret[it[1]]  > ret[it[0]] + it[2])
                {
                	ret[it[1]] = ret[it[0]] + it[2];
                }
            }
        }
        return ret;
    }
};
