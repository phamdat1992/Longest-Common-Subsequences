/**
 * @author: Pham Huu Thanh Dat
 * @organization: ZALORA
 * @email: dat.pham@zalora.com
 */

#pragma once
#include <LCS.h>

class MyAlgorithm01 : LCS
{
    protected:
        map<int, set<int> > matchList;
        set<int> track;

        void buildMatchList(const vector &);
        void process(const vector &, const vector &);
    public:
        int run(const vector &, const vector &);
}