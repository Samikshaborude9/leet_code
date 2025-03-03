class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome (single character center)
            expandAroundCenter(s, i, i, start, maxLen);
            // Even-length palindrome (two-character center)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }
        
        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        int len = right - left - 1; // Length of palindrome
        
        if (len > maxLen) {
            maxLen = len;
            start = left + 1; // New start index
        }
    }
};