class Solution {
public:
    bool isPalindrome(string s) {
        string newstr;
        for(char c: s){
            if(isalnum(c)){
                newstr += tolower(c);
            }
        }
        int st = 0 ;
        int e = newstr.length()-1;
        while(st<=e){
            if(newstr[st]!=newstr[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
};