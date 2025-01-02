class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long total = 0 ;
        int l = 0; //left pointer of sliding window
        int res = 1;//result maximum frequency
        for(int r = 1;r<nums.size();++r)
{
    total +=(long)(nums[r]-nums[r-1])*(r-l);
    while(total>k){
        total -= nums[r]-nums[l];
        ++l;
    }
    res = max(res,r-l+1);
}
return res;   
}
};
