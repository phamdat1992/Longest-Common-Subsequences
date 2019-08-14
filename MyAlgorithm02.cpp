/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 *
 * @author: Duong Thanh Hien
 * @organization: Lam Son High School for the Gifted
 * @email: hienjeony@gmail.com
 */

#include <MyAlgorithm01.h>
 
using namespace std;
 
void buildMatchList(const vector &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        matchList[b[i]].insert(i);
    }
}

void buildReservedFlag(const vector &a, const vector &b)
{
    set<int>::iterator itMatch;
    stack<pair<int, int>> t;
    int valueMatch;

    idx.resize(a.size(), 0);
    for (int i = 0; i < a.size)
    {
        while (!t.empty() && t.top()->second < (*matchList[a[i]].rbegin())) {
            matchList[a[t.top()->first]].push_back(t.top()->second);
            t.pop();
        }

        itMatch = matchList[a[i]].rbegin();
        valueMatch = *itMatch;
        if (!t.empty() && t.top()->second > valueMatch) {
            idx[i] = valueMatch;
            matchList[a[i]].erase(itMatch);
            stack.push(new pair(i, valueMatch));
        }
    }
}

void process(const vector &a, const vector &b)
{
    set<int>::iterator itMatch;
    set<int>::iterator itTrack;
    int idMatch, idTrack;
 
    for (int i = 0; i < a.size(); ++i)
    {
        if (idx[i] != 0) {
            matchList[a[i]].insert(idx[i]);
        }
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
 
int run(const vector &a, const vector &b)
{
    buildMatchList(b);
    process(a, b);
 
    return track.size();
}
