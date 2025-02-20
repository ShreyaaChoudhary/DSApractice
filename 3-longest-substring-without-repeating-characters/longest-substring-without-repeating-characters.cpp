class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> sp;
        int l = 0;
        int maxlen = 0 ;
        for(int r= 0 ; r<s.length(); r++){
            if(sp.count(s[r])==0){
                //doesnt exist
                sp.insert(s[r]);
                maxlen = max(maxlen,r-l+1);
            }
            else{
                while(sp.count(s[r])){
                    sp.erase(s[l]);
                    l++;
                }
                sp.insert(s[r]);
                //exists
            }
        }
        return maxlen;
    }
        
    
};