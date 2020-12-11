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
typedef vector<string> vs;

int dx[8] = {1, 0,-1, 0, 1, 1,-1,-1};
int dy[8] = {0, 1, 0,-1, 1,-1, 1,-1};

bool check(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int solve(vs a) {
    int n = sz(a), m = sz(a[0]);
    vs b;
    do {
        b = a;
        fori(i,0,n) {
            fori(j,0,m) {
                int cnt = 0;
                fori(k,0,8) {
                    int mx = i + dx[k], my = j + dy[k];
                    if(check(mx, my, n, m) && b[mx][my] == '#') cnt++;    
                }
                if(a[i][j] == '#' && cnt >= 4) a[i][j] = 'L';
                if(a[i][j] == 'L' && !cnt) a[i][j] = '#'; 
            }
        }
    } while(a != b);
    int ans = 0;
    fori(i,0,n) {
        fori(j,0,m) {
            ans += a[i][j] == '#';
        }
    }
    return ans;
}

bool count(int x, int y, int dirx, int diry, vs & a) {
    int n = sz(a), m = sz(a[0]);
    while(1) {
        x += dirx;
        y += diry;
        if(check(x, y, n, m)) {
            if(a[x][y] != '.') return a[x][y] == '#';
        } else break;
    }
    return 0;
}

int solve2(vs a) {
    int n = sz(a), m = sz(a[0]);
    vs b;
    do {
        b = a;
        fori(i,0,n) {
            fori(j,0,m) {
                int cnt = 0;
                fori(k,0,8) {
                    cnt += count(i, j, dx[k], dy[k], b);
                }
                if(a[i][j] == '#' && cnt >= 5) a[i][j] = 'L';
                if(a[i][j] == 'L' && !cnt) a[i][j] = '#';
            }
        }
    } while(a != b);
    int ans = 0;
    fori(i,0,n) {
        fori(j,0,m) {
            ans += a[i][j] == '#';
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vs a;
    for(string s; cin >> s; a.eb(s)) {}
    // part 1
    cout << solve(a) << endl;
    // part 2
    cout << solve2(a) << endl; 
    return 0; 
}