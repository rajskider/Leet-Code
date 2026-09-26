class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                string temp;
                i++;
                while(s[i] != ')')
                    temp.push_back(s[i++]);
                if(mp.find(temp) != mp.end())
                    ans += mp[temp];
                else ans += "?";
            }
            if(s[i] != ')') ans += s[i];
        }
        return ans;
    }
};