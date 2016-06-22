/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int num_size = digits.size();

        //using logic of basic arithematic i was taught in childhood -carry
        bool carry = true;

        /*An additional condition, which has not been included in the test cases

        if (num_size == 0)
        {
            digits.push_back(1);
            return digits;
        }*/

        for(int i=num_size-1 ; i >=0; i--)
        {
            digits[i] = (carry == true ? (digits[i] +1) : digits[i]);
            carry = (digits[i]== 10? true: false);

            if (carry == false)
            {
                // I realized later that returning directly is much better idea than using break
                //break;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }

        // no need to test the condition (realized later) when i am returning digits at any point inside the loop
        //if (digits[0] == 0 && carry== true)
        //{
            vector<int> new_digits(num_size+1, 0);
            new_digits[0] = 1;
            return new_digits;
        //}

        //return digits;
    }
};
