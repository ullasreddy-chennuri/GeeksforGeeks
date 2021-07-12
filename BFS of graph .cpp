/*

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and 
find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph.
Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

*/

	vector<int>bfsOfGraph(int v, vector<int> adj[])
	{
	    // Code here
	    vector<int> res;
	    bool visited[v]={false};
	    visited[0]=true;
	    list<int> queue;
	    queue.push_back(0);
	    while(!queue.empty()){
	        int t = queue.front();
	        res.push_back(t);
	        queue.pop_front();
	        for(int i=0;i<adj[t].size();i++){
	            if(!visited[adj[t][i]]){
	                visited[adj[t][i]]=true;
	                queue.push_back(adj[t][i]);
	            }
	        }
	    }
	    return res;
	}
