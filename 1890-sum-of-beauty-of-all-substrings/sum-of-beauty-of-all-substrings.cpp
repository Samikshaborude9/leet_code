class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int totalBeauty = 0;
        
        // Iterate over all substrings
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); // Frequency array for characters
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; // Update frequency for current character
                
                int minFreq = INT_MAX, maxFreq = INT_MIN;
                
                // Find min and max frequencies (ignoring 0s)
                for (int f : freq) {
                    if (f > 0) { 
                        minFreq = min(minFreq, f);
                        maxFreq = max(maxFreq, f);
                    }
                }
                
                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;

    }
};