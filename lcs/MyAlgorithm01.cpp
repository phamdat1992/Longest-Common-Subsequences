/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 *
 * @author: Duong Thanh Hien
 * @organization: Lam Son High School for the Gifted
 * @email: hienjeony@gmail.com
 */

#include "MyAlgorithm01.h"
 
void MyAlgorithm01::buildMatchList(const vector<int> &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        this->matchList[b[i]].insert(i);
    }
}
 
void MyAlgorithm01::process(const vector<int> &a, const vector<int> &b)
{
    set<int>::iterator itMatch;
    set<int>::iterator itTrack;
    int idMatch, idTrack;
 
    for (int ai : a)
    {
        itMatch = this->matchList[ai].begin();
        while (itMatch != this->matchList[ai].end())
        {
            idMatch = *itMatch;
            this->matchList[ai].erase(itMatch);
            this->track.insert(idMatch);
 
            itTrack = this->track.upper_bound(idMatch);
            if (itTrack == this->track.end())
            {
                break;
            }
 
            idTrack = *itTrack;
            this->track.erase(itTrack);
            this->matchList[b[idTrack]].insert(idTrack);
            itMatch = this->matchList[ai].upper_bound(idTrack);
        }
    }
}
 
int MyAlgorithm01::run(const vector<int> &a, const vector<int> &b)
{
    this->buildMatchList(b);
    this->process(a, b);
 
    return this->track.size();
}
