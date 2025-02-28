class Solution {
public:
    string removeOuterParentheses(string s) {

        string result ;
        int count =0;
        int n = s.length();
        for( int i=0 ; i<n;i++){
            char c= s[i];
            if(c=='('){
                if(count > 0){
                    result += c;
                }
                count++;
            }else{
                count --;
                if(count > 0){
                    result += c;
                }
            }
        }
        return result;
    }
};