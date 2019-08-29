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
	vector<vector<int> > matrix(2);
	matrix[0].reserve(b.size());
	matrix[1].reserve(b.size());

	int last = 1, now = 0;
    for (int i = 0; i < a.size(); ++i)
	{
        swap(last, now);
		for (int j = 0; j < b.size(); ++j)
		{
			matrix[now][j] = j ? matrix[now][j - 1] : 0;
			if (a[i] == b[j])
			{
				int tmp = j ? matrix[last][j - 1] : 0;
				matrix[now][j] = max(matrix[now][j], tmp + 1);
			}
			else
			{
				matrix[now][j] = max(matrix[last][j], matrix[now][j]);
			}
		}
    }

	return matrix[now][b.size() - 1];
}

int Hirschberg::run(const vector<int>& a, const vector<int>& b)
{
    return process(a, b);
}
