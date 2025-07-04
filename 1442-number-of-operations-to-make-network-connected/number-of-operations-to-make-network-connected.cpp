class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i<n ; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionfind(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px==py)//nodes from same cmponent
        return;
        if(rank[px]>rank[py])
        parent[py] = px;
        else if(rank[px]<rank[py])
        parent[px] = py;
        else{
            parent[py] = px;
            rank[px]++;
        }        
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DSU dsu(n);
        for(auto conn:connections){
            dsu.unionfind(conn[0],conn[1]);
        }
        int conncnt= 0;
        for(int i = 0 ; i<n ; i++){
            if(dsu.find(i)==i){
                conncnt++;
            }
        }
        return conncnt-1;
    }
};