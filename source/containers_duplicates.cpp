/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array,
 and it should return false if every element is distinct.
 */
 class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      //36ms
    int size = nums.size();
        if(size>1){
            sort(nums.begin(), nums.end());
            for(int i=0; i<size; ++i)
                if(nums[i] == nums[i+1] && i+1 != size)
                    return true;
        }
        return false;
}
};

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    //48ms
    unordered_set<int> result ;
    for (int i = 0; i < nums.size(); i++){
        result.insert(nums[i]);
        if (result.size() != i+1){
            return true;
        }
    }
    return false;
    //

    //54ms
    set<int> result(nums.begin(), nums.end());
    return ( int(result.size()) < int(nums.size()));
    //

    //54ms
        unordered_map<int,int> hash;
        for(int i:nums)
        {
            hash[i]++;
            if (hash[i] > 1)
                return true;
        }
        return false;
    //

    //60ms
    set<int> result ;
    for (int i = 0; i < nums.size(); i++){
        result.insert(nums[i]);
        if (result.size() != i+1){
            return true;
        }
    }
    return false;
    //
    }
};
*/
