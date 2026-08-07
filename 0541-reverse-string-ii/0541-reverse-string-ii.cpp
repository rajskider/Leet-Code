class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k){
            reverse(s.begin() + i, s.begin() + i + min(k, (int)s.size() - i));
        }
        return s;
    }
};