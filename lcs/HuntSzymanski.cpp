/**
 * @author: Ha Nhat Nam
 * @organization: Fontys University
 * @email: nhnam2k1@gmail.com
 *
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#include "HuntSzymanski.h"

void HuntSzymanski::buildMatchList(const vector<int>& b)
{
	for (int i = 0; i < b.size(); ++i)
	{
		this->matchList[b[i]].insert(i);
	}
}

void HuntSzymanski::process(const vector<int>& a, const vector<int>& b)
{
	set<int>::reverse_iterator itMatch;
	set<int>::iterator itTrack;
	int idMatch;

	for (int ai : a)
	{
		for (itMatch = matchList[ai].rbegin(); itMatch != matchList[ai].rend(); ++itMatch)
		{
			idMatch = (*itMatch);
			if (this->track.insert(idMatch).second)
			{
				itTrack = this->track.upper_bound(idMatch);
				if (itTrack != this->track.end())
				{
					this->track.erase(itTrack);
				}
			}
		}
	}
}

void HuntSzymanski::reset()
{
	this->matchList.clear();
	this->track.clear();
}

int HuntSzymanski::run(const vector<int>& a, const vector<int>& b)
{
	this->buildMatchList(b);
    this->process(a, b);

	return this->track.size();
}

string HuntSzymanski::getName()
{
	return "HuntSzymanski";
}
