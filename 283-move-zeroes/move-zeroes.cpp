class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzeroindex = 0;
        int n = nums.size();
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i]!=0){
                nums[nonzeroindex] = nums[i];
                nonzeroindex++;
            }
        }
        for(int i = nonzeroindex ; i<n; i++){
            nums[i] = 0;
        }
    }
};