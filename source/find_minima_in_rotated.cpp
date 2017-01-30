/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question
*/

class Solution {
public:
    int finder(int start, int end, vector<int> &nums) {
        while(start < end) {
            int mid = (start + end )/2;
            if (nums[start] < nums[end]) return nums[start];
            if (nums[start] > nums[mid]) end = mid;
            else start = mid + 1;
        }
        return nums[start];
    }
    int findMin(vector<int>& nums) {
        return finder(0,nums.size() - 1, nums);
    }
};
