class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n= nums.size();
        //1st step
        for(int i = n-2; i>=0; i-- ){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            //no dip
            reverse(nums.begin(), nums.end());
            return;
        }
        //2nd step
        for(int i = n-1; i>=ind; i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
    }
};