#include<bits/stdc++.h>
using namespace std;
void solve(int i, vector<int>&arr, int sum, vector<int>&ans) {
	if (i == arr.size()) {
		ans.push_back(sum);
		return;
	}
	//time to pick
	sum += arr[i];
	solve(i + 1, arr, sum, ans);
	sum -= arr[i];
	solve(i + 1, arr, sum, ans);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int>ans;
	solve(0, arr, 0, ans);
	sort(ans.begin(), ans.end());
	for (auto it : ans) {
		cout << it << " ";
	}

	return 0;
}