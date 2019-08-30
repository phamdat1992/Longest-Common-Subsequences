/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class LCS
{
    public:
    virtual int run(const vector<int> &, const vector<int> &) = 0;
	virtual void reset() = 0;
	virtual string getName() = 0;
};
