#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character to the window
            freq[s[right]]++;

            // Shrink the window until it becomes valid
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            // Update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};