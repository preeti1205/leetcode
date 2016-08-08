/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
//26 ms
/*
class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        int size = nums.size();
        if(size < 2)return 0;
        int maxi = *max_element(nums.begin(), nums.end()); //remember
        int exp = 1, result= 0;
        while(maxi)
        {
            countsort(nums, exp);
            exp *= 10;
            maxi /= 10;
        }

        for(int i =1; i < size; i++)
        {
            result = max(result, nums[i]- nums[i-1]);
        }
        return result;
    }

    void countsort(vector<int> &arr, int e )
    {
        vector<queue<int>> bucket;
        queue<int> q[10];
        int indx=0;
        for(int i =0; i < int(arr.size()) ;i++)
        {
            int a= arr[i]/e;
            q[a%10].push(arr[i]);
        }
        for(int i = 0; i < 10; i++)
        {
            bucket.push_back(q[i]);
        }

        for(int i = 0; i < int(bucket.size()); i++)
        {
            while(!bucket[i].empty())
            {
                arr[indx++] = bucket[i].front();
                bucket[i].pop();
            }
        }

    }
};

class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
      int size = nums.size();
          if(size < 2) return 0 ;
          int count = 0, result = 0;
          int maxi = *max_element(nums.begin(), nums.end()); //remember
          while(maxi)
          {
              vector<queue<int>> bucket; // important to declare inside the loop. otherwise, push_back will create more buckets
              queue<int> q1, q0;
              for(int i = 0; i < size ; i++)
              {
                  if ((nums[i]>>count)&1)   q1.push(nums[i]);
                  else                      q0.push(nums[i]);
              }
              bucket.push_back(q0);
              bucket.push_back(q1);
              maxi >>= 1;
              count++ ;
              int indx= 0;
              for(int i = 0; i < 2 ; i++)
              {
                  while(!bucket[i].empty())
                  {
                      nums[indx++] = bucket[i].front();
                      bucket[i].pop();
                  }
              }

          }
          for(int j = 1; j< size; j++)
          {
              result = max(result, nums[j] - nums[j-1]);
          }
          return result;

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
