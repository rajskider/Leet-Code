class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; 
    }
    string sortVowels(string s) {
        string vowel = "";
        for(char c : s){
            if(isVowel(c))
                vowel += c;
        }
        sort(vowel.begin(), vowel.end());
        int j = 0;
        for(char &c : s){
            if(isVowel(c))
                c = vowel[j++];
        }
        return s;
    }
};