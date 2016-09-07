class Solution {
public:
void wiggleSort(vector<int>& nums) {
    int n = nums.size();

    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}
};
//116 ms solution - non linear for sort - O(nlogn) solution
/*
[6 5 5 4] -> [6 5] [4 3] -> [4 6 3 5]
[6 5  5 4 3] -> [6 5] [5] [4 3] -> [5 6 4 5 3]   -> [4 6 3 5 5]
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
