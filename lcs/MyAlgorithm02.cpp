/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */
/**
 * @author: Le Nho Thanh
 * @organization: University of Technology Sydney
 * @email: lenhothanh.nsl@gmail.com
 */
#include "MyAlgorithm02.h"

void MyAlgorithm02::buildMatchList(const vector<int> &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        this->matchList[b[i]].insert(i);
    }
}

void MyAlgorithm02::buildThreshold(const vector<int> &a, const vector<int> &b)
{
    map<int, set<int>::reverse_iterator> flag;
    stack<pair<int, int> > t;

    int oo = numeric_limits<int>::max();
    t.push(make_pair(oo, oo));
    this->threshold.resize(a.size(), 0);

    
    for (auto const& [key, val] : this->matchList)
    {
        if (!val.empty()){
            flag[key] = val.rbegin();
        }
    }
	
    for (int i = a.size() - 1; i >= 0; --i)
    {
        if (!this->matchList[a[i]].empty())
        {
            while (t.top().second < (*flag[a[i]]))
            {
                --flag[t.top().first];
                t.pop();
            }

            this->threshold[i] = (*flag[a[i]]);
            t.push(make_pair(a[i], this->threshold[i]));
			++flag[a[i]];
        }
    }
}

void MyAlgorithm02::process(const vector<int> &a, const vector<int> &b)
{
    set<int>::iterator itMatch;
    set<int>::iterator itTrack;
    int idMatch, idTrack;
 
    for (int i = 0; i < a.size(); ++i)
    {
        itMatch = this->matchList[a[i]].begin();
        while (itMatch != this->matchList[a[i]].end())
        {
            idMatch = *itMatch;
            if (idMatch > this->threshold[i]) 
            {
                break;
            }

            this->matchList[a[i]].erase(itMatch);
            track.insert(idMatch);
 
            itTrack = this->track.upper_bound(idMatch);
            if (itTrack == track.end())
            {
                break;
            }
 
            idTrack = *itTrack;
            this->track.erase(itTrack);
            this->matchList[b[idTrack]].insert(idTrack);
            itMatch = this->matchList[a[i]].upper_bound(idTrack);
        }
    }
}
 
void MyAlgorithm02::reset()
{
	this->matchList.clear();
	this->threshold.clear();
	this->track.clear();
}

int MyAlgorithm02::run(const vector<int> &a, const vector<int> &b)
{
    this->buildMatchList(b);
    this->buildThreshold(a, b);
    this->process(a, b);
 
    return this->track.size();
}

string MyAlgorithm02::getName()
{
	return "MyAlgorithm02";
}
