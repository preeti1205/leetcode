/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.
*/

class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int segment = 0;
        for(int i = 0; i < n; i++){
            segment += (s[i] != ' '  && ( s[i + 1] == ' ' || i + 1 == n) );
        }


        /*
        if(n == 0) return 0;

        int i = s.find_first_not_of(' ');
        if(i == -1) return 0;
        int segment = 0;

        while(i < n && s[i]) {
            if(s[i] != ' ' ) segment++;
            while(i < n && s[i] != ' ')i++;
            while(i < n && s[i] == ' ')i++;
        }
        */
        return segment;
    }
};
