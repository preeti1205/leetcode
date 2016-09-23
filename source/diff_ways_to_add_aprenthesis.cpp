/*
Given a string of numbers and operators,
return all possible results from computing all the different possible ways to group numbers
and operators. The valid operators are +, - and *.

Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2

Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
      int size = input.size();
      vector<int> result;

      for(int i =0; i< size; i++){
        if(!isdigit(input[i])){
          char c = input[i];
          for(int a: diffWaysToCompute(input.substr(0,i))){
            for(int b:diffWaysToCompute(input.substr(i+1))){
                result.push_back(c=='+'? a+b: c=='-'? a-b: a*b);
           }
         }
       }
    }
    return result.size()? result: vector<int> {stoi(input)};
  }
};
