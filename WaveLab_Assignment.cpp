class Test {

    void task(vector<int> adj[], vector<bool> &visited, int c)
    {
        visited[c] = true;
        for(int i : adj[c])
		{
            if(!visited[i]){
                task(adj, visited, i);
            }
        }
    }


public:
    int makeConnected(int n, vector<vector<int>>& ar) 
    {
        int len = ar.size();
        if(len<n-1) return -1;
         vector<int> adj[n];
        for(auto i : ar)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n, false);
        int res = 0;
        for(int i=0; i<n; i++)
        if(!visited[i])
        {
            task(adj, visited, i);
            res++;
        }
        return res - 1;

    }
};

