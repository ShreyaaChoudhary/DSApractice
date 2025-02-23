//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        int n = arr.size();
        int start  = 0;
        int end = n-1;
        int ans = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]<=k){
                ans = mid;
                start= mid+1;
            }
            else{
                end =mid-1;
            }
        }
        return ans;
        // Your code here
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
