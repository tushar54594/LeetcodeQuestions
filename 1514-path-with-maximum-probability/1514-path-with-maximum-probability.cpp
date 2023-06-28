class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        //we use max heap since we have to find max prob
        priority_queue<pair<double,int>> pq;
        vector<double> prob(n, 0);  
        prob[start] = 1.0;  //prob of reaching from start to start node is 1
        pq.push({1.0, start});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            double currProb = it.first;
            int currNode = it.second;
            
            for(auto a : adj[currNode]){
                int adjNode = a.first;
                double adjProb = a.second;
                
                if(prob[adjNode] < currProb * adjProb){
                    prob[adjNode] = currProb * adjProb;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }
        
        return prob[end];
    }
};