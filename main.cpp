/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#include <string>
#include "LCS.h"
#include "Benchmarker.h"
#include "Hirschberg.h"
#include "HuntSzymanski.h"
#include "MyAlgorithm01.h"
#include "MyAlgorithm02.h"
#include <fstream>

int main(int argc, char *argv[]) 
{
	int len  = stoi(argv[1]);
	int loop = stoi(argv[2]);
	int base = stoi(argv[3]);
	string file = argv[4];

	Benchmarker ben;
	vector<LCS*> algos;
	algos.push_back(new Hirschberg());
	algos.push_back(new HuntSzymanski());
	algos.push_back(new MyAlgorithm01());
	algos.push_back(new MyAlgorithm02());

	string data = ben.start(len, base, loop, algos);

	ofstream writer;
	writer.open(file);
	writer << data;
	writer.close();

	for (auto algo : algos)
	{
		delete algo;
	}
}