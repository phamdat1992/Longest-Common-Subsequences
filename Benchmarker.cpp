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

Benchmarker::Benchmarker()
{
	srand(time(NULL));
}

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

string Benchmarker::start(int len, int base, int loop, vector<LCS*> algos)
{
	string result = "";
	for (int i = 0; i < loop; ++i)
	{
		cout << i << endl;
		vector<int> a = this->generateVector(len, base);
		vector<int> b = this->generateVector(len, base);

		for (LCS* algo : algos)
		{
			algo->reset();
			auto start = chrono::high_resolution_clock::now();
			int data = algo->run(a, b);
			auto end = chrono::high_resolution_clock::now();
			auto runningTime = (chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000) / 1000000.0f;
			result += to_string(data) + "," + to_string(runningTime) + ",";
			cout << algo->getName() << " " << runningTime << endl;
		}

		result += "\n";
	}

	return result;
}