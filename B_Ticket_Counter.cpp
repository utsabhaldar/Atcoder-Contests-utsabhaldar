#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (ans < T[i]) {
            ans = T[i];
        }
        ans += A;
        cout << ans << endl;
    }
    
    return 0;
}
