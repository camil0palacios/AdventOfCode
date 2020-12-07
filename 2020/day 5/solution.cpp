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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int mx = 0;
    vi ids;
    while(cin >> s) {
        int r = 0, c = 0;
        int lx = 0, rx = 127;
        fori(i,0,7) {
            int m1 = (lx + rx) / 2;
            int m2 = (lx + rx + 1) / 2; 
            if(s[i] == 'F') rx = m1;
            else lx = m2;
        }
        r = s[6] == 'F' ? lx : rx;
        int ly = 0, ry = 7;
        fori(i,7,10) {
            int m1 = (ly + ry) / 2;
            int m2 = (ly + ry + 1) / 2;
            if(s[i] == 'L') ry = m1;
            else ly = m2;
        }
        c = s[9] == 'L' ? ly : ry; 
        mx = max(mx, r*8 + c);
        ids.eb(r*8 + c);
    }
    // part 1
    cout << mx << endl;
    // part 2
    int myseat = 0;
    sort(all(ids));
    fori(i,1,sz(ids)) {
        if(ids[i]-2 == ids[i-1]) {
            myseat = ids[i]-1;
            break;
        }
    }
    cout << myseat << endl;
    return 0; 
}