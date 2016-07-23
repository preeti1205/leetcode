/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

   You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
   Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

I am Using heap
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<pair<int,int>> table;
        unordered_map<int,int> hash;
        for(auto &x:nums) hash[x]++;

        for(auto &x:hash)
        {
            table.push_back(make_pair(x.second, x.first));
        }
        make_heap(table.begin(), table.end());

        for(int i = 0; i < k; i++)
        {
            result.push_back(table[0].second);
            pop_heap(table.begin(),table.end());
            table.pop_back();
        }

        return result;
    }
};
