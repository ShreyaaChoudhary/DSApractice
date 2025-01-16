class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
    //     int sum = (n*(n+1))/2;
    //     int numsum =0;
    //     for(int i =  0 ; i<nums.size();i++){
    //         numsum+=nums[i];
    //     }
    //     return (sum-numsum);
        
    // }
    int temp=0;
    for(int i = 1; i<=n;i++){
        temp^=i;
    }
    for(int i = 0; i<n;i++){
        temp^=nums[i];
    }
    return temp;
}};