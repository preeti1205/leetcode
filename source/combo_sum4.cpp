/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/
class Solution {
public:
    int ways(int sum, vector<int>& nums, unordered_map<int, int> &cache) {
        if(cache.find(sum) != cache.end()) return cache[sum];
        //if (sum < 0) return 0;
        if (sum == 0) {
            return 1;
        }
        int counter = 0;
        for(int i = 0; i < int(nums.size()); i++) {
            int diff = sum - nums[i];
            if (diff >= 0) counter += ways(diff, nums, cache);
        }
        cache[sum] = counter;
        return counter;
    }
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        return ways(target, nums, cache);
    }
};
