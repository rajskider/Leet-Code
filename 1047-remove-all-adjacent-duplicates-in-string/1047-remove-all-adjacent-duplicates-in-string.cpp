class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> temp;
        string ans;
        for(int i = 0; i < s.length(); i++){
            if(!temp.empty() && temp.top() == s[i]) temp.pop();
            else temp.push(s[i]);
        }
        while(!temp.empty()){
            ans.push_back(temp.top());
            temp.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};