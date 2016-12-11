/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n= s.size();
        int max_count = 0, i = 0;

        while (i < n) {
           unordered_map<char,int> table;
           int count = 0;
           int j = i;
           while(table.count(s[j]) == 0 && j < n) {    // \x00 is at the end of the string.
             //So remember to use j < n. Remove it to see what happens
               table[s[j]] = 1;
               count++;
               //cout<<s[j]<<" "<<count<<endl;
               j++ ;
           }
           max_count = max(max_count, count);
           i++ ;
        }
        return max_count;
    }
};
