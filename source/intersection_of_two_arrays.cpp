/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

   Each element in the result must be unique.
   The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {


        vector<int> result;
        unordered_map<int,int> hash;

        if(nums1.size() == 0 || nums2.size() == 0) return result;

        for(int i = 0; i < int(nums1.size()); i++)
        {
            if(hash.find(nums1[i]) == hash.end())
            {
                hash.insert(make_pair(nums1[i],1));
            }
        }

        for(int i = 0; i< int(nums2.size()); i++)
        {
            if(hash.find(nums2[i]) != hash.end())
            {
                if(hash[nums2[i]] != 0)
                {
                    result.push_back(nums2[i]);
                    hash[nums2[i]] = 0;
                }
            }
        }


        return result;

    }
};
