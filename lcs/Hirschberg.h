/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once
#include "LCS.h"

class Hirschberg : public LCS
{
protected:
	vector<vector<int> > matrix;
	void init(int);
	int process(const vector<int>&, const vector<int>&);

public:
	void reset();
	int run(const vector<int>&, const vector<int>&);
	string getName();
};
