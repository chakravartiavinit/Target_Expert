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
int Answer(string &alpha)
{
    int answer = 10;
    int first = 0, second = 0, count_first = 0, count_second = 0;
    for (int i = 0; i < 10; ++i)
    {
        if ((i + 1) % 2 == 1)
        {
            first += (alpha[i] - '0');
            count_first++;
        }
        else
        {
            second += (alpha[i] - '0');
            count_second++;
        }
        if (max(first, second) == first)
        {
            if (first > second + 5 - count_second)
            {
                answer = i + 1;
                break;
            }
        }
        else
        {
            if (second > first + 5 - count_first)
            {
                answer = i + 1;
                break;
            }
        }
    }
    return answer;
}
int Generate(int index, string &alpha, vector<int> &vt)
{
    if (index == 10 || index == vt.size())
    {
        int answer1 = Answer(alpha);
        return answer1;
    }
    int answer;
    alpha[vt[index]] = '1';
    answer = Generate(index + 1, alpha, vt);
    alpha[vt[index]] = '0';
    answer = min(answer, Generate(index + 1, alpha, vt));
    alpha[vt[index]] = '?';
    return answer;
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
        string alpha;
        cin >> alpha;
        vector<int> not_found_pos;
        for (int i = 0; i < 10; ++i)
        {
            if (alpha[i] == '?')
            {
                not_found_pos.push_back(i);
            }
        }
        cout << Generate(0, alpha, not_found_pos) << "\n";
    }
}