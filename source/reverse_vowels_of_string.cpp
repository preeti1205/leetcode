/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n -1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if(i < j)swap(s[i++], s[j--]);
        }

        /*
        vector<int> vow;
        set<char> vowels = {'a','e', 'i', 'o', 'u', 'A','E', 'I', 'O', 'U'};
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                vow.push_back(i);
            }
        }
        int len = vow.size();
        for(int i = 0; i < len/2; i++) {
            swap( s[vow[i]], s[vow[len - i - 1]]);
        }
        */
        return s;
    }
};
