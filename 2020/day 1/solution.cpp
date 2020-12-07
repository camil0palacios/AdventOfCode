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
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    while(cin >> a[n]) n++;
    us s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s.count(2020-a[i]-a[j])) {
                cout << 1LL*a[i]*a[j]*(2020 - a[i] - a[j]) << endl;
                return 0;
            }
        }
        s.insert(a[i]);
    }
    return 0; 
}