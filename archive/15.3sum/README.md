# Three Sum

## Solution


ThreeSum will use twoSum as a sub-routine to address the problem. 


First of all look at twoSum. 

1. It need to be sorted to apply the two-pointer method.
2. `lo` and `hi` pointer.
3. `left` and `right` to store the current num. This is critical since 
    we need to keep track of the current solution and update the pointer
    accordingly to avoid duplicate solutions.
4. Update `lo` and `hi` according to the relation of `sum` and `target`. 
    Note that the additional while loop to update the pointers. The while 
    loops are updating the ptrs to avoid duplicate solutions.
5. Remember to update the pointers when the solution is found.


<br>
Check out the threeSum solution. 

It uses similar logic to twoSum.

Find out the two sum solution for each element, and add the triplet as solution.

To avoid duplicate solutions, increment `i` when there is a duplicate number.
