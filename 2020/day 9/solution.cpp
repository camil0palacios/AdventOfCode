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

const int Mxn = 1010;
ll a[Mxn];

ll solve(int n) {
    fori(i,25,n) {
        set<ll> s;
        bool ok = 0;
        fori(j,max(0, i - 25),i) {
            if(s.count(a[i] - a[j])) {
                ok = 1;
                break;
            }
            s.insert(a[j]);
        }
        if(!ok) return a[i];
    }
    return -1;
}

ll solve2(int n, ll s) {
    // pi - pj = s
    // pi - s = pj
    map<ll, int> m;
    m[0] = 0;
    ll p = 0;
    fori(i,0,n) {
        p += a[i];
        if(m.count(p - s)) {
            int j = m[p - s];
            ll mx = 0, mn = 1e18;
            fore(j,m[p - s],i) {
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
            }
            return mx + mn;
        }
        m[p] = i;
    }
    return -1;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = 0;
    while(cin >> a[n]) n++;
    // part 1
    ll ans = solve(n);
    cout << ans << endl;
    // part 2
    ans = solve2(n, ans);
    cout << ans << endl;
    return 0; 
}