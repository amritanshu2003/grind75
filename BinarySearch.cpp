# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
/*
Its a divide & search algorithm
it works by repeatedly dividing the search space in half until the target is found
or the search space is empty.
Use two pointers start & end to represent the range of array search
calculate the mid element index
compare if mid element is same as target return the index you found the target
- if nums[mid] > target that means search in the right side st = mid + 1
- if nums[mid] < target that means search in the left side end = mid - 1
Repeat the above steps
*/
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        while( st <= end ){
            int mid = st + (end - st) / 2;
            cout<<"1- st="<<st<<" end="<<end<<" mid="<<mid 
            << "  mid_elem="<<nums[mid]
            << "  target="<<target<<endl;
            if(nums[mid] == target) {
                return mid; //found target
            } else if( nums[mid] < target){
                st = mid + 1; //search right
            } else {
                end = mid - 1; //search left
            }
            cout<<"2- st="<<st<<" end="<<end<<" mid="<<mid 
            << "  mid_elem="<<nums[mid]
            << "  target="<<target<<endl;
        }
        return -1;
    }
};
```
