class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxi =0 ;
        for(int i = 0; i<stones.size()-2; i++){
            maxi = max(maxi, stones[i+2]-stones[i]);
        }
        maxi = max(maxi, stones[1]-stones[0]);
        maxi = max(maxi, stones[stones.size()-1] - stones[stones.size()-2]);
        return maxi;
    }
};