# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
sliding window + mono queue 를 활용하면 O(N)으로 문제를 해결할 수 있다.
# Complexity
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(N)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        deque<int> deq;
        for(int i=0; i<nums.size();++i){
            if(i<k-1){
                if(deq.empty()) deq.push_back(i);
                else{
                    while(!deq.empty()&& nums[deq.back()]<=nums[i]){
                        deq.pop_back();
                    }
                    deq.push_back(i);
                }
            } 
            else{
                if(!deq.empty()&&deq.front()<=i-k){
                    deq.pop_front();
                }
                while(!deq.empty()&&nums[deq.back()]<=nums[i]){
                    deq.pop_back();
                }
                deq.push_back(i);
                answer.push_back(nums[deq.front()]);
            }
        }
        return answer;

    }
};


/*
모노큐의 의사코드
1. 인덱스 범위를 벗어난 값 버리기 (pop_front)
2. 신규 값 확인
3. 신규 값보다 작거나 같은 값 버리기 (pop_back)
4. 신규 값 추가 (push_back)
++ 주의할 점 : 인덱스를 사용할 때와 값을 사용할 때 구분해야 함.
*/
```
