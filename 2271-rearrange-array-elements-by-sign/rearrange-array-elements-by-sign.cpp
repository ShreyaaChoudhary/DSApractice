class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(),pos = 0,neg = 1;
        vector<int> ans(n,0);
        for(int i = 0 ; i < n ; i++){
            if(nums[i]<0){
                //neg
                ans[neg] = nums[i];
                neg+=2;
            }
            else{
                //pos
                ans[pos] = nums[i];
                pos+=2;
            }
        }
        return ans;
    }
};