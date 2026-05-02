#include <cstring>
#include <iostream>
using namespace std;

int dp[100005];
int arr[100005];
int N;

int dpp(int k) {
  if (k == 1)
    return 0;
  if (k == 2)
    return abs(arr[2] - arr[1]);

  if (dp[k] != -1)
    return dp[k];

  dp[k] = min(dpp(k - 1) + abs(arr[k] - arr[k - 1]),
              dpp(k - 2) + abs(arr[k] - arr[k - 2]));

  return dp[k];
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }

  memset(dp, -1, sizeof(dp));

  cout << dpp(N);
}

// dp 활용
// top down 방식으로 문제를 풀이함.
// 메모이제이션을 통해 시간초과 문제 해결.