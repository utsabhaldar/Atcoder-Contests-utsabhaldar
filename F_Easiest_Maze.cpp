#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M, K;
  cin >> N >> M >> K;
  if (K < N || (K - N) % 2 != 0){
    cout << "No" << endl;
  } else {
    vector<vector<char>> S(2 * N + 1, vector<char>(2 * M + 1, '+'));
    for (int i = 1; i < N * 2; i += 2){
      for (int j = 1; j < M * 2; j += 2){
        S[i][j] = 'o';
      }
    }
    S[0][M * 2 - 1] = 'S';
    S[N * 2][M * 2 - 1] = 'G';
    for (int i = 1; i < N * 2; i += 2){
      for (int j = 2; j <= M * 2 - 2; j += 2){
        S[i][j] = '|';
      }
    }
    for (int i = 2; i <= N * 2 - 2; i += 2){
      for (int j = 1; j < M * 2 - 1; j += 2){
        S[i][j] = '-';
      }
      S[i][M * 2 - 1] = '.';
    }
    K -= N;
    for (int i = 1; i <= N * 2 - 3; i += 4){
      for (int j = M * 2 - 1; j >= 3; j -= 2){
        if (K > 0){
          S[i + 1][j] = '-';
          S[i][j - 1] = '.';
          S[i + 2][j - 1] = '.';
          S[i + 1][j - 2] = '.';
          K -= 2;
        }
      }
    }
    for (int j = 1; j <= M * 2 - 5; j += 4){
      if (K > 0){
        S[N * 2 - 3][j + 1] = '|';
        S[N * 2 - 2][j] = '.';
        S[N * 2 - 2][j + 2] = '.';
        S[N * 2 - 1][j + 1] = '.';
        K -= 2;
      }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N * 2 + 1; i++){
      for (int j = 0; j < M * 2 + 1; j++){
        cout << S[i][j];
      }
      cout << endl;
    }
  }
}