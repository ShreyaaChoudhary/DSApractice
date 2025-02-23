class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> pos, ans;
        int len = boxes.size();
        for(int i = 0 ; i< len ; i++){
            if(boxes[i]=='1'){
                pos.push_back(i);
            }
        }
        for(int i = 0 ; i< len ; i++){
            int sum = 0 ;
            for(int index : pos){
                int distance = abs(i-index);
                sum+=distance;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};