#include <bits/stdc++.h>
#include <regex>
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

bool yrValid(string s, int l, int r) {
    if(sz(s) != 4) return 0;
    int n = stoi(s);
    return l <= n && n <= r;
}

bool hgtValid(string s) {
    regex str_expr ("[0-9]+(in|cm)");
    if(!regex_match(s, str_expr)) return 0;
    int i = sz(s) - 2;
    int num = stoi(s.substr(0, i));
    string hgt = s.substr(i);
    if(hgt == "cm") return num >= 150 && num <= 193;
    return num >= 59 && num <= 76;
}

bool hclValid(string s) {
    regex str_expr ("#[0-9a-f]{6}");
    return regex_match(s, str_expr);
}

bool eclValid(string s) {
    set<string> ecl({"amb", "blu", "brn", "gry", "grn", "hzl", "oth"});
    return ecl.count(s);
}

bool pidValid(string s) {
    regex str_expr ("[0-9]{9}");
    return regex_match(s, str_expr);
}

bool passValid(string & x) {
    stringstream ss(x);
    string s;
    set<string> dic({"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"});
    set<string> tmp;
    while(ss >> s) {
        bool ok = 1;
        string x = s.substr(0,3);
        if(x == "byr") { if(yrValid(s.substr(4), 1920, 2002)) tmp.insert(x); }
        else if(x == "iyr") { if(yrValid(s.substr(4), 2010, 2020)) tmp.insert(x); }
        else if(x == "eyr") { if(yrValid(s.substr(4), 2020, 2030)) tmp.insert(x); }
        else if(x == "hgt") { if(hgtValid(s.substr(4))) tmp.insert(x); } 
        else if(x == "hcl") { if(hclValid(s.substr(4))) tmp.insert(x); }
        else if(x == "ecl") { if(eclValid(s.substr(4))) tmp.insert(x); }
        else if(x == "pid") { if(pidValid(s.substr(4))) tmp.insert(x); }
    }
    bool tot = 1;
    for(auto & i : dic) {
        tot &= tmp.count(i);
    }
    return tot;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ans = 0;
    string s, line;
    while(getline(cin, line)) {
        if(line.empty()) {
            if(passValid(s)) ans++;
            s.clear();
        } else s += (s.empty() ? "" : " ") + line;
    }
    if(passValid(s)) ans++;
    cout << ans << endl;
    return 0; 
}
