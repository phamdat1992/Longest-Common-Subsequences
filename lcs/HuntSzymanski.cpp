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
	set<int>::iterator itMatch;
	set<int>::iterator itTrack;
	int idMatch, idTrack;

	for (int i = 0; i < a.size(); ++i)
	{
		itMatch = this->matchList[a[i]].begin();
		while (itMatch != this->matchList[a[i]].end())
		{
			idMatch = *itMatch;
			int previousSize = this->track.size();
			this->track.insert(idMatch);

			if (this->track.size() != previousSize)
			{
				itTrack = this->track.upper_bound(idMatch);
				if (itTrack == this->track.end())
				{
					break;
				}

				idTrack = *itTrack;
				this->track.erase(itTrack);
			}
			itMatch = this->matchList[a[i]].upper_bound(idTrack);
		}
	}
}

int HuntSzymanski::run(const vector<int>& a, const vector<int>& b)
{
	this->buildMatchList(b);
    this->process(a, b);

	return this->track.size();
}
