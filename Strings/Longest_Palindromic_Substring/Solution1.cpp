/*
LeetCode 5 - Longest Palindromic Substring (s1)

Approach:
1. Generate every possible substring using two nested loops.
2. For each substring, check if it is a palindrome using a lambda function.
3. Track the longest palindrome found.

Time Complexity: O(n^3)
- O(n^2) substrings
- O(n) palindrome check for each substring

Space Complexity: O(1)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        // Lambda function to check if s[left...right] is a palindrome
        auto isPalindrome = [&s](int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };

        int maxLength = 1;
        int start = 0;

        // Generate all substrings
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {

                // Check if the current substring is a palindrome
                if (isPalindrome(i, j)) {
                    int currentLength = j - i + 1;

                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};