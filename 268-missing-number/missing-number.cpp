class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> mp;
        for(int i= 0 ; i<nums.size(); i++){
            mp.insert(nums[i]);
        }
        for(int i = 0 ; i <=nums.size(); i++){
            if(mp.find(i)==mp.end())
            return i;
        }
        return 0;
    }
};