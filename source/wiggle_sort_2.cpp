class Solution {
public:
    void wiggleSort(vector<int>& nums) {

    }
};
// The following algo works beautifully if we don't have consecutive repeating numbers.
// In case like this        [1,2,2,1,2,1,1,1,1,2,2,2]
//we will get               [1,2,1,2,1,2,1,1,1,2,2,2]
//What we really want is    [1,2,1,2,1,2,1,2,1,2,1,2]
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool flag = true;
        int size = nums.size();
        for(int i=1; i < size; i++)
        {
            if ((flag && nums[i] <nums[i-1]) ||  (!flag && nums[i] >nums[i-1]))
                swap(nums[i], nums[i-1]);
            flag = !flag ;
        }
    }
};
