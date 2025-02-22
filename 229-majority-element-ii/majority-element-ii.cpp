class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> cs;
        for(int i = 0 ; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto m: mp){
            if(m.second>(nums.size()/3)){
                cs.push_back(m.first);
            }
        }
        return cs;
    }
};