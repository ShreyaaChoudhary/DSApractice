class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int flag;
        map<int,int> mp;
        for(int i = 0 ; i< nums.size(); i++){
            mp[nums[i]] = count(nums.begin(), nums.end(),nums[i]); 
        }
        for(auto &it: mp){
            if(it.second==1){
                flag = it.first;
            }
        }
        return flag;
    }
};