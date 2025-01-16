class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n= nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            // mp[nums[i]] = count(nums.begin(), nums.end(), nums[i]);
        }
        n=n/2;
        for(auto v: mp){
            if(v.second>n){
                return v.first;
            }
        }
        return 0;
    }
};