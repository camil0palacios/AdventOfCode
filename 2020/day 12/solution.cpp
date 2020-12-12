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

//  e n w s
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void move(int & x, int & y, int & c, char op, int n) {
    if(op == 'N') y += n; 
    if(op == 'S') y -= n;
    if(op == 'E') x += n;
    if(op == 'W') x -= n;
    if(op == 'L') {
        fori(i,0,n/90) {
            int t = x;
            x = -y;
            y = t;
        }
    }
    if(op == 'R') {
        fori(i,0,n/90) {
            int t = -x;
            x = y;
            y = t;
        } 
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char op; int n;
    int x = 0, y = 0, dir = 0;
    int xp = 10, yp = 1, c = 0;
    while(cin >> op >> n) {
        if(op == 'F') x += n*xp, y += n*yp;
        else move(xp, yp, c, op, n);
    }
    cout << abs(x) + abs(y) << endl;
    return 0; 
}