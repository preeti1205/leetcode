/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

double findMedian(vector<int> &a, vector<int> &b, int size, int low, int high) {
    //cout<<low<<" "<<high<<endl;
    if (low > high)
        return INT_MIN;
    int arr_size = a.size() - 1;// last index
    int arr2_size = b.size();
    int k = (low + high)/2;

    if (k <= arr_size && (b[size - k - 1] <= a[k] && a[k] <= b[size - k] ))
    {
        //cout<<b[size - k - 1]<<" "<<a[k]<<" "<<b[size - k]<<" "<<k<<endl;
        if ( (arr_size + arr2_size + 1) % 2 == 0) {
            double med_2 = max(a[k-1], b[size - k - 1]);
            //cout<<med_2<<a[k]<<endl;
            return (med_2 + a[k])/2;
        }
        else return a[k];
    }
    else if ( a[k] > b[size - k - 1] && (size - k - 1 < arr2_size) ) return findMedian(a, b, size, low, k-1);  //if median is smaller than k
    else return findMedian(a, b, size, k + 1, high);
}
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        double result = findMedian(nums1, nums2, (m+n)/2, 0, m-1);
        if (result == INT_MIN) result = findMedian(nums2, nums1, (m+n)/2, 0, n-1);

        return result;
    }
};
