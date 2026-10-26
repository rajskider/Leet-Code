class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0; i < k; i++){
            if(isvowel(s[i])) count++;
        }
        int maxcount = count;
        for(int i = k; i < s.length(); i++){
            if(isvowel(s[i - k])) count--;
            if(isvowel(s[i])) count++;
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};