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

const int oo = 1e9;

void part1(int y, string s) {
    vi a;
    int n = sz(s);
    int num = 0;
    fori(i,0,n) {
        if(s[i] == 'x') continue;
        if(s[i] == ',') {
            if(num) a.eb(num), num = 0;
        } else num = num*10 + (s[i] - '0');

    }
    if(num) a.eb(num);
    n = sz(a);
    int idx = 0, mn = oo;
    fori(i,0,n) {
        int x = (y + a[i] - 1) / a[i];
        if(x*a[i] - y < mn) {
            mn = x*a[i] - y;
            idx = i;
        }
    }
    cout << mn*a[idx] << endl;
}

void part2(string s) {
    vii a;
    int n = sz(s);
    int num = 0, pos = 0;
    fori(i,0,n) {
        if(s[i] == 'x') continue;
        if(s[i] == ',') {
            if(num) a.eb(num, pos), num = 0;
            pos++;
        } else num = num*10 + (s[i] - '0');
    }
    if(num) a.eb(num, pos);
    n = sz(a);
    ll inc = a[0].ft;
    ll t = a[0].ft;
    fori(i,1,n) {
        while((t + a[i].sd) % a[i].ft != 0) t += inc;
        inc *= a[i].ft;
    }
    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int y;
    string s;
    cin >> y >> s;
    part1(y, s);
    part2(s);
    return 0;
}