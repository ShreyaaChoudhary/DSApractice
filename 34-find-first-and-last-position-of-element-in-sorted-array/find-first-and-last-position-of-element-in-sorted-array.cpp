class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // int s = -1;
        // int e = -1;
        // int n = nums.size();
        // for(int i= 0 ; i< n; i++){
        //     if(nums[i]==target){
        //         s= i;
        //         break;
        //     }
        // }
        // for(int i= n-1 ; i >=0; i--){
        //     if(nums[i]==target){
        //         e= i;
        //         break;
        //     }
        // }
        // return {s,e};
        
        //using binary search 
        int left = 0, right = nums.size() - 1;
        int first = -1, last = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                last = mid;
                while (first > 0 && nums[first - 1] == target) {
                    first--;
                }
                while (last < nums.size() - 1 && nums[last + 1] == target) {
                    last++;
                }
                break;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return {first, last};
    }
};