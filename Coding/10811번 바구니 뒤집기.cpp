#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int N, M, i, j;
	scanf("%d%d", &N, &M);
	vector<int> v(N+1);
	for (i = 1; i <= N; i++) v[i] = i;
	while (M--) {
		scanf("%d%d", &i, &j);
		reverse(v.begin() + i, v.begin() + j + 1);
	}
	for (i = 1; i <= N; i++) printf("%d ", v[i]);
}
