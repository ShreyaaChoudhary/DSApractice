class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //one way
        // set<int> mp;
        // for(int i= 0 ; i<nums.size(); i++){
        //     mp.insert(nums[i]);
        // }
        // for(int i = 0 ; i <=nums.size(); i++){
        //     if(mp.find(i)==mp.end())
        //     return i;
        // }
        // return 0;
        //second way
        // int n= nums.size();
        // int sum = (n*(n+1))/2;
        // int nosum = 0 ;
        // for(int i= 0; i<nums.size(); i++){
        //     nosum+=nums[i];
        // }
        // return sum-nosum;
        //third way 
        int n= nums.size();
        int temp = 0;
        for(int i = 0  ; i<=n; i++){
            temp^=i;
        }
        for(int i = 0 ; i<n ; i++){
            temp^=nums[i];
        }
        return temp;
    }
};