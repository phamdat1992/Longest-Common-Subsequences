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
 
void buildMatchList(const vector<int> &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        matchList[b[i]].insert(i);
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
    process(a, b);
 
    return track.size();
}
