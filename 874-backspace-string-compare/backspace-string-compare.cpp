class Solution {
public:
    string processString(string str){
        stack<char> st;
        for (int i=0;i<str.size(); i++){
            if (str[i] == '#'){
                if (!st.empty()) {
                    st.pop();
                }

            }
            else{
                st.push(str[i]);
            }

        }
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;

    }
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);

    }
};