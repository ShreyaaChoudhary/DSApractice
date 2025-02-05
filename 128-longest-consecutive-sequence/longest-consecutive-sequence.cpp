class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        int maxi = 1;
        if(n==0)
        return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(int num : st){
            if(st.find(num-1)==st.end()){
                int i = num;
                int c = 1;
                while(st.find(i+1)!=st.end()){
                    c=c+1;
                    i=i+1;
                }
                maxi = max(maxi,c);
            }
        }
        return maxi;
    }
};