class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        //3 6 1 2 5
        //1 2 3 5 6 
        
        int min = nums[0];
        int ans = 1;
        for(int i=1; i<nums.size(); i++ ){
            if(nums[i]-min>k){
                ans++;
                min = nums[i];
            }
        }
        return ans;
    }
};