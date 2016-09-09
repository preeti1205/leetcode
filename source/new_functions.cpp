****The element pointed at by nth is changed to whatever element would occur in that position if [first, last)
was sorted.
All of the elements before this new nth element are less than or equal to the elements after
the new nth element.



    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());

    nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:

*****to arrange a vector in dec order : sort(res.begin(), res.end(), greater<int>())
                                  sort(res.rbegin(), res.rend())

**** upper_index gives a reference to the position that is greater than the given number
lower_index gives a reference to the first position that is less than or equal to the given number

****upper_bound(row.begin(), row.end(), num) - row.begin(); will give diffrence in position and not the value.
