/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

//best solutions - coz array is faster than hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n= s.size();
        int max_count = 0, i = 0, j = 0;
        int cache[256];
        std::fill_n ( cache, 256, -1 );   //don't make default value 0.
        //It messes up with index 0 and rep at index 0 will never be picked
        // -- also note the default for filling an array with def value. Using {-1} will set first value to -1 and rest to 0. 

        for(int i = 0, j = 0; j < n; j++) {
            int asci = int(s[j]);
            if( cache[asci] != -1) {
                i = max(i, cache[asci] + 1);
            }
            cache[asci] = j;
            max_count = max(max_count, j - i + 1);
        }
        return max_count;
    }
};

//editorial solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n= s.size();
        int max_count = 0, i = 0, j = 0;
        unordered_map<char,int> table;

        for(int i = 0, j = 0; j < n; j++) {
            if(table.find(s[j]) != table.end()) {
                i = max(i, table[s[j]] + 1);
            }
            table[s[j]] = j;
            max_count = max(max_count, j - i + 1);
            //cout<<j<<" "<<i<<" "<<max_count<<endl;
        }
        return max_count;
    }
};

//*************O(n) but fails for a test case when max is at the end eg: tmmzuxt
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n= s.size();
        int max_count = 0, i = 0, j = 0;
        unordered_map<char,int> table;
        string longest_str ;
        while(j < n) {
            while(table.count(s[j]) == 0 && j < n) {
                table[s[j]] = j;
                j++;
            }
            max_count = max(max_count, j - i );
            if(j < n) {
                i = table[s[j]] + 1;
                table[s[j]] = j;
                j++;
            }
        }
        return max_count;
    }
};

//o(n^2)
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
