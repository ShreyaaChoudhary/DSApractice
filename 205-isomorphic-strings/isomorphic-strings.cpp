class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> sp;
        unordered_map<char,int> tp;
        for(int i = 0 ; i<s.length(); i++){
            if(sp.find(s[i])==sp.end()){
                sp[s[i]] = i;
            }
            if(tp.find(t[i])==tp.end()){
                tp[t[i]] = i;
            }
            if(sp[s[i]]!=tp[t[i]]){
                return false;
            }
        }
        return true;
    }
};