/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once
#include "LCS.h"

class HuntSzymanski : public LCS
{
protected:
	map<int, set<int> > matchList;
	set<int> track;

	void buildMatchList(const vector<int>&);
	void process(const vector<int>&, const vector<int>&);

public:
	void reset();
	int run(const vector<int>&, const vector<int>&);
	string getName();
};
