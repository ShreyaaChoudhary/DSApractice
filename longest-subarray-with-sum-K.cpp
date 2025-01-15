class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int> mp;
        int sum =0 , len = 0 ; 
        for(int i = 0 ; i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                len = max(len, i+1);
            }
            if(mp.find(sum)==mp.end()){
            mp[sum]=i;
            }
            int rem = sum - k;
            if(mp.find(rem)!=mp.end()){
                int temp = i-mp[rem];
                len = max(len,temp);
            }
        }
        return len;
    }
};
