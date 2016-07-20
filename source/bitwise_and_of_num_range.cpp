/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {

        while(n>m)
        {
          n = n&(n-1);
        }

        return n ;
    }

        //run time - 72ms when paired with above answer
        /*
        if (( (1<<(highest_log(n))) & m) == 0)
        {
            return 0;
        }
        */

        /* run time - 100ms when paired with 1500 ms answer

        if (highest_log(m) != highest_log(n))
        {
            return 0;
        }
        */

        //really long runtime - 1500 ms
        /*
        int result=0;

        for(int i = 0; i < 31 ; i++)
        {
            int curr = (m>>i);

            for(int j = m+1; (j <= n) && (j > 0) && ((j>>i) >0);j++)
            {
                curr = curr & ((j>>i)&1);
                if (curr == 0)
                {
                    //cout<<i<<":"<<j<<endl;
                    break;
                }
            }
            result |= (curr<<i);
        }

        return result;


    }


private:
    int highest_log(int a)
    {
        vector<unsigned int> shifter = {0x2, 0xc, 0xf0 , 0xff00, 0xffff0000};
        vector<unsigned int> amount = {1,2,4,8,16};
         int r =0;

        for(int i = 4; i >=0 ; i--)
        {
            if(a & shifter[i])
            {
                a >>= amount[i];
                r |= amount[i];
            }
        }

        return r;
    }
    */
};
