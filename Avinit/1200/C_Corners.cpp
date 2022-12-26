#include <iostream>
#include <vector>
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
bool check(char a, char b, char c, char d)
{
    int count = 0;
    if (a == '0')
    {
        count++;
    }
    if (b == '0')
    {
        count++;
    }
    if (c == '0')
    {
        count++;
    }
    if (d == '0')
    {
        count++;
    }
    return count >= 2;
}
bool Operation(vector<string> &vt, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vt[i][j] == '0' && vt[i + 1][j] == '0')
            {
                return true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (vt[i][j] == '0' && vt[i][j + 1] == '0')
            {
                return true;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (check(vt[i][j], vt[i][j + 1], vt[i + 1][j], vt[i + 1][j + 1]))
            {
                return true;
            }
        }
    }
    return false;
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
        int n, m;
        cin >> n >> m;
        vector<string> vt(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> vt[i];
        }
        int total_ones = 0, total_zeros = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (vt[i][j] == '1')
                {
                    total_ones++;
                }
                else
                {
                    total_zeros++;
                }
            }
        }
        if (total_ones == 0)
        {
            cout << "0\n";
        }
        else if (Operation(vt, n, m) == true)
        {
            cout << total_ones << "\n";
        }
        else if (total_zeros > 0)
        {
            cout << total_ones - 1 << "\n";
        }
        else
        {
            cout << total_ones - 2 << "\n";
        }
    }
}