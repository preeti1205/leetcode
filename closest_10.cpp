/*

Given an array of numbers between 1 and 100, write a C++ (or any other language of your choice) 
program to calculate the point that is within 10 of the most numbers in the array.
For example, given the following array:
10, 14, 15, 19, 28, 31, 34, 48, 52, 55

If you choose 20 as the point, there are 5 numbers within 10 of 20: (10, 14, 15, 19 and 28). 
But the program should choose 24 instead since there are 6 numbers in the array 
within 10 of 24: (14, 15, 19, 28, 31 and 34).
If there are ties, choose the lowest number among the possibilities.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findClosest(vector<int> &numbers) {
	int size = numbers.size();
	pair<int, int> indexCache(0, -1);

	if (size == 0) 
		throw domain_error(" No number entered ");

	sort(numbers.begin(), numbers.end());
	int start_index = 0;
	int end_index = start_index + 1;

	while(start_index < size && end_index < size) {		
		// will stop one step ahead of the last acceptable value
		while( (end_index < size) && (numbers[end_index] - numbers[start_index]) <= 20) {
			++end_index;
		}

		if ( (end_index - 1 - start_index) > ( indexCache.second  - indexCache.first) ) {
			indexCache.second = end_index - 1;
			indexCache.first = start_index;
		}
		++start_index;
		++end_index;
	}
	return  max(numbers[indexCache.second] - 10, 1); //because the range is from 1 to 100 and (num - 10) could be negative
}

int main() {
	vector<int> input;
	int num;
	cout << "Enter the numbers: ";
	while(cin >> num) {
		input.push_back(num);
	}

	int result = findClosest(input);
	cout << result << endl;
	return 0;
}