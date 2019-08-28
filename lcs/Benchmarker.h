/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once

#include <cstdlib>
#include <vector>

using namespace std;

class Benchmarker
{
protected:
	int getRandomBase(const int);
	
public:
	vector<int> generateVector(const int, const int);
};
