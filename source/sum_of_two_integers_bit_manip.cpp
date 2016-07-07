/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
*/

class Solution {
public:
    int getSum(int a, int b) {

            //uses half added logic
            if (b==0)
            {
                return a;
            }
            int sum = a^b;
            int carry=a&b;
            return getSum(sum,carry<<1);

    }
};
