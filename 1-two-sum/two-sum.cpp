class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0 ; i<n; i++){
            int j = nums[i];
            int rem = target-j;
            if(mp.find(rem)!=mp.end()){
                return {i,mp[rem]};
            }
            mp[j]=i;
        }
        return {};
    }
};