//116 ms solution - non linear for sort - O(nlogn) solution
/*
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return;
        vector<int> res(size, 0);
        sort(nums.begin(), nums.end());
        int small = 0;
        int big = (size-1)/2 +1;
        int i = size -1;
        if (size%2 == 0) res[i--]= nums[big++];
        while(i > -1){
            res[i--]  = nums[small++];
            if (i > -1)
                res[i--] = nums[big++];
        }
        nums = res;

    }
};

// The following algo works beautifully if we don't have consecutive repeating numbers.
// In case like this        [1,2,2,1,2,1,1,1,1,2,2,2]  ( [4,5,5,6] is also a good test case)
// we will get              [1,2,1,2,1,2,1,1,1,2,2,2]
// What we really want is   [1,2,1,2,1,2,1,2,1,2,1,2]

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
*/
