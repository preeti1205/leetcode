/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        int size = intervals.size();
        return merge_sort(intervals, result,0, size);

    }
    vector<Interval> merge_sort(vector<Interval> intervals)
    {
        int n = intervals.size();
        if (n == 1)
        {
            return {};
        }
        int mid = n/2;
        vector<Interval> left, right;
        for(int i = 0 ; i <= mid; i++)
        {
            left.push_back(intervals[i]);
        }
        for(int i = mid+1 ; i < n; i++)
        {
            right.push_back(intervals[i]);
        }

        left = merge_sort(left);
        right = merge_sort(right);
        return merger(left , right);

    }
    vector<Interval> merger(vector<Interval> l, vector<Interval> r)
    {   vector<Interval> res;
        int i = 0; j = 0;
        while(i < int(l.size()) && j < int(r.size()) )
        {
            (l[i].first < r[i].first ) ? res.push_back(l[i++]) : res.push_back(r[j++]) ;
        }
        while (i < int(l.size())) res.push_back(l[i++]);
        while (j < int(r.size())) res.push_back(r[j++]);
        return res;
    }
};
