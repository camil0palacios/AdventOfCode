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
typedef vector<vi> mat;

vi myticket;
vector<string> names;
mat ranges, other, rest;

bool anyValid(int x) {
    int n = sz(ranges);
    fori(i,0,n) {
        if(ranges[i][0] <= x && x <= ranges[i][1]) return 1;    
    }
    return 0;
}

void part1() {
    int ans = 0;
    int n = sz(other);
    fori(i,0,n) {
        int m = sz(other[i]);
        bool valid = 1;
        fori(j,0,m) {
            bool ok = anyValid(other[i][j]);
            if(!ok) ans += other[i][j];
            valid &= ok;
        }
        if(valid) rest.eb(other[i]);
    }
    cout << ans << endl;
}

vi g[55];
int match[55];
bool seen[55];

bool bpm(int u) {
    for(auto & v : g[u]) {
        if(!seen[v]) {
            seen[v] = 1;
            if(match[v] < 0 || bpm(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

void allValid(vi & col, int idx) {
    int n = sz(col), m = sz(ranges);
    for(int i = 0; i < m; i += 2) {
        bool ok = 1;
        fori(j,0,n) {
            ok &= (ranges[i][0] <= col[j] && col[j] <= ranges[i][1]) || 
                (ranges[i+1][0] <= col[j] && col[j] <= ranges[i+1][1]);
        }
        if(ok) {
            g[idx].eb(m/2 + i/2);
        }
    }
}

void part2() {
    rest.eb(myticket);
    int n = sz(rest), m = sz(rest[0]);
    fori(j,0,m) {
        vi col;
        fori(i,0,n) col.eb(rest[i][j]);
        allValid(col, j);
    }
    memset(match, -1, sizeof match);
    int cnt = 0;
    fori(i,0,m) {
        memset(seen, 0, sizeof seen);
        if(bpm(i)) cnt++;
    }
    ll ans = 1;
    fori(i,0,m) {
        if(names[i].substr(0,9) == "departure") ans *= (ll)myticket[match[m + i]];
    }
    cout << ans << endl;
}

vi get_nums(string & s) {
    int n = sz(s), num = 0;
    vi v;
    fori(i,0,n) {
        if(s[i] == ',' || s[i] == '-') {
            v.eb(num);
            num = 0;
        } else num = num*10 + (s[i] - '0');
    }
    v.eb(num);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int type = 0;
    string s;
    while(getline(cin, s)) {
        stringstream ss(s);
        string name;
        while(ss >> s) {
            if(s == "your" || s == "nearby") { type++; continue; }
            if(type == 0) { 
                if(isdigit(s[0])) ranges.eb(get_nums(s));
                else {
                    if(s.back() == ':') {
                        name += s.substr(0, sz(s)-1);
                        names.eb(name);
                    } else name += s;
                }
            }
            else if(type == 1 && isdigit(s[0])) myticket = get_nums(s);
            else if(type == 2 && isdigit(s[0])) other.eb(get_nums(s));
        }
    }
    part1();
    part2();
    return 0;
}