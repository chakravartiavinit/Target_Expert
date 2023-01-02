#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <iomanip>
using namespace std;

//  ████████  ██████      ████████ ██   ██ ███████     ████████  ██████  ██████
//     ██    ██    ██        ██    ██   ██ ██             ██    ██    ██ ██   ██
//     ██    ██    ██        ██    ███████ █████          ██    ██    ██ ██████
//     ██    ██    ██        ██    ██   ██ ██             ██    ██    ██ ██
//     ██     ██████         ██    ██   ██ ███████        ██     ██████  ██
//
//
#define MOD 1000000007
#define PI 3.141592653589793238462
#define int long long

/*########################################### DEBUG ###############################################################################################*/
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*###############################################################################################################################################*/
bool Done(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d, vector<string> &vt)
{
    if (vt[a.first][a.second] == '#' && vt[b.first][b.second] == '#' && vt[c.first][c.second] == '#' && vt[d.first][d.second] == '#')
    {
        return true;
    }
    return false;
}
int Calc(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d, vector<string> &vt)
{
    int answer = 0;
    if (vt[a.first][a.second] == '1')
    {
        answer++;
    }
    if (vt[b.first][b.second] == '1')
    {
        answer++;
    }
    if (vt[c.first][c.second] == '1')
    {
        answer++;
    }
    if (vt[d.first][d.second] == '1')
    {
        answer++;
    }
    return answer;
}
bool check_ind(pair<int, int> &a, int n)
{
    if (a.first < 0 || a.second < 0 || a.first >= n || a.second >= n)
    {
        return false;
    }
    return true;
}
bool check(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d, int n)
{
    if (check_ind(a, n) == false || check_ind(b, n) == false || check_ind(c, n) == false || check_ind(d, n) == false)
    {
        return false;
    }
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> vt(n);
        int one = 0, zero = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> vt[i];
            for (auto x : vt[i])
            {
                if (x == '0')
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
        }
        if (one == 0 || zero == 0)
        {
            cout << "0\n";
        }
        else
        {
            int total_operation = 0;
            pair<int, int> a = {0, 0};
            pair<int, int> b = {0, n - 1};
            pair<int, int> c = {n - 1, 0};
            pair<int, int> d = {n - 1, n - 1};
            pair<int, int> a_temp = a;
            pair<int, int> b_temp = b;
            pair<int, int> c_temp = c;
            pair<int, int> d_temp = d;
            int total = n * n;
            while (total >= 0 && check(a, b, c, d,n) == true)
            {
                if (Done(a, b, c, d, vt) == true)
                {
                    a_temp.first += 1;
                    a_temp.second += 1;
                    b_temp.first += 1;
                    b_temp.second -= 1;
                    c_temp.first -= 1;
                    c_temp.second += 1;
                    d_temp.first -= 1;
                    d_temp.second -= 1;
                    a = a_temp;
                    b = b_temp;
                    c = c_temp;
                    d = d_temp;
                }
                else
                {
                    int temp = Calc(a, b, c, d, vt);
                    total_operation += min(temp, 4 - temp);
                    vt[a.first][a.second] = '#';
                    vt[b.first][b.second] = '#';
                    vt[c.first][c.second] = '#';
                    vt[d.first][d.second] = '#';
                    a.second += 1;
                    b.first += 1;
                    c.first -= 1;
                    d.second -= 1;
                    total -= 4;
                }
            }
            // debug(vt);
            cout << total_operation << "\n";
        }
    }
}