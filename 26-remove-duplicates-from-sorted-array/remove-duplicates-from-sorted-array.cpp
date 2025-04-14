class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1,k=0;
        int n = nums.size();
        for(int i = 1 ; i<n; i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
                k++;
            }
        }
        return j
        ;
    }
};