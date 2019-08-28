/**
 * @author: Ha Nhat Nam
 * @organization: Fontys University
 * @email: nhnam2k1@gmail.com
 *
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

vector<int> Matchlist[256];
int L[1000005] ={0};
bool ch[256] = {0};

void buildMatchList()
{
	for (i = 0; i < a.size(); ++i)
	{
		idx = int(a[i]);
		if (Matchlist[idx].empty())
		{
			for (j = n - 1; j >= 0; --j) {
				if (a[i] == b[j])
				{
					Matchlist[idx].push_back(j);
				}
			}
		}
	}
}

int process(const vector<int>& a, const vector<int>& b)
{
    int k, high, low, mid;
    int m,n,idx;
    m = a.size(); n = b.size();
	for (int i = 0; i < 1000005; ++i)
	{
		L[i] = -1;
	}

    int si, LCS = 0;
    for (int i = 0; i < a.size(); ++i)
	{
        idx = a[i];
        si = Matchlist[idx].size(); 
		ch[idx] = 1;
        for (int j = 0; j < si; ++j)
		{
            if (Matchlist[idx][j] > L[LCS])
			{
                ++LCS;
                L[LCS] = Matchlist[idx][j];
                continue;
            }
            low = 0; high = LCS; k = 0;
            while (true)
			{
                mid = (low+high) >> 1;
                if (L[mid] == Matchlist[idx][j])
				{
                    k = 1; 
					break;
                }

                if (high - low <= 1)
				{
                    mid = high;  
					break;
                }

				if (L[mid] > Matchlist[idx][j])
				{
					high = mid;
				}
				else if (L[mid] < Matchlist[idx][j])
				{
					low = mid;
				}
            }

			if (k == 0)
			{
				L[mid] = Matchlist[idx][j];
			}
        }
    }

    return LCS;
}

int run(const vector<int>& a, const vector<int>& b)
{
    return HuntSzymanski(a,b);
}
