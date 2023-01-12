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
    int n;
    cin >> n;
    vector<int> vt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vt[i];
    }
    if (n <= 2)
    {
        cout << "0\n";
    }
    else if (n == 3)
    {
        cout << "2\n";
    }
    else
    {
        vector<int> temp(n);
        int answer = 1e16;
        temp[0] = 0;
        temp[1] = vt[1];
        int operation = 1, times;
        for (int i = 2; i < n; ++i)
        {
            times = (temp[i - 1] / vt[i]) + 1;
            temp[i] = vt[i] * times;
            operation += times;
        }
        answer = min(answer, operation);
        temp[n - 1] = 0;
        temp[n - 2] = -1 * vt[n - 2];
        operation = 1;
        for (int i = n - 3; i >= 0; --i)
        {
            times = (abs(temp[i + 1]) / vt[i]) + 1;
            temp[i] = vt[i] * times * -1;
            operation += times;
        }
        answer = min(answer, operation);
        for (int i = 1; i < n - 1; ++i)
        {
            int f = i + 2;
            int b = i - 2;
            temp[i] = 0;
            temp[i + 1] = vt[i + 1];
            temp[i - 1] = -1 * vt[i - 1];
            operation = 2;
            while (f < n)
            {
                times = (temp[f - 1] / vt[f]) + 1;
                temp[f] = vt[f] * times;
                operation += times;
                f++;
            }
            while (b >= 0)
            {
                times = (abs(temp[b + 1]) / vt[b]) + 1;
                temp[b] = vt[b] * times * -1;
                operation += times;
                b--;
            }
            answer = min(answer, operation);
        }
        cout << answer << "\n";
    }
}