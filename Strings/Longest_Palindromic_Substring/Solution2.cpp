class Solution {
public:
    string longestPalindrome(string s) {
        int mlen{1};
        int start{};

        if (s.empty()) {
            return "";
        }

        auto expand = [&](int left, int right) {
            while (left >= 0 &&
                   right < s.size() &&
                   s[left] == s[right]) {

                int currlen = right - left + 1;

                if (currlen > mlen) {
                    mlen = currlen;
                    start = left;
                }

                left--;
                right++;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);       // Odd-length palindrome
            expand(i, i + 1);   // Even-length palindrome
        }

        return s.substr(start, mlen);
    }
};