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
string a[Mxn];

void part1(int n) {
    map<ll, ll> m;
    string msk;
    fori(i,0,n) {
        stringstream ss(a[i]);
        string s, num;
        bool ismsk = 0; 
        ll mem = 0;
        while(ss >> s) {
            if(s == "=") continue;
            if(s == "mask") ismsk = 1;
            else if(s.substr(0,3) == "mem") {
                fori(i,4,sz(s)) {
                    if(s[i] == ']') break;
                    mem = mem*10 + (s[i] - '0');
                }
            } else num = s;
        }
        if(ismsk) {
            msk = num;
            reverse(all(msk));
        }
        else {
            ll tmp = stoll(num);
            fori(i,0,sz(msk)) {
                if(msk[i] == 'X') continue;
                if(msk[i] == '0') tmp &= ~(1ULL << i);
                if(msk[i] == '1') tmp |= (1ULL << i);
            }
            m[mem] = tmp;
        }
    }
    ll ans = 0;
    for(auto & p : m) ans += p.sd;
    cout << ans << endl;
}

void allMsk(int i, ll pmem, string & msk, map<ll,ll> & m, ll & val) {
    if(i == sz(msk)) {
        m[pmem] = val;
        return;
    }
    if(msk[i] == '0') allMsk(i+1, pmem, msk, m, val);
    if(msk[i] == '1') allMsk(i+1, pmem | (1ULL << i), msk, m, val);
    if(msk[i] == 'X') {
        allMsk(i+1, pmem | (1ULL << i), msk, m, val);
        allMsk(i+1, pmem & ~(1ULL << i), msk, m, val);
    }
}

void part2(int n) {
    map<ll,ll> m;
    string msk;
    fori(i,0,n) {
        stringstream ss(a[i]);
        string s, num;
        bool ismsk = 0; 
        ll mem = 0;
        while(ss >> s) {
            if(s == "=") continue;
            if(s == "mask") ismsk = 1;
            else if(s.substr(0,3) == "mem") {
                fori(i,4,sz(s)) {
                    if(s[i] == ']') break;
                    mem = mem*10 + (s[i] - '0');
                }
            } else num = s;
        }
        if(ismsk) {
            msk = num;
            reverse(all(msk));
        } else {
            ll val = stoll(num);
            allMsk(0,mem,msk,m,val);
        }
    }
    ll ans = 0;
    for(auto & p : m) ans += p.sd;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = 0;
    while(getline(cin, a[n])) n++;
    part1(n);
    part2(n);
    return 0;
}