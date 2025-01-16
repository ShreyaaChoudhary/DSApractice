class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {

    vector<int> max;
    int count = 0 ;
    for(int i= 0 ; i<nums.size(); i++){
        if(nums[i]==1){
            count++;
        }
        else{
            max.push_back(count);
            count=0;
        }
    }
    max.push_back(count);
    auto ans = max_element(max.begin(),max.end());
    return *ans;

    }









    //      vector<int> max;
    //     int c = 0;
        
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 1) {
    //             c++;  
    //         } else {
    //             max.push_back(c);  
    //             c = 0;  
    //         }
    //     }
        
    //     max.push_back(c);

    //     auto max_elem = max_element(max.begin(), max.end());
    //     return *max_elem;  
    // }
};