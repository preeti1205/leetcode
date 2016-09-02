nth element function in cpp: used to sort in O(n) time using some partial sorting algo - <algorithm>
The element pointed at by nth is changed to whatever element would occur in that position if [first, last)
was sorted.
All of the elements before this new nth element are less than or equal to the elements after
the new nth element.



    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());

    nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:
