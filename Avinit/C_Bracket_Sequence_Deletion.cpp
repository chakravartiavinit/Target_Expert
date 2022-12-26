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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string alpha;
        cin >> alpha;
        stack<char> st;
        int last_character_index = 0, number_of_operations = 0;
        vector<int> forward(n);
        int current = 0, first = 0;
        string gamma;
        for (int i = 0; i < n; ++i)
        {
            gamma += alpha[i];
            if (st.empty() == true)
            {
                st.push(alpha[i]);
            }
            else
            {
                if (st.top() == '(' && alpha[i] == ')')
                {
                    st.pop();
                }
                else
                {
                    st.push(alpha[i]);
                }
            }
            if ((st.empty() == true))
            {
                number_of_operations++;
                last_character_index = i;
                while (!st.empty())
                {
                    st.pop();
                }
                first = i + 1;
                gamma.clear();
            }
            else if (alpha[i] == alpha[first] && (i != first))
            {
                string delta = gamma;
                reverse(delta.begin(), delta.end());
                if (delta == gamma)
                {
                    gamma.clear();
                    number_of_operations++;
                    last_character_index = i;
                    while (!st.empty())
                    {
                        st.pop();
                    }
                    first = i + 1;
                }
            }
        }
        cout << number_of_operations << " ";
        if (last_character_index == 0)
        {
            cout << n - last_character_index << "\n";
        }
        else
        {
            cout << n - last_character_index - 1 << "\n";
        }
    }
}