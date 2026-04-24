# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
Convert the number to a string, create a copy of it, reverse the copied string, and then compare it with the original string.
# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        return reverse_s == s;
    }
};
```
