#include <bits/stdc++.h>

using namespace std;


int main() {
    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K, P;
        cin >> N >> K >> P;
        int a[N][K + 1];
        
        for (int j = 0; j < N; j++) {
            a[j][0] = 0;
            
            for (int k = 1; k <= K; k++) {
                cin >> a[j][k];
                a[j][k] += a[j][k - 1];
            }
        }
        
        int dp[N][P + 1];
        
        for (int p = 0; p < P + 1; p++) {
            if (p <= K) dp[0][p] = a[0][p];
            else dp[0][p] = 0;
        }
        
        for (int j = 1; j < N; j++) {
            for (int p = 0; p < P + 1; p++) {
                dp[j][p] = 0;
            }
        }
        
        for (int j = 1; j < N; j++) {
            for (int k = 0; k <= K; k++) {
                for (int p = k; p < P + 1; p++) {
                    dp[j][p] = max(dp[j][p], dp[j - 1][p - k] + a[j][k]);
                }
            }
        }
        
        cout << "Case #" << i + 1 << ": " << dp[N - 1][P] << endl;
    }
    
}
