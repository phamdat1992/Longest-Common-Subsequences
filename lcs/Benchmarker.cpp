/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 *
 * @author: Nguyen Kieu Trang
 * @organization: 
 * @email: 
 */

#include "Benchmarker.h"

int Benchmarker::getRandomBase(const int base)
{
	return rand() % base;
}

vector<int> Benchmarker::generateVector(const int len, const int base)
{
	vector<int> data(len);
	for (int i = 0; i < data.size(); ++i)
	{
		data[i] = this->getRandomBase(base);
	}

	return data;
}
