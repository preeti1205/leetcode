/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer,
replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

*/

class Solution {
public:
    int result(int a)
    {
        int sum = 0;
        while(a)
            {
                int digit = a%10;
                sum +=digit*digit;
                a = a/10;
            }
        return sum;

    }
    //Floyd's Cycle Detection Algo - fastest
public:
    bool isHappy(int n) {
        int slow = result(n);
        int fast = result(result(n));

        while(slow != fast)
        {
            slow = result(slow);
            fast = result(result(fast));
        }

        return fast ==1;
    }
};
/*
bool isHappy(int n) {
        unordered_set<int> happy;

        while(n != 1 && (happy.find(n)==happy.end()))
        {   happy.insert(n);
            int sum = 0;
            while(n)
            {
                int digit = n%10;
                sum +=digit*digit;
                n = n/10;
            }
            n = sum;
        }

       return n==1;
    }
};
*/
