class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        while(n >0 && s.find(part) < s.length() ){
            s.erase(s.find(part) , part.length());
        }
        return s;
    }
};