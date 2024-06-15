#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> stands(N);
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        int bitmask = 0;
        for (int j = 0; j < M; ++j) {
            if (S[j] == 'o') {
                bitmask |= (1 << j);
            }
        }
        stands[i] = bitmask;
    }
    
    int msk = (1 << M) - 1; 
    int mn = N + 1; 
    
    for (int mask = 1; mask < (1 << N); ++mask) {
        int tmp = 0;
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                tmp |= stands[i];
                ++count;
            }
        }
        if (tmp == msk) {
            mn = min(mn, count);
        }
    }
    
    cout << mn << endl;
    return 0;
}
