class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        //base case
        if(st.find(endWord)==st.end()){
            return 0;
        }
        queue<pair<string,int>> q; //current word, current level
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            for(int i = 0 ; i<word.size() ; i++){
                string temp = word;
                for(char ch = 'a' ; ch<='z' ; ch++){
                    temp[i] = ch; //replacing every letter with every character
                    if(temp==endWord) return level+1;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp, level+1});
                    }
                }
            }
        }
        return 0;
    }
};