class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int presum=0 ;
        int cnt = 0 ;
        int n = nums.size();
        for(int i = 0 ; i< n; i++){
            presum+=nums[i];
            if(mp.find(presum-k)!=mp.end()){
                cnt= cnt+ mp[presum-k];
            }
            mp[presum]++;
        }
        return cnt;
    }
};