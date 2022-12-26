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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    int sum = 0;
    vector<int> vt(n);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> vt[i];
        sum += vt[i];
        mp[i] = {vt[i], 0};
    }
    pair<int, int> temp = {-100, -100};
    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index, number;
            cin >> index >> number;
            if (mp[index - 1].second > temp.second)
            {
                sum = sum - mp[index - 1].first + number;
            }
            else
            {
                sum = sum - temp.first + number;
            }
            mp[index - 1] = {number, i + 1};
        }
        else
        {
            int number;
            cin >> number;
            sum = n * number;
            temp = {number, i + 1};
        }
        cout << sum << "\n";
    }
}