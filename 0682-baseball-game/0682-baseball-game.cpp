class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1 + num2);
            }
            else if(operations[i] == "D") 
                st.push(2 * st.top());
            else if(operations[i] == "C") 
                st.pop();
            else 
                st.push(stoi(operations[i]));
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};