class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto flight:flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v,w});
        }
        vector<int> minstop(n,INT_MAX); // min no of stops to reach a city
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq; //cost,city,stop
        pq.push({0,src,0});
        minstop[src] = 0;
        while(!pq.empty()){
            auto[cost,city,stop] = pq.top();
            pq.pop();
            if(city==dst) return cost;
            if(stop>k) continue;
            if(minstop[city]!=INT_MAX && minstop[city]<stop) continue;
            minstop[city] = min(minstop[city], stop);
            for(auto ad:adj[city]){
                int newcost = ad.second;
                int next = ad.first;
                pq.push({cost+newcost,next, stop+1});
            }
        }
        return -1;
    }
};