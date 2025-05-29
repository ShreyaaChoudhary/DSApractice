class Solution {
public:
    string removeOuterParentheses(string s) {
        //depth counter method
        // int count = 0;
        // string res = "";
        // int i = 0;
        // while(i<s.size()){
        //     if(s[i]=='('){
        //         if(count>0){
        //             res+=s[i];
        //         }
        //         count++;
        //     }
        //     else{
        //         count--;
        //         if(count>0){
        //             res+=s[i];
        //         }
        //     }
        //     i++;
        // }
        // return res;

        //using stack
        stack<char> st;
        if(s.empty()) return "";
        string res = "";
        for(int i = 0; i< s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
                continue; //skips all other iterations
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