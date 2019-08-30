/**
 * @author: Ha Nhat Nam
 * @organization: Fontys University
 * @email: nhnam2k1@gmail.com
 *
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#include "Hirschberg.h"

int Hirschberg::process(const vector<int>& a, const vector<int>& b)
{
	int last = 1, now = 0;
    for (int i = 0; i < a.size(); ++i)
	{
        swap(last, now);
		for (int j = 0; j < b.size(); ++j)
		{
			this->matrix[now][j] = j ? this->matrix[now][j - 1] : 0;
			if (a[i] == b[j])
			{
				int tmp = j ? this->matrix[last][j - 1] : 0;
				this->matrix[now][j] = max(this->matrix[now][j], tmp + 1);
			}
			else
			{
				this->matrix[now][j] = max(this->matrix[last][j], this->matrix[now][j]);
			}
		}
    }

	return this->matrix[now][b.size() - 1];
}

void Hirschberg::init(int len)
{
	this->matrix.resize(2);
	this->matrix[0].resize(len);
	this->matrix[1].resize(len);

	for (int i = 0; i < len; ++i)
	{
		this->matrix[0][i] = this->matrix[1][i] = 0;
	}
}

void Hirschberg::reset()
{
	this->matrix.clear();
}

int Hirschberg::run(const vector<int>& a, const vector<int>& b)
{
	this->init(b.size());
    return process(a, b);
}

string Hirschberg::getName()
{
	return "Hirschberg";
}