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
float sqrtBinarySearch(int num, int p)
{
    int left = 0, right = num;
    int mid;
    float res;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (mid * mid == num)
        {
            res = mid;
            break;
        }
        if (mid * mid < num)
        {
            left = mid + 1;
            res = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    float incr = 0.1;
    for (int i = 0; i < p; i++)
    {
        while (res * res <= num)
        {
            res += incr;
        }
        res -= incr;
        incr /= 10;
    }
    return res;
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
        vector<int> miners, diamond_mines;
        for (int i = 0; i < 2 * n; ++i)
        {
            int a, b;
            cin >> a >> b;
            if (a == 0)
            {
                miners.push_back(abs(b));
            }
            else
            {
                diamond_mines.push_back(abs(a));
            }
        }
        double answer = 0, answer1 = 0;
        vector<int> temp, temp1;
        sort(miners.begin(), miners.end());
        sort(diamond_mines.begin(), diamond_mines.end());
        for (int i = 0; i < n; ++i)
        {
            answer += sqrt(1.0 * miners[i] * miners[i] + 1.0 * diamond_mines[i] * diamond_mines[i]);
        }
        cout << fixed << setprecision(15) << answer << "\n";
    }
}