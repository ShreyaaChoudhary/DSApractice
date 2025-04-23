class Solution {
public:
    // Helper function to get the sum of digits
    int countdigits(int i) {
        int sum = 0;
        while(i != 0) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        map<int, int> mp;

        // Group numbers by the sum of their digits
        for (int i = 1; i <= n; i++) {
            mp[countdigits(i)]++;
        }

        int maxi = 0, count = 0;

        // Find the maximum group size
        for (auto s : mp) {
            if (s.second > maxi) {
                maxi = s.second;
            }
        }

        // Count how many groups have the maximum size
        for (auto s : mp) {
            if (s.second == maxi) {
                count++;
            }
        }

        return count;
    }
};
