class Solution {
public:
    int convert(int &n){
        int flag = (n==0)?1:0;
        return flag;
    }
    int minOperations(vector<int>& nums) {
        // bool allones = true;
        // for(auto i: nums){
        //     if(i==0){
        //         allones = false;
        //         break;
        //     }
        // }
        // if(allones)
        // return 0;
        int minop = 0;
        for(int i = 0 ; i<=nums.size()-3; i++){
            if(nums[i]==0){
                nums[i] = convert(nums[i]);
                nums[i+1]= convert(nums[i+1]);
                nums[i+2]= convert(nums[i+2]);
                minop++;
            }
        }
        for(int i:nums){
            if(i==0)
            return -1;
        }
        return minop;
    }
};