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
        if (vt[0][0] == '1')
        {
            cout << "-1\n";
        }
        else
        {
            vector<vector<int>> answer;
            vector<string> visited = vt;
            for (int i = 0; i < n; ++i)
            {
                for (int j = m - 1; j >= 0; --j)
                {
                    if (visited[i][j] == '1')
                    {
                        int start = j;
                        while (start >= 1 && vt[i][start] == '1')
                        {
                            answer.push_back({i, start - 1, i, start});
                            visited[i][start] = '#';
                            start--;
                        }
                    }
                }
            }
            for (int i = 0; i < m; ++i)
            {
                for (int j = n - 1; j >= 0; --j)
                {
                    if (visited[j][i] == '1')
                    {
                        int start = j;
                        while (start >= 1 && vt[start][i] == '1')
                        {
                            answer.push_back({start - 1, i, start, i});
                            visited[start][i] = '#';
                            start--;
                        }
                    }
                }
            }
            cout << answer.size() << "\n";
            for (auto x : answer)
            {
                for (auto y : x)
                {
                    cout << y + 1 << " ";
                }
                cout << "\n";
            }
        }
    }
}