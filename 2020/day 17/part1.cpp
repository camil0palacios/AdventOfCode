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

typedef vector<string> vs;

const int Mxn = 110;
const int offst = 25;
char a[Mxn][Mxn][Mxn];
char b[Mxn][Mxn][Mxn];

bool check(int x, int y, int z) {
    return x >= 0 && x < Mxn && y >= 0 && y < Mxn && z >= 0 && z < Mxn && a[x][y][z] == '#';
}

int neighbours(int x, int y, int z) {
    int cnt = 0;
    fore(i,-1,1) fore(j,-1,1) fore(k,-1,1) {
        if(x+i == x && y+j == y && z+k == z) continue; 
        cnt += check(x+i,y+j,z+k);
    }
    return cnt;
}

bool change(char c, int cnt) {
    if(c == '#') return cnt != 2 && cnt != 3;
    if(c == '.') return cnt == 3;
    return 0;
}

void run() {
    memcpy(b, a, sizeof a);
    fori(i,0,Mxn) fori(j,0,Mxn) fori(k,0,Mxn) {
        if(change(a[i][j][k], neighbours(i,j,k))) 
            b[i][j][k] = a[i][j][k] == '#' ? '.' : '#';
    }
    memcpy(a, b, sizeof b);
}

int count() {
    int cnt = 0;
    fori(i,0,Mxn) fori(j,0,Mxn) fori(k,0,Mxn) 
        cnt += a[i][j][k] == '#';
    return cnt;
}

void part1(vs & mc) {
    int n = sz(mc);
    memset(a, '.', sizeof a);
    fori(i,0,n) fori(j,0,n) a[i+offst][j+offst][offst] = mc[i][j]; 
    fori(i,0,6) run();
    cout << count() << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    vs mc;
    while(cin >> s) mc.eb(s);
    part1(mc);
    return 0;
}