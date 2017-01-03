/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    string stripExtra(string str) {
        int n = str.size();
        int i = 0;
        string result;
        while(i < n) {
            if (isalnum(str[i])) result += tolower(str[i]);
            i++;
        }
        return result;
    }
    bool isPalindrome(string s) {
        string input = stripExtra(s);
        int n = input.size();
        for(int i = 0; i < n/2 ; i++) {
            if(input[i] != input[n - 1 - i]) return false;
        }
        return true;
    }
};
