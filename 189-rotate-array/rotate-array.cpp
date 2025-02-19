class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(k);
        int n = nums.size();
        k = k % n;
        // if(k==0)
        // return;
        for(int i = 0 ; i < k ; i++){
            temp[i] = nums[n-k+i];
        }
        //this is overwriting
        // for(int i = k ; i < n ; i++){
        //     nums[i] = nums[i-k];
        // }
        for(int i = n-k-1; i>=0; i--){
            nums[i+k] = nums[i];
        }
        for(int i  = 0 ; i < k; i++){
            nums[i]=temp[i];
        }
    }
};