class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int n = nums.size();
    if (n == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = 1;
        for(int num : st){
            if(st.find(num-1)==st.end()){
                int i = num ; 
                int cnt = 1;
                while(st.find(i+1)!=st.end()){
                    i=i+1;
                    cnt=cnt+1;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};