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
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, r;
    char c, s[200000]; 
    int ans = 0, ans2 = 0;
    while(scanf("%d-%d %c: %s", &l, &r, &c, &s) != EOF) {
        int n = strlen(s);
        int cnt = 0;
        fori(i,0,n) {
            cnt += s[i] == c;
        }
        ans += cnt >= l && cnt <= r;
        ans2 += (s[l-1] == c) ^ (s[r-1] == c);
    }
    cout << ans << endl;
    cout << ans2 << endl;
    return 0; 
}