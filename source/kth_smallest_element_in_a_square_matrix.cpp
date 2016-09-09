/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order,
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
//55 ms
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        if (k > n*n) return 0;
        int l = matrix[0][0];
        int r= matrix[n-1][n-1];

        while(l < r){
            int mid = (l+r)/2;
            int count = 0;
            for(int i =0; i < n; i++){
                vector<int> row =matrix[i];
                count += upper_bound(row.begin(), row.end(), mid) - row.begin();
            }
            if (count < k) l =mid +1;
            else r= mid;
        }

        return l;
    }
};
// lamest solution - 100 ms
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int size = row*col;
        if (k > size) return 0;
        vector<int> res;

        for(int i =0; i < size; i++)
        {
            int r = i/col;
            int c = i%col;
            res.push_back(matrix[r][c]);
        }

        sort(res.begin(), res.end());
        return res[k-1];
    }
};
*/
