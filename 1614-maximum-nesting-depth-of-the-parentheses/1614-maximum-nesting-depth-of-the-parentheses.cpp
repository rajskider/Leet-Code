class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mx = 0, count = 0;
        for(char c : s){
            if(c == '('){
                st.push(c);
                count++;
            }
            else if(c == ')'){
                mx = max(count, mx);
                count--;
                st.pop();
            }
        }
        return mx;
    }
};