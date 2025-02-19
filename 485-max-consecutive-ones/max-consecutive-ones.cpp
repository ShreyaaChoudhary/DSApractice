class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int c = 0 ;
        vector<int> maxi;
        for(int i = 0 ; i< n ; i++){
            if(nums[i]==1){
                c++;
            }
            else{
                maxi.push_back(c);
                c= 0;
            }
        }
        maxi.push_back(c);
        auto ans = max_element(maxi.begin(), maxi.end());
        return *ans;
    }
};