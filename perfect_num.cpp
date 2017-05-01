/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.

Example:

Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14

Note: The input number n will not exceed 100,000,000. (1e8) 
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0) return false;
       int sum = 0;
       int lastPossibleDivisor =  sqrt(num);
       for(int i = 1; i <= lastPossibleDivisor; ++i) {
           if (num % i == 0 && i*i != num)
            sum += i + (num/i);
            if (num % i == 0 && i*i == num)  // this is if the number is a perfect sqr, you won't want to miss out the sqrt. Think 4 in 16
                sum += i;
           //cout << i << " " << num/i << endl ;
       } 
       //cout << sum;
       return (sum - num) == num;
    }
};