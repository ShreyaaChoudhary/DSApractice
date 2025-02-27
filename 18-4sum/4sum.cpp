class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i< n; i++){
            //repeated
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j< n; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                //2 fixed 2 moving pointers 
                int p = j+1;
                int q = n-1;
                while(p<q){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[p]+nums[q];
                    if(sum==target){
                        vector<int> temp = {nums[i], nums[j], nums[p], nums[q]};
                        ans.push_back(temp);
                        p++;
                        q--;
                        //repeated
                        while(p<q && nums[p]==nums[p-1]) p++;
                        while(p<q && nums[q]==nums[q+1]) q--;

                    }
                    else if(sum<target){
                        p++;
                    }
                    else{
                        q--;
                    }
                }
            }
        } return ans;
    }
};