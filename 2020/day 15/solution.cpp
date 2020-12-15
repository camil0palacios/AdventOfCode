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

const int Mxn = 30000000;
int lst[Mxn + 10];

void solve(vi & a) {
    int n = sz(a);
    vll turn(Mxn + 2);
    fore(i,1,n) {
        turn[i] = a[i-1];
        if(i != n) lst[a[i-1]] = i;
    }
    for(int i = sz(a) + 1; i <= Mxn; i++) {
        if(!lst[turn[i-1]]) turn[i] = 0, lst[turn[i-1]] = i-1;
        else turn[i] = i - 1 - lst[turn[i-1]];
        lst[turn[i-1]] = i-1;
    }
    // part 1
    cout << turn[2020] << endl;
    // part 2
    cout << turn[Mxn] << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    vi a;
    int num = 0;
    fori(i,0,sz(s)) {
        if(s[i] == ',') {
            a.eb(num);
            num = 0;
        } else num = num*10 + (s[i]-'0');
    } 
    a.eb(num);
    solve(a);
    return 0; 
}