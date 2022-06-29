//#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
	vector<pair<int, int> > vp;
	set<int> allset;

	int size, segmentx, segmenty;

	cin >> size;

	while(size--)
	{
		cin >> segmentx >> segmenty;
		vp.push_back({segmentx, segmenty});
		allset.insert(segmentx);
		allset.insert(segmenty);
	}

	for(auto v: vp)
	{
		auto lower  = allset.lower_bound(v.first);
		auto upper = allset.upper_bound(v.second);

		cout << floor((*upper - *lower -1)/2) << "\n";
	}

	return 0;
}