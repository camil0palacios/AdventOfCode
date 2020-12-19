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

const int Mxn = 1e5 + 5;
int n;
string a[Mxn];

ll result(ll a, ll b, char op) {
    if(op == '+') return a + b;
    else return a * b;
}

ll exp(int idx, string & s) {
    ll ans = 0; char op = '+';
    for(int i = idx; i < sz(s); i++) {
        if(isdigit(s[i])) {
            ll x = s[i] - '0';
            ans = result(ans, x, op);
        }
        else if(s[i] == '+' || s[i] == '*') op = s[i];
        else if(s[i] == '(') {
            int x = exp(i + 1, s);
            ans = result(ans, x, op);
            int cnt = 0, j;
            for(j = i; j < sz(s); j++) {
                if(s[j] != '(' && s[j] != ')') continue;
                cnt += s[j] == '(' ? 1 : -1;
                if(cnt == 0) break;
            }
            i = j;
        }
        else if(s[i] == ')') return ans;
    }
    return ans;
}

void part1() {
    ll ans = 0;
    fori(i,0,n) {
        ll x = exp(0, a[i]);
        ans += x;
    }
    cout << ans << endl;
}

ll solve(vector<string> & v) {
    while(sz(v) > 1) {
        int j = 0;
        char op = '.';
        fori(i,0,sz(v)) {
            if(v[i] == "+") {
                op = v[i][0];
                j = i;
                break;
            }
            if(v[i] == "*") {
                op = v[i][0];
                j = i;
            }
        }
        ll ans = result(stoll(v[j-1]), stoll(v[j+1]), op);
        v.erase(v.begin() + j-1);
        v.erase(v.begin() + j-1);
        v[j-1] = to_string(ans);
    } 
    return stoll(v[0]);
}

ll exp2(int idx, string & s) {
    vector<string> v;
    for(int i = idx; i < sz(s); i++) {
        if(isdigit(s[i])) {
            ll x = s[i] - '0';
            v.eb(to_string(x));
        }
        else if(s[i] == '+' || s[i] == '*') v.eb(string(1, s[i]));
        else if(s[i] == '(') {
            v.eb(to_string(exp2(i + 1, s)));
            int cnt = 0, j;
            for(j = i; j < sz(s); j++) {
                if(s[j] != '(' && s[j] != ')') continue;
                cnt += s[j] == '(' ? 1 : -1;
                if(cnt == 0) break;
            }
            i = j;
        }
        else if(s[i] == ')') return solve(v);
    }
    return solve(v);
}

void part2() {
    ll ans = 0;
    fori(i,0,n) {
        ll x = exp2(0, a[i]);
        ans += x;
    }
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    n = 0;
    while(getline(cin, a[n])) n++;
    part1();
    part2();
    return 0;
}