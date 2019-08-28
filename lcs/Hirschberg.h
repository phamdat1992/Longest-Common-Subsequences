/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once
#include "LCS.h"

class Hirschberg : LCS
{
protected:
	int process(const vector<int>&, const vector<int>&);
public:
	int run(const vector<int>&, const vector<int>&);
};
