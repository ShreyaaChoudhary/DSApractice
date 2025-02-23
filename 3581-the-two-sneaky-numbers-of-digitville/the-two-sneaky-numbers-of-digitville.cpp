class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        set<int> ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        for(auto m : mp){
            if(m.second>1){
                ans.insert(m.first);
            }
        }
        vector<int> vs(ans.begin(), ans.end());
        return vs;
    }
};