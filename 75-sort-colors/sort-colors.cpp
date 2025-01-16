class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algorithm --optimal
        //0 - low-1 -> 0
        //low - mid-1 ->1
        //mid - high-1 -> random nos
        //high - n-1 -> 2
        int n = nums.size();
        int mid = 0, low = 0 , high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};