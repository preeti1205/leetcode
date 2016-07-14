/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result{0};
        int start_range= 0 ;

        //O(n) Solution
        for (int i= 1 ; i <= num; i++)
        {
            if ( (i&(i-1)) == 0)
            {
                result.push_back(1);
                start_range = i;
            }
            else
            {
                result.push_back(1 + result[i-start_range]);
            }


            //O(sum of all the ones in all the numbers) complexity
            /*

            int count = 0;
            int k = i;

            while(k != 0)
            {
                int temp=k&(~(k-1)) ;
                if (temp) count++;
                k = temp^k;
            }
            */

            // O(n*size of digit) complexity
            /*
            while(k != 0)
            {
              if (k&1) count++ ;
              k = k>>1;
            }

            result.push_back(count);

            */
        }

        return result;

    }
};
