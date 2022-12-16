#include <iostream>
#include <vector>

#define int long long
using namespace std;

vector<int> ways(int n)  {
    vector<int> p(n + 1);
    p[0] = 1;
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        int q = 1;
        while (i - ((3 * q * q - q) / 2) >= 0) {
            if (q % 2 == 0) {
                p[i] -= p[i - ((3 * q * q - q) / 2)];
                if (i - ((3 * q * q + q) / 2) >= 0) {
                    p[i] -= p[i - ((3 * q * q + q) / 2)];
                }
            } else {
                p[i] += p[i - ((3 * q * q - q) / 2)];
                if (i - ((3 * q * q + q) / 2) >= 0) {
                    p[i] += p[i - ((3 * q * q + q) / 2)];
                }
            }
            q++;
        }
    }
    return p;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p = ways(n + 1);
    cout << p[n];
    return 0;
}

