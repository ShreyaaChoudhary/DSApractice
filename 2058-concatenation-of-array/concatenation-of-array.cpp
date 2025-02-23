class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> nums2(nums);
        nums2.insert(nums2.end(), nums.begin(), nums.end());  // Append nums again
        return nums2;
    }
};