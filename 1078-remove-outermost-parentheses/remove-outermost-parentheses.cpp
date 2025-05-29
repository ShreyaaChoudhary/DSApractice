class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string res = "";
        int i = 0;
        while(i<s.size()){
            if(s[i]=='('){
                if(count>0){
                    res+=s[i];
                }
                count++;
            }
            else{
                count--;
                if(count>0){
                    res+=s[i];
                }
            }
            i++;
        }
        return res;
    }
};