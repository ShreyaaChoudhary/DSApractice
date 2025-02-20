class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0 ;
        int r = n-1;
        int maxarea = 0 ;
        while(l<r){
            int heightt = min(height[l],height[r]);
            int width = r-l;
            maxarea = max(maxarea, heightt*width);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};