/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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

// 16 ms 
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        int size = intervals.size();
        vector<Interval> left,right;
        for(int i =0; i < size; i++)
        {
            if      (intervals[i].end < newInterval.start) left.push_back(intervals[i]);
            else if (newInterval.end < intervals[i].start ) right.push_back(intervals[i]);
            else
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max (newInterval.end, intervals[i].end);
            }
        }

        left.push_back(newInterval);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

 /* 20 ms solution
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int size = intervals.size();
        if (size == 0)
        {
            result.push_back(newInterval);
            return result;
        }
        int i = 0;

        while(i <size)
        {
            if (intervals[i].start > newInterval.start)
            {
                result.push_back(newInterval);
                break;
            }
            else if (intervals[i].end >= newInterval.start)
            {
                Interval in;
                in.start = intervals[i].start;
                in.end = max(intervals[i].end, newInterval.end);
                result.push_back(in);
                break;
            }
            else result.push_back(intervals[i++]);
        }
        if(i==size) result.push_back(newInterval);
        while(i<size)
        {
            if (result.back().end >= intervals[i].start)
            {
                result.back().end = max(result.back().end, intervals[i++].end);
            }
            else break;
        }
        while(i<size)
        {
            result.push_back(intervals[i++]);
        }
        return result;

    }
};
*/
