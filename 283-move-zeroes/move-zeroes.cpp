class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int nonZeroIndex = 0; // Pointer for the next non-zero position

        // Move all non-zero elements to the front
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex] = nums[i];
                nonZeroIndex++;
            }
        }

        // Fill the remaining positions with zeros
        for (int i = nonZeroIndex; i < size; i++) {
            nums[i] = 0;
        }
    }
};
