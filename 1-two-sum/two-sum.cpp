class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hashing
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int j = nums[i];
            int rem = target - j;
            // rem foumd
            if (mp.find(rem) != mp.end()) {

                    return {i, mp[rem]};
                
            }
            mp[j]=i;
        }
        return {};
    }
};