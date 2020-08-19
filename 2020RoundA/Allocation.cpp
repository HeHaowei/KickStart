#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N, B;
        cin >> N >> B;
        int a[N];
        for (int j = 0; j < N; j++) {
            cin >> a[j];
        }
        sort(a, a + N);
        int res = 0;
        for (int j = 0; j < N; j++) {
            if (a[j] > B) break;
            else {
                B -= a[j];
                res++;
            }
        }
        cout << "Case #" << i + 1 << ": " << res << endl; 
    }
    
}
