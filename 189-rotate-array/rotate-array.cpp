class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;  // Handle cases where k >= size
        if (k == 0) return;

        // Corrected the size of the temporary vector to hold 'k' elements
        vector<int> temp(k);
        
        // Copy the last 'k' elements into the temporary vector
        for (int i = 0; i < k; i++) {
            temp[i] = nums[size - k + i];
        }

        // Shift the remaining elements to the right
        for (int i = size - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Place the elements from the temporary vector at the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }

        // Optional: Uncomment this to print the rotated array (for debugging)
        // for (auto &v : nums) {
        //     cout << v << " ";
        // }
    }
};
