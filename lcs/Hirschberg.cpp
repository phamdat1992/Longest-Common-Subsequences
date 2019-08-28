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
	int maxSize = max(a.size(), b.size());
	matrix[0].reserve(maxSize);
	matrix[1].reserve(maxSize);

	int last = 1, now = 0;
    for (int i = 1; i <= a.size(); ++i)
	{
        swap(last, now);
		for (int j = 1; j <= b.size(); ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				matrix[now][j] = matrix[last][j - 1] + 1;
			}
			else if (matrix[now][j - 1] > matrix[last][j]) 
			{
				matrix[now][j] = matrix[now][j - 1];
			}
			else
			{
				matrix[now][j] = matrix[last][j];
			}
		}
    }

	int ans = 0;
    for (int i = 1; i <= maxSize; ++i)
	{
        ans = max(ans, matrix[0][i]);
        ans = max(ans, matrix[1][i]);
    }

    return ans;
}

int Hirschberg::run(const vector<int>& a, const vector<int>& b)
{
    return process(a, b);
}
