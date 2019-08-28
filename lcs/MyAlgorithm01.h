/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once
#include "LCS.h"

class MyAlgorithm01 : LCS
{
protected:
	map<int, set<int> > matchList;
	set<int> track;

	void buildMatchList(const vector<int>&);
	void process(const vector<int>&, const vector<int>&);
public:
	int run(const vector<int>&, const vector<int>&);
};
