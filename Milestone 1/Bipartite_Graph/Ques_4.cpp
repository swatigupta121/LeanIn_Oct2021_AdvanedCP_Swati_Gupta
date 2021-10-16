class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited(V,-1);
	   //-1 for not visited any other for visited
	   //using same array for colors(0,1)
	   queue<int> q;
	   for(int i=0;i<V;i++)
	   {
	       if(visited[i]==-1)
	       {
	          q.push(i);
	          visited[i]=0;
	          while(!q.empty())
	          {
	             for(int j=0;j<adj[q.front()].size();j++)
	             {
	                 if(visited[adj[q.front()][j]]==-1)
	                 {
	                     q.push(adj[q.front()][j]);
	                     visited[adj[q.front()][j]]=!visited[q.front()];
	                 }
	                 else if(visited[adj[q.front()][j]]!=(!visited[q.front()]))
	                 return false;
	                 
	             }
	             q.pop();
	          }
	       }
	   }
	   return true;
	}

};
