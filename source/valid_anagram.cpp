/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        //best answer - 12ms
        //the answer below this one uses the same concept in hashmap but is slower(array is always faster)
        int counts[26]{0};
        for(int i = 0; i < s.length(); ++i) counts[s[i]-'a']++;
        for(int i = 0; i < t.length(); ++i) counts[t[i]-'a']--;
        for(int i = 0; i < 26; ++i) if(counts[i]) return false;
        return true;
    }
};

/*
class OtherSolution {
public:
    bool isAnagram(string s, string t) {

        //hashmap solution - 40 ms
        /*
        unordered_map<int,int> counter;
        unordered_map<int,int>::iterator it;
        for(char ch: s)counter[ch-'a']++;
        for(char ch: t)counter[ch-'a']--;
        for(it= counter.begin(); it != counter.end(); it++) if(it->second != 0)return false;
        return true;
        */

        /*
        //most basic sorting solution
        if(int(s.size()) != int(t.size()))
        {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t)
            return true;
        else
            return false;
        */

        //a super cool solution - 16ms
        /*return euler_prime(s)==euler_prime(t);


    }
//a super cool solution
long euler_prime( string str)
        {
            long result = 1;
            for(char ch: str)
            {
                int n = ch -'a';
                result = result*(n*n + n +41)%INT_MAX;
            }

            return result;
        }
};
*/
