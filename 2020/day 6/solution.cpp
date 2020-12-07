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
typedef vector<ii> vii;
typedef unordered_set<int> us;

int solve(string & s) {
    int n = sz(s);
    us c;
    fori(i,0,n) {
        c.insert(s[i]);
    }
    return sz(c);
}

int solve2(string & s, int cnt) {
    int n = sz(s);
    vi f(26);
    fori(i,0,n) {
        f[s[i]-'a']++;
    }
    int ans = 0;
    fori(i,0,26) {
        if(f[i] == cnt) ans++;
    } 
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ans = 0, ans2 = 0;
    string s, t;
    int cnt = 0;
    while(getline(cin, s)) {
        if(s.empty()) {
            ans += solve(t);
            ans2 += solve2(t, cnt);
            t.clear();
            cnt = 0;
        } else t += s, cnt++;
    }
    ans += solve(t);
    ans2 += solve2(t, cnt);
    // part 1
    cout << ans << endl;
    // part 2
    cout << ans2 << endl;
    return 0; 
}