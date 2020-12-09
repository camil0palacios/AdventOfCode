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
string ins[Mxn];
int num[Mxn];
bool vis[Mxn], vis2[Mxn][2];

struct state {
    int u, acc; bool ch;
    state(){}
    state(int u, bool ch, int acc): u(u), ch(ch), acc(acc) {}
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = 0;
    char c; int x;
    while(cin >> ins[n] >> c >> x) {
        num[n] = c == '-' ? -x : x;
        n++;
    }
    // part 1
    int acc = 0;
    for(int i = 0; i < n && !vis[i];) {
        vis[i] = 1;
        if(ins[i] == "nop") i++;
        else if(ins[i] == "acc") acc += num[i], i++;
        else if(ins[i] == "jmp") i += num[i];
    }
    cout << acc << endl;
    // part 2
    queue<state> q;
    q.emplace(0,0,0);
    vis2[0][0] = 1;
    while(!q.empty()) {
        int u = q.front().u;
        int ch = q.front().ch;
        int ac = q.front().acc;
        q.pop();
        if(u == n-1) { acc = ac; break; }
        int v1, v2 = -1, _acc = ac;
        if(ins[u] == "nop") v1 = u + 1;
        if(ins[u] == "acc") v1 = u + 1, _acc += num[u]; 
        if(ins[u] == "jmp") v1 = u + num[u];
        if(!vis2[v1][ch]) {
            vis2[v1][ch] = 1;
            q.emplace(v1, ch, _acc);
        }
        if(!ch) {
            if(ins[u] == "nop") v2 = u + num[u];
            if(ins[u] == "jmp") v2 = u + 1;
            if(v2 != -1 && !vis2[v2][ch^1]) {
                vis2[v2][ch^1] = 1;
                q.emplace(v2, ch^1, _acc);
            }
        }
    }
    cout << acc << endl;
    return 0; 
}