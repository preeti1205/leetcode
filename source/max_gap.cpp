/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0 ;
        int count = 0;
        int maxi = *max_element(nums.begin(), nums.end()); //remember
        vector<int> final = nums;

        while(maxi)
        {
            maxi = maxi/10;
            vector<queue<int>> bucket;
            for(int i = 0; i < size ; i++)
            {
                int n  = nums[i]%10;
                bucket[n].push(final[i]);
                nums[i] = nums[i]/10;
            }
            int count = 0;
            /*
            for(int i = 0; i < bucket.size() ; i++)
            {
                while(!bucket[i].empty())
                {
                    final[count++] = bucket[i].front();
                    cout<<bucket[i].front()<<" ";
                    bucket[i].pop();
                }
            }
            */
        }

        /*
        for(int i = 0; i <size; i++)
        {
            cout<<final[i]<<endl;
        }
        */
        return 0;

    }
};
//30 ms solution
/*
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        map<int, int> hash;
        map<int, int>::iterator it;
        int result = 0;

        for(int i =0; i< size; i++)
        {
            hash[nums[i]] += 1;
        }

        int prev_ele = hash.begin()->first;
        for(it = hash.begin(); it != hash.end() ; it++)
        {
                result = max(result , it->first - prev_ele );
                prev_ele = it->first;
        }

        return result;
    }
};
*/
