class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //brute 
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int sum = 0; // Reset sum for each starting point
            
            for(int j = i; j < n; j++) {
                sum += nums[j]; // Expand subarray
                
                if(sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};