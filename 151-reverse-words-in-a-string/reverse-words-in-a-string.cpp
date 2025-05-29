class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while(iss>>word){
            words.push_back(word);
        }
        string res = "";
        reverse(words.begin(), words.end());
        for(int i= 0 ; i<words.size(); i++){
            res+=words[i];
            if(i<words.size()-1){
                res+=" ";
            }
        }
        return res;
    }
};