#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
vector<int> dx = {1, 0, -1, 0, 0};
vector<int> dy = {0, 1, 0, -1, 0};
int main(){
  int H, W, K;
  cin >> H >> W >> K;
  int Si, Sj;
  cin >> Si >> Sj;
  Si--;
  Sj--;
  vector<vector<int>> A(H, vector<int>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> A[i][j];
    }
  }
  int N = min(H * W, K);
  vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(H, vector<long long>(W, -INF)));
  dp[0][Si][Sj] = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < H; j++){
      for (int k = 0; k < W; k++){
        for (int l = 0; l < 5; l++){
          int x = j + dx[l];
          int y = k + dy[l];
          if (0 <= x && x < H && 0 <= y && y < W){
            dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][j][k] + A[x][y]);
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      ans = max(ans, dp[N][i][j] + (long long) (K - N) * A[i][j]);
    }
  }
  cout << ans << endl;
}