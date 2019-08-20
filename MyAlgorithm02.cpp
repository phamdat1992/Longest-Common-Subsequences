/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

// #include <MyAlgorithm02.h>
#include <bits/stdc++.h>
using namespace std;

map<int, set<int> > matchList;
set<int> track;
vector<int> threshold;

void buildMatchList(const vector<int> &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        matchList[b[i]].insert(i);
    }
}

void buildThreshold(const vector<int> &a, const vector<int> &b)
{
    map<int, set<int>::reverse_iterator> flag;
    stack<pair<int, int> > t;

    int oo = numeric_limits<int>::max();
    t.push(make_pair(oo, oo));
    threshold.resize(a.size(), 0);

    for (int i = 0; i < b.size(); ++i) 
    {
        flag[b[i]] = matchList[b[i]].rbegin();
    }

    for (int i = a.size() - 1; i >= 0; --i)
    {
        if (flag[a[i]] != matchList[a[i]].rend())
        {
            while (t.top().second < (*flag[a[i]]))
            {
                --flag[t.top().first];
                t.pop();
            }

            threshold[i] = (*flag[a[i]]);
            t.push(make_pair(a[i], threshold[i]));
            ++flag[a[i]];
        }
    }
}

void process(const vector<int> &a, const vector<int> &b)
{
    set<int>::iterator itMatch;
    set<int>::iterator itTrack;
    int idMatch, idTrack;
 
    for (int i = 0; i < a.size(); ++i)
    {
        itMatch = matchList[a[i]].begin();
        while (itMatch != matchList[a[i]].end())
        {
            idMatch = *itMatch;
            if (idMatch > threshold[i]) 
            {
                break;
            }

            matchList[a[i]].erase(itMatch);
            track.insert(idMatch);
 
            itTrack = track.upper_bound(idMatch);
            if (itTrack == track.end())
            {
                break;
            }
 
            idTrack = *itTrack;
            track.erase(itTrack);
            matchList[b[idTrack]].insert(idTrack);
            itMatch = matchList[a[i]].upper_bound(idTrack);
        }
    }
}
 
int run(const vector<int> &a, const vector<int> &b)
{
    buildMatchList(b);
    buildThreshold(a, b);
    process(a, b);
 
    return track.size();
}

int main()
{
    vector<int> a, b;
    int n, m;
    cin>>n>>m;
    a.resize(n);
    b.resize(m);

    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin>>b[i];
    }

    cout<<run(a, b);
}