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
bool Inc(vector<int> &vt)
{
    for (int i = 0; i + 1 < vt.size(); ++i)
    {
        if (vt[i] > vt[i + 1])
        {
            return false;
        }
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
        vector<int> vt(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> vt[i];
        }
        bool dec = true;
        for (int i = 0; i + 1 < n; ++i)
        {
            if (vt[i] > vt[i + 1])
            {
                dec = false;
                break;
            }
        }
        if (dec == true)
        {
            cout << "0\n";
        }
        else
        {
            vector<int> vt1 = vt;
            vector<vector<int>> answer, answer1;
            for (int i = n - 4; i >= 0; --i)
            {
                vt[i] = vt[i + 1] - vt[n - 1];
                answer.push_back({i + 1, i + 2, n});
            }
            int gamma = vt1[n - 2] - vt1[n - 1];
            for (int i = n - 3; i >= 0; --i)
            {
                vt1[i] = vt1[i + 1] - vt1[n - 1];
                answer1.push_back({i + 1, i + 2, n});
            }
            if (Inc(vt) == true)
            {
                cout << answer.size() << "\n";
                for (auto x : answer)
                {
                    for (auto y : x)
                    {
                        cout << y << " ";
                    }
                    cout << "\n";
                }
            }
            else if (Inc(vt1) == true)
            {
                cout << answer1.size() << "\n";
                for (auto x : answer1)
                {
                    for (auto y : x)
                    {
                        cout << y << " ";
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}
