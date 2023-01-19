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
        int n;
        cin >> n;
        vector<int> vt(n);
        bool possible = true;
        set<int> st;
        for (int i = 0; i < n; ++i)
        {
            cin >> vt[i];
            st.insert(vt[i]);
        }
        sort(vt.rbegin(), vt.rend());
        int a = vt[0], b = vt[1], c = vt[2];
        if (st.find((a + b + c)) == st.end())
        {
            possible = false;
        }
        for (int i = 3; i < n; ++i)
        {
            int current = a + b + vt[i];
            if (st.find(current) == st.end())
            {
                possible = false;
                break;
            }
        }
        for (int i = 3; i < n; ++i)
        {
            if (i == 2)
            {
                continue;
            }
            else
            {
                int current = a + c + vt[i];
                if (st.find(current) == st.end())
                {
                    possible = false;
                    break;
                }
            }
        }
        sort(vt.begin(), vt.end());
        a = vt[0], b = vt[1], c = vt[2];
        if (st.find((a + b + c)) == st.end())
        {
            possible = false;
        }
        for (int i = 3; i < n; ++i)
        {
            int current = a + b + vt[i];
            if (st.find(current) == st.end())
            {
                possible = false;
                break;
            }
        }
        for (int i = 3; i < n; ++i)
        {
            if (i == 2)
            {
                continue;
            }
            else
            {
                int current = a + c + vt[i];
                if (st.find(current) == st.end())
                {
                    possible = false;
                    break;
                }
            }
        }
        possible == true ? cout << "YES\n" : cout << "NO\n";
    }
}