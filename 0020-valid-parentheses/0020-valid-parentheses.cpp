class Solution {
public:
    bool isMatch(char c1, char c2) {
        if((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') ) {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s) {
            // jb tk open hai jb tk push kro 
            if(i == '(' || i == '{' || i == '[') {
                st.push(i);
            } else {
                if(st.empty()) {
                    return false;
                }
                char curr = st.top();
                st.pop();
                bool ans = isMatch(curr,i);
                if(!ans) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};