/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once

#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>
#include <chrono>
#include "LCS.h"

using namespace std;

class Benchmarker
{
protected:
	int getRandomBase(const int);
	vector<int> generateVector(const int, const int);

public:
	Benchmarker();
	string start(int, int, int, vector<LCS*>);
};
