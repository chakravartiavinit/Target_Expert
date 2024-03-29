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
        for (int i = 0; i < n; ++i)
        {
            cin >> vt[i];
        }
        vector<int> set_bits(30, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 30; ++j)
            {
                if (vt[i] & (1 << j))
                {
                    set_bits[j]++;
                }
            }
        }
        map<int, int> mp;
        set<int> answer;
        answer.insert(1);
        for (int i = 0; i < 30; ++i)
        {
            mp[set_bits[i]]++;
        }
        if (mp.size() == 1 && mp.begin()->first == 0)
        {
            for (int i = 1; i <= n; ++i)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            vector<int> temp;
            for (auto x : mp)
            {
                if (x.first != 0)
                {
                    temp.push_back(x.first);
                }
            }
            int temp1 = temp[0];
            for (int i = 1; i < temp.size(); ++i)
            {
                temp1 = gcd(temp1, temp[i]);
            }
            for (int i = 1; i <= sqrt(temp1); ++i)
            {
                if (temp1 % i == 0)
                {
                    answer.insert(i);
                    answer.insert(temp1 / i);
                }
            }
            for (auto x : answer)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}