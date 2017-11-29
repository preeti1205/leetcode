/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        int num = x ^ y;
        while(num) {
            ++distance;
            num &= num - 1;
        }
        return distance;
    }
    /*
    int hammingDistance(int x, int y) {
        int distance = 0;
        while(x || y) {
            distance += 1 & (x ^ y);
            x >>= 1;
            y >>= 1;
        }
        return distance;
    }
    */
};