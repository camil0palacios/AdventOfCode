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

const int Mxn = 1e5 + 5;
map<string,int> mp;
vi g[Mxn];
vii g2[Mxn];
bool vis[Mxn], gold[Mxn];
int ans[Mxn];

bool is_num(string & s) {
    fori(i,0,sz(s)) {
        if(!isdigit(s[i])) return 0;
    }
    return 1;
}

void dfs(int u) {
    vis[u] = 1;
    for(auto & v: g[u]) {
        if(!vis[v]) {
            gold[v] |= gold[u];
            dfs(v);
        } 
    }
}

int dp[Mxn];

int dfs2(int u) {
    if(sz(g2[u]) == 0) return 0;
    if(dp[u] != -1) return dp[u];
    int ans = 0;
    for(auto & e : g2[u]) {
        int v = e.ft, w = e.sd;
        ans += dfs2(v)*w + w; 
    }
    return dp[u] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int n = 0;
    while(getline(cin, s)) {
        stringstream ss (s);
        int u = -1, num = 0;
        string t;
        while(ss >> s) {
            if(s == "contanins" || s == "contain" || s == "no" || s == "other") continue;
            if(is_num(s)) { num = stoi(s); continue; }
            if(s.substr(0,3) == "bag" && sz(t)) {
                if(!mp.count(t)) mp[t] = n++;
                if(u == -1) u = mp[t];
                else {
                    int v = mp[t];
                    g[v].eb(u);
                    g2[u].eb(v, num);
                }
                if(t == "shiny gold") gold[mp[t]] = 1;
                t.clear();
            } else t += (sz(t) ? " " : "") + s;
        }
    }
    int u = mp["shiny gold"];
    dfs(u);
    int ans = 0;
    fori(i,0,n) {
        ans += gold[i];
    }
    // part 1
    cout << ans - 1 << endl;
    // part 2
    memset(dp, -1, sizeof dp);
    cout << dfs2(u) << endl;
    return 0; 
}