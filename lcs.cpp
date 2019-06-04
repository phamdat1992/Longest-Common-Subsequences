/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 *
 * @author: Duong Thanh Hien
 * @organization: Lam Son High School for the Gifted
 * @email: hienjeony@gmail.com
 */

#include <bits/stdc++.h>
 
using namespace std;
 
map<int, set<int> > matchList;
set<int> track;
vector<int> a, b;
 
void input()
{
    int n, m;
    cin>>n>>m;
 
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < a.size(); ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < b.size(); ++i)
    {
        cin>>b[i];
    }
}
 
void buildMatchList()
{
    for (int i = 0; i < b.size(); ++i)
    {
        matchList[b[i]].insert(i);
    }
}
 
void process()
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
 
int main()
{
    input();
    buildMatchList();
    process();
 
    cout<<track.size();
}
