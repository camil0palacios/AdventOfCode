#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 1e5 + 5;
int a[Mxn];
ll dp[Mxn];

ll solve2(int n) {
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 3; j++) {
            if(i - j >= 0 && a[i] - a[i - j] <= 3) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n-1];
}

int solve(int n) {
    int dif[4] = {0, 0, 0, 0};
    fori(i,1,n) {
        dif[a[i] - a[i-1]]++;
    }
    // cout << dif[1] << ' ' << dif[3] << endl;
    return dif[1] * dif[3];
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = 0;
    a[n++] = 0;
    while(cin >> a[n]) n++;
    sort(a, a + n);
    a[n] = a[n-1] + 3; n++;
    // part 1
    cout << solve(n) << endl;
    // part 2
    cout << solve2(n) << endl;  
    return 0; 
}