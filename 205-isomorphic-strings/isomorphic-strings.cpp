class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false; // Strings must be the same length
        
        unordered_map<char, char> s_to_t, t_to_s; // Two maps to track character mappings
        
        for (int i = 0; i < s.size(); i++) {
            char sc = s[i], tc = t[i];
            
            if (s_to_t.count(sc) && s_to_t[sc] != tc) return false; // Conflict in s → t mapping
            if (t_to_s.count(tc) && t_to_s[tc] != sc) return false; // Conflict in t → s mapping
            
            s_to_t[sc] = tc; // Map s[i] → t[i]
            t_to_s[tc] = sc; // Map t[i] → s[i]
        }
        
        return true; // If no conflicts, the strings are isomorphic
    }
};
