#include <bits/stdc++.h>
using namespace std;
#define pclh0
#ifdef pclh
#define debug(...) do {\
    fprintf(stderr, "Line: %d - (%s) = ", _LINE_, #__VA_ARGS__);\
    DO(__VA_ARGS_);\
}while(0);
template<typename I>void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T>void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#else
#define debug(...)
#endif
struct DisjointSet {
    int p[55] = {};
    int group[55] = {};
    void Init(int n) {
        for (int i = 0; i <= n; i++) {
            p[i] = i;
            group[i] = 1;
        }
    }
    int Find(int x) {
        return (x == p[x] ? x : p[x] = Find(p[x]));
    }
    void Union(int a, int b) {
        a = Find(a), b = Find(b);
        if(a==b) return ;
        
        if (group[b] > group[a]) {
            swap(a, b);
        }
        p[b] = a;
        group[a] += group[b];
    }
}djs;
string arr[55] = {};
long long dp[55][55] = {};
void lcs(int a, int b) {
    debug(arr[a], arr[b], a, b);
    for (int i = 0; i <= arr[a].size(); i++) dp[i][0] = 0;
    for (int i = 0; i <= arr[b].size(); i++) dp[0][i] = 0;
    //if (str[a][0] == str[b][0]) dp[1][1] = 1;
    for (int i = 1; i <= arr[a].size(); i++) {
        for (int j = 1; j <= arr[b].size(); j++) {
            if (arr[a][i-1] == arr[b][j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    debug(a, b, dp[arr[a].size()][arr[b].size()], min(arr[a].size(), arr[b].size()) / 2.0);
    int len = dp[arr[a].size()][arr[b].size()];
    if (len*2 >= min(arr[a].size(), arr[b].size())) {
        djs.Union(a, b);
        cout<<"uni"<<a<<' '<<b<<'\n';
        debug("union", a, b);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //arr[0] = "abc";
    //arr[1] = "adb";
    //lcs(0, 1);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        djs.Init(n);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        debug(n);
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                lcs(i, j);
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = max(djs.group[i], ans);
            cout<<djs.group[i]<<' ';
        }
        cout<<'\n';
        cout << ans << endl;
    }
    return 0;
}