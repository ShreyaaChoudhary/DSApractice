class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res="";
        if(s.empty()) return "";
        for(int i=0 ; i<s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
                continue; //skips all iterations
            }
            if(s[i]=='('){
                st.push('(');
            }
            if(s[i]==')'){
                st.pop();
            }
            if(!st.empty()){
                res+=s[i];
            }
        }
    return res;
    }
};