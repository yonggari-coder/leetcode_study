# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
파이프 이동 방향을 먼저 정의해놓고 (mx, my) Bfs를 통해 탐색을 진행한다.
먼저 가보고, 다시 돌아올 수 있으면 큐에 추가한다.
# Complexity
- Time complexity: O(N*M) (=dir * N*M)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(N*M)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int mx[6][2] = {{0,0}, {-1,1}, {0,1},{1,0}, {0,-1},{0,-1}};
        int my[6][2] = {{-1,1}, {0,0},{-1,0},{0,1},{-1,0},{1, 0}};

        int m =grid.size();
        int n = grid[0].size();

        if(m==1&&n==1) return true;

        int st_obj = grid[0][0];  // 1 <= st_obj <=6
        int st_r = 0;
        int st_c = 0;
        
        int check[301][301];
        memset(check, 0, sizeof(check));

        queue<pair<int,int>> q;
        while(!q.empty()) q.pop();

        q.push({st_r, st_c});
        check[st_r][st_c] = 1;

        while(!q.empty()){
            int x= q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<2;++i){
                int nx = x + mx[grid[x][y]-1][i];
                int ny = y + my[grid[x][y]-1][i];

                if(nx<0||nx>=m||ny<0||ny>=n) continue;
                if(check[nx][ny]) continue;
                
                for(int j=0; j<2; ++j){
                    int wx = nx + mx[grid[nx][ny]-1][j];
                    int wy = ny + my[grid[nx][ny]-1][j];

                    if(wx==x && wy == y) {
                        q.push({nx,ny});
                        check[nx][ny] = check[x][y] +1;
                        if(nx==m-1 && ny == n-1) return true;
                        break;
                    }
                }
            }
        }
        return false;
    }
};
```
