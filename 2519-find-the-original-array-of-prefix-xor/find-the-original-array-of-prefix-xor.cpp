class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        if (n==0) return {};
        ans[0] = pref[0];
        for(int i = 1 ; i< n ; i++){
            int prev = i-1;
            int xx = pref[prev]^pref[i];
            ans[i] = xx;
        }
        return ans;
    }
};