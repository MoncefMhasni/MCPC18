#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cerr << (#x) << " is " << (x) << endl

int main() {
    freopen("parabolic.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll n, x, y;

    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        ll answer = ceil(1.0 * 2 * n * sqrt(y * y + x * x * 1.0 / (4 * n * n)));
        cout << answer << '\n';
    }
}
