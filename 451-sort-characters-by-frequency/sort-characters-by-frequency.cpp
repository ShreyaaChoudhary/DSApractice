class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string res="";
        while(!pq.empty()){
            char c = pq.top().second;
            int f = pq.top().first;
            pq.pop();
            res+=string(f,c);
        }
        return res;
    }
};