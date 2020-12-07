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
int n, m;
string a[Mxn];

int count_trees(int right, int down) { 
    int ans = 0;
    for(int i = 0, j = 0; i < n; i += down, j = (j + right) % m) {
        if(a[i][j] == '#') ans++;
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> a[n]) n++;
    m = sz(a[0]);
    int ans = 0;
    // part 1
    for(int i = 0, j = 0; i < n; i++, j = (j + 3) % m) {
        if(a[i][j] == '#') ans++;
    }
    cout << ans << endl;
    // part 2
    ll ans2 = 1LL*count_trees(1,1)*count_trees(3,1)*count_trees(5,1)*count_trees(7,1)*count_trees(1,2);
    cout << ans2 << endl; 
    return 0; 
}