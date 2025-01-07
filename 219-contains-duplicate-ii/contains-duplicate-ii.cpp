class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                //already seen this num i.e 2DISTINCT INDICES
                //abs(i-j)=k
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
            //not seen-> insert num with pos
            
            mp[nums[i]] = i;
        }
        return false;
    }
};