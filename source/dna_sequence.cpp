/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        //128ms
        int size = s.size();
        unordered_map<int,bool> hash; //saves memory as compared to using int as value
        vector<string> result={};
        int i =0, num;

        while(i<9)
        {
            num = ((num<<2) | mapper(s[i++]));
        }

        for(; i<size; i++)
        {
            num = ( ((num<<2) & 0xfffff) | mapper(s[i]));

            if (hash.find(num) != hash.end())
            {
                if(hash[num])
                {
                    result.push_back(s.substr(i-9,10));
                    hash[num] = false;
                }
            }
            else
            {
                hash[num] = true;
            }
        }

        //100 ms
        //Since there are only 4 alphabets, same them in 2 bits. Full string can be saved as an integer(2*10)
        /*
        int size = s.size();
        unordered_map<int,int> hash;
        vector<string> result={};
        int num=0, i;

        for(i=0; i<9; i++)
        {
            num = ((num<<2) | mapper(s[i]));
        }

        for(; i<size; i++)
        {
            num = (((num<<2) & 0xfffff) | mapper(s[i]));
            if(hash[num]++ == 1)        //if the value does not exist in hash, [] operator creates one(cpp behaviour)
            {
                result.push_back(s.substr(i-9,10));
            }
        }
        */


        //Naive solution. Lot of memory neeeded -> 158ms
        /*
        int size = s.size();
        vector<string> result={};
        unordered_map<string,int> hash;
        unordered_map<string,int>:: iterator it;

        /*
        for(int i = 0; i <= (size-10); i++)
        {
            string str = s.substr(i,10);

            if( hash.find(str) != hash.end())
            {
                hash[str]++;
            }
            else
            {
                hash.insert(make_pair(str,1));
            }
        }

        for( it = hash.begin(); it!= hash.end(); it++)
        {
            if( (it->second) >1)
            {
                result.push_back(it->first);
            }
        }
        */

        return result;

    }

private:
    int mapper(char ch)
    {
        switch (ch){
            case 'A':return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
};
