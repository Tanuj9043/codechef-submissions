#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
#define band first
#define length second
 
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
    {
		int N;
		scanf("%d", &N);
		vector<pair<int,int> > a(N);
 
		for (int i = 0; i < N; ++i)
        {
			scanf("%d%d", &a[i].band, &a[i].length);
		}
		sort(a.begin(), a.end());
 
		long long total = 0;
		vector<int> songs;
 
		for (int i = 0; i < N; ++i)
		{
			if (i==0 || a[i-1].band < a[i].band) songs.push_back(a[i].length);
 
            else total += a[i].length;
		}
 
		sort(songs.begin(), songs.end());
 
		long long ans = songs.size() * total;
 
		for (int i = 0; i < songs.size(); ++i)
		{
			ans += (long long)(i+1) * songs[i];
		}
 
		printf("%lld\n", ans);
	}
	return 0;
}
