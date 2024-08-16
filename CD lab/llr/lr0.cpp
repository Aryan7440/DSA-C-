#include <bits/stdc++.h>
using namespace std;
vector<pair<char, string>> p;
vector<char> nt;
vector<char> term, u;
map<char, int> m;
char table[20][20];
vector<char> tt[20][20];
int tab[20][20];
// check if given is a non terminal
bool is_nonterm(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// find index of given non terminal in vector
int findnt(char c)
{
    for (int i = 0; i < nt.size(); i++)
    {
        if (nt[i] == c)
        {
            return i;
        }
    }
}
vector<char> v, first, taken;
queue<char> Q;
//
void findnext()
{
    while (!Q.empty())
    {
        char c = Q.front();
        Q.pop();
        if (is_nonterm(c))
        {
            for (int i = 0; i < p.size(); i++)
            {
                if (p[i].first == c)
                {
                    if (find(v.begin(), v.end(), p[i].second[0]) == v.end())
                    {
                        v.push_back(p[i].second[0]);
                        Q.push(p[i].second[0]);
                    }
                }
            }
        }
        else
        {
            if (find(v.begin(), v.end(), c) == v.end())
            {
                v.push_back(c);
            }
        }
    }
}
// find last for each variable
void findlast()
{
    while (!Q.empty())
    {
        char c = Q.front();
        Q.pop();
        if (is_nonterm(c))
        {
            for (int i = 0; i < p.size(); i++)
            {
                if (p[i].first == c)
                {
                    int len = p[i].second.size();
                    if (find(v.begin(), v.end(), p[i].second[len - 1]) == v.end())
                    {
                        v.push_back(p[i].second[len - 1]);
                        Q.push(p[i].second[len - 1]);
                    }
                }
            }
        }
        else
        {
            if (find(v.begin(), v.end(), c) == v.end())
            {
                v.push_back(c);
            }
        }
    }
}
// calculate first for each variable
void findfirst()
{
    while (!Q.empty())
    {
        char c = Q.front();
        Q.pop();
        if (is_nonterm(c) &&
            find(taken.begin(), taken.end(), c) == taken.end())
        {
            taken.push_back(c);
            for (int i = 0; i < p.size(); i++)
            {
                if (p[i].first == c)

                {
                    int len = p[i].second.size();
                    if (!is_nonterm(p[i].second[0]))
                    {
                        if (find(first.begin(), first.end(), p[i].second[0]) == first.end())
                        {
                            first.push_back(p[i].second[0]);
                        }
                    }
                    else
                    {
                        if (
                            find(taken.begin(), taken.end(), p[i].second[0]) == taken.end())
                        {
                            Q.push(p[i].second[0]);
                        }
                    }
                }
            }
        }
    }
}
void print(stack<char> s1)
{
    if (!s1.empty())
    {
        char c = s1.top();
        s1.pop();
        print(s1);
        cout << c;
    }
}
int find_handle(vector<char> s)
{
    int k = -1;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].second.size() == s.size())
        {
            int flag = 1;
            for (int j = 0; j < p[i].second.size(); j++)
            {
                if (s[j] != p[i].second[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                k = i;
                return k;
            }
        }
    }
}
// parse given string using generated table
void parsing(string input)
{
    stack<char> s;
    int cur = 0;
    s.push('$');
    while (1)
    {
        int fl = 0;
        print(s);
        for (int k = 0; k < 20 - (input.size() - cur) -
                                s.size();
             k++)
        {
            cout << " ";
        }
        for (int k = cur; k < input.size(); k++)
        {
            cout << input[k];
        }
        cout << "\n";
        if (s.size() == 2 && s.top() == u[0] && cur == input.size() - 1)
        {
            break;
        }
        while (1)
        {
            if (table[m[s.top()]][m[input[cur]]] == '<' ||
                table[m[s.top()]][m[input[cur]]] == '=')
            {
                s.push(input[cur]);
                cur++;
                fl = 1;
            }
            else if (table[m[s.top()]][m[input[cur]]] == '>')
            {
                break;
            }
            else if (table[m[s.top()]][m[input[cur]]] == ' ')
            {
                cout << "No\n";
                exit(0);
            }
        }
        if (fl)
        {
            print(s);
            for (int k = 0; k < 20 - (input.size() - cur) -
                                    s.size();
                 k++)
            {
                cout << " ";
            }
            for (int k = cur; k < input.size(); k++)
            {
                cout << input[k];
            }
            cout << endl;
        }
        vector<char> handle;
        char x;
        x = s.top();
        s.pop();
        handle.push_back(x);
        while (1)
        {
            if (table[m[s.top()]][m[x]] == '=')
            {
                x = s.top();
                s.pop();
                handle.push_back(x);
            }
            else if (table[m[s.top()]][m[x]] == '<')
            {
                break;
            }
            else if (table[m[s.top()]][m[x]] == ' ')
            {
                cout << "No\n";
                exit(0);
            }
        }
        reverse(handle.begin(), handle.end());
        // for(int j=0;j<handle.size();j++) { cout<<handle[j]; }
        // cout<<endl;
        int i = find_handle(handle);
        if (i == -1)
        {
            cout << "No\n";
            exit(0);
        }
        s.push(p[i].first);
    }
    cout << "yes\n";
}
int main()
{
    int n;
    char c;
    string s, str;
    memset(table, ' ', 400);
    cout << "\n Note : Productions will be entered as follows : S->AB |BC represents two productions \n ";
    cout << "and should be given one by one as S->AB and S->BC, where S will be the LHS part \n ";
    cout<< "and AB will be the RHS part and also A->a will have 'a' as its RHS \n\n ";
    cout<< "Enter the number of productions : \n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter LHS of production : ";
        cin >> c;
        cout << "enter RHS of production : ";
        cin >> s;
        p.push_back(make_pair(c, s));
    }
    int k = 0;
    cout << "Non terminals are : ";
    for (int i = 0; i < p.size(); i++)
    {
        int x = 1;
        if (find(nt.begin(), nt.end(), p[i].first) == nt.end())
        {
            cout << p[i].first << " ";
            u.push_back(p[i].first);
            nt.push_back(p[i].first);
            m[p[i].first] = k++;
        }
        for (int j = 0; j < p[i].second.size(); j++)
        {
            if (!is_nonterm(p[i].second[j]) &&
                find(term.begin(), term.end(), p[i].second[j]) == term.end())
            {
                term.push_back(p[i].second[j]);
            }
        }
    }
    // add $ to list of terminals as it denotes end of input
    term.push_back('$');
    cout << endl
         << "Terminals are : ";
    for (int i = 0; i < term.size(); i++)
    {
        cout << term[i] << " ";
        m[term[i]] = k++;
        u.push_back(term[i]);
    }
    cout << endl;
    for (int i = 0; i < p.size(); i++)
    {
        char x, y;
        for (int j = 0; j < p[i].second.size() - 1; j++)
        {
            x = p[i].second[j];
            y = p[i].second[j + 1];
            table[m[x]][m[y]] = '=';
            tt[m[x]][m[y]].push_back('=');
            if (is_nonterm(y))
            {
                v.clear();
                Q.push(y);
                findnext();
                for (int l = 0; l < v.size(); l++)
                {
                    char e1, e2;
                    e1 = x;
                    e2 = v[l];
                    table[m[e1]][m[e2]] = '<';
                    tt[m[e1]][m[e2]].push_back('<');
                }
            }
            if (is_nonterm(x))
            {
                v.clear();
                Q.push(x);
                findlast();
                first.clear();
                taken.clear();
                if (!is_nonterm(y))
                {
                    first.push_back(y);
                }
                else
                {
                    Q.push(y);
                    findfirst();
                }
                for (int d1 = 0; d1 < v.size(); d1++)
                {
                    for (int d2 = 0; d2 < first.size(); d2++)
                    {
                        char e1, e2;
                        e1 = v[d1];
                        e2 = first[d2];
                        table[m[e1]][m[e2]] = '>';
                        tt[m[e1]][m[e2]].push_back('>');
                    }
                }
            }
        }
        char start = p[0].first;
        v.clear();
        Q.push(start);
        findnext();
        for (int l = 0; l < v.size(); l++)
        {
            table[m['$']][m[v[l]]] = '<';
            tt[m['$']][m[v[l]]].push_back('<');
        }
        v.clear();
        Q.push(start);
        findlast();
        for (int l = 0; l < v.size(); l++)
        {
            table[m[v[l]]][m['$']] = '>';
            tt[m[v[l]]][m['$']].push_back('>');
        }
    }
    // New table
    int correct = 1;
    cout << "\n\n ";
    for (int i = 0; i < nt.size(); i++)
    {
        cout << nt[i] << " ";
    }
    for (int i = 0; i < term.size(); i++)
    {
        cout << term[i] << " ";
    }
    cout << endl
         << endl;
    for (int i = 0; i < k; i++)
    {
        cout << u[i] << " ";
        for (int j = 0; j < k; j++)
        {
            int cnn = 0;
            if (tt[i][j].size() == 0)
            {
                cout << " ";
            }
            for (int u = 0; u < tt[i][j].size(); u++)
            {
                int fff = 1;
                for (int h = 0; h < u; h++)
                {
                    if (tt[i][j][u] == tt[i][j][h])
                    {
                        fff = 0;
                        break;
                    }
                }
                if (fff)
                {
                    cnn++;
                    cout << tt[i][j][u];
                }
                if (cnn > 1)
                {
                    correct = 0;
                }
            }
            cout << " ";
        }
        cout << endl;
    }
    if (correct == 0)
    {
        cout << "\nNot Simple precedence grammar\n";
        exit(0);
    }
    // New Table end
    string input;
    cout << "\n\nEnter input string : ";
    cin >> input;
    parsing(input);
    return 0;
}
