# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
vector 크기를 처음에 할당해 재할당을 방지한다. 
O(NlogN)이 걸리는 sort 대신 O(N)의 "nth_element"를 사용해 정렬한다. 
# Complexity
- Time complexity: O(M*N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(M*N)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int total_size = m * n;

        vector<int> v;
        // 메모리 재할당(Reallocation) 방지
        v.reserve(total_size); 

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                v.push_back(grid[i][j]);
            }
        }

        int mid_index = total_size / 2;

        // O(N log N)인 sort 대신 O(N)인 nth_element 사용
        nth_element(v.begin(), v.begin() + mid_index, v.end());

        int target = v[mid_index];
        int sum = 0;

        for(int i = 0; i < total_size; ++i){
            
            if (abs(v[i] - target) % x != 0) return -1;
            sum += abs(v[i] - target) / x;
        }

        return sum;
    }
};
```
