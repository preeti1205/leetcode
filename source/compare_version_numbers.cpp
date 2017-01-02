/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        istringstream s1(version1), s2(version2);

        while(1) {
            string a, b;
            int n1, n2;
            if ( !getline(s1, a, '.')) n1=0;  //stringstream pointer is updated everytime it is used as in, in this loop
            else n1 = stoi(a);
            if( !getline(s2, b, '.')) n2 = 0;
            else n2 = stoi(b);

            if( !s1 && !s2) return 0;
            if (n1 > n2) return 1;
            if(n1 < n2) return -1;
        }

        return 0;

    }
};

/*****************************************************************************/
class Solution {
public:
    string stripZeros(string s) {
        int i = s.find_first_not_of('0');
        if(i == -1) return "0";
        else return s.substr(i, s.size() - i);
    }
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int i = 0, j = 0;
        while(i < m || j < n) {
            string s1, s2;
            while(i < m && version1[i] != '.')  s1 +=version1[i++] ;
            while(j < n && version2[j] != '.')  s2 +=version2[j++] ;
            i++;
            j++;
            s1 = stripZeros(s1);
            s2 = stripZeros(s2);
            if(stoi(s1) == stoi(s2)) continue;
            else if(stoi(s1) > stoi(s2)) return 1;
            else return -1;
        }

        return 0;

    }
};
