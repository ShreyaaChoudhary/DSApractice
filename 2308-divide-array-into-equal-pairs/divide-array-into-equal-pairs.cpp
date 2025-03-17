class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0 ; i < nums.size(); i++){
                mp[nums[i]]++;
        }
        for(auto c:mp){
            if(c.second%2)
                return false;
            
        }
        return true;
    }
};