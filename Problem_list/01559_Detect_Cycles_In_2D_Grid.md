# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
check 배열은 한 번만.
"결국 돌다가 만날거라면, 특정 지점에서는 나보다 거리가 짧은 칸이 2개이상 나오게 될 것이다."
# Approach
<!-- Describe your approach to solving the problem. -->
BFS를 활용해, 특정 문자와 일치하는 칸을 계속해서 탐색해가며 시작지점에서의 거리를 기록한다.
거리가 2이상일 때부터, 주변 4방향을 보며 현재 칸보다 시작지점까지의 거리가 짧은 칸이 2칸 이상이면 true를 리턴한다.
# Complexity
- Time complexity: O(N^2) (= O(R*C))
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(N^2) (= O(R*C))
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        
        int check[501][501];
        memset(check, 0, sizeof(check));
        
        queue<pair<int,int>> q;
        while(!q.empty()) q.pop();

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0, 1, 0, -1};
        char start = 'a';
        int sz = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(!check[i][j]){
                    sz = 1;
                    start = grid[i][j];
                    check[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        
                        int cnt = 0;
                        for(int k=0; k<4;++k){
                            if(x+dx[k]<0||x+dx[k]>=grid.size()||y+dy[k]<0||y+dy[k]>=grid[i].size()) continue;
                            if(check[x+dx[k]][y+dy[k]]&& start==grid[x+dx[k]][y+dy[k]]) cnt++;
                        }
                        if(cnt>=2){
                            if(check[x][y]>=2) return true;
                        }
                        
                        q.pop();

                        for(int k=0; k<4;++k){
                            int nx = x+dx[k];
                            int ny = y+dy[k];
                            if(nx<0||nx>=grid.size()||ny<0||ny>=grid[i].size()) continue;
                            if(check[nx][ny]) continue;
                            if(grid[nx][ny]!=start) continue;
                            check[nx][ny] = check[x][y]+1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return false;
    }
};
```
