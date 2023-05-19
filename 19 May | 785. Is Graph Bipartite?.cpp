class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);

        for(int node = 0; node < n; node++){
            if(color[node] != 0) continue;

            queue<int> q;
            q.push(node);
            color[node] = 1;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int adjN : graph[curr]){
                    if(color[adjN] == 0){
                        color[adjN] = -color[curr];
                        q.push(adjN);
                    }
                    else if(color[adjN] != -color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
