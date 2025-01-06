class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         vector<int> max;
        int c = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                c++;  // Increment count when 1 is encountered
            } else {
                max.push_back(c);  // Push count of consecutive ones
                c = 0;  // Reset count when 0 is encountered
            }
        }
        
        // Push the last count if it ends with consecutive 1's
        max.push_back(c);

        // Find the maximum count of consecutive ones
        auto max_elem = max_element(max.begin(), max.end());
        return *max_elem;  // Return the maximum value
    }
};