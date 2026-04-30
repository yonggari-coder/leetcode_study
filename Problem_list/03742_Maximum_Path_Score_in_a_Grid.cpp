class Solution {
  vector<vector<vector<int>>> memo;

public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

    int ans = dfs(m - 1, n - 1, k, grid);

    return ans < 0 ? -1 : ans;
  }

private:
  int dfs(int r, int c, int k, const vector<vector<int>> &grid) {
    if (r < 0 || c < 0 || k < 0)
      return -1e9;
    if (r == 0 && c == 0)
      return 0;

    if (memo[r][c][k] != -1)
      return memo[r][c][k];

    int score = grid[r][c];
    int cost = (score > 0) ? 1 : 0;

    int up = dfs(r - 1, c, k - cost, grid);
    int left = dfs(r, c - 1, k - cost, grid);

    return memo[r][c][k] = max(up, left) + score;
  }
};