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
        if (size < 2) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return (a.start < b.start);});
        /*
        result.push_back(intervals[0]);
        for (int i = 1; i < size; i++)
        {
            if (result.back().end < intervals[i].start) result.push_back(intervals[i]);
            else
                result.back().end = max(result.back().end, intervals[i].end);
        }
        */
        for(int i =1; i<size; i++)
        {
            if ( intervals[i-1].end >= intervals[i].start)
            {
                intervals[i].start = intervals[i-1].start;
                intervals[i].end = max(intervals[i].end, intervals[i-1].end);
            }
            else
                result.push_back(intervals[i-1]);
        }
        result.push_back(intervals[size-1]);
        return result;

    }
 };

 /*
 //96 ms
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result, temp;
        int size = intervals.size();
        if (size < 2) return intervals;
        temp =  merge_sort(intervals);
        for(int i =1; i<size; i++)
        {
            if ( temp[i-1].end >= temp[i].start)
            {
                temp[i].start = temp[i-1].start;
                temp[i].end = max(temp[i].end, temp[i-1].end);
            }
            else
                result.push_back(temp[i-1]);
        }
        result.push_back(temp[size-1]);
        return result;
    }

    vector<Interval> merge_sort(vector<Interval> intervals)
    {
        int n = intervals.size();
        if (n == 1)
        {
            return intervals;
        }
        int mid = n/2;
        vector<Interval> left, right;
        for(int i = 0 ; i < mid; i++)
        {
            left.push_back(intervals[i]);
        }
        for(int i = mid ; i < n; i++)
        {
            right.push_back(intervals[i]);
        }

        left = merge_sort(left);
        right = merge_sort(right);
        return merger(left , right);

    }
    vector<Interval> merger(vector<Interval> l, vector<Interval> r)
    {   vector<Interval> res;
        int i = 0, j = 0;
        while(i < int(l.size()) && j < int(r.size()) )
        {
            (l[i].start < r[j].start ) ? res.push_back(l[i++]) : res.push_back(r[j++]) ;
        }
        while (i < int(l.size())) res.push_back(l[i++]);
        while (j < int(r.size())) res.push_back(r[j++]);
        return res;
    }
};
*/
