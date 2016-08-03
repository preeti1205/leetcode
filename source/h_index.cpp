/*
Given an array of citations (each citation is a non-negative integer) of a researcher,
 write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia:
 "A scientist has index h if h of his/her N papers have at least h citations each,
 and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total
 and each of them had received 3, 0, 6, 1, 5 citations respectively.
 Since the researcher has 3 papers with at least 3 citations each
 and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

class Solution {
public:
    //O(n) time but O(n) space - 4ms
    int hIndex(vector<int>& citations) {
        int max = citations.size();
        int papers[max+1]={0};
        for(int i =0; i <max; i++)
        {
            int num = citations[i];
            if(num >=max) papers[max]++;
            else papers[num]++ ;
        }

        for(int i=max; i> 0; i--)
        {
            if(papers[i] >= i) return i; // definition: at least n papers with n or more citations
            papers[i-1] += papers[i];
        }
        return 0;

    }
};

//O(nlogn) solution but O(1) space - 4ms
/*
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //sort(citations.begin(), citations.end(), greater<int>());
        sort(citations.begin(), citations.end());
        int max = citations.size();
        //for(int i=0; i < max; i++)
        for(int i = max-1; i >=0; i--)
        {
            //if (citations[i] < (i+1)) return i;
            if(citations[i]< max -i) return (max -i-1);
        }
        return max;
    }
};
*/
