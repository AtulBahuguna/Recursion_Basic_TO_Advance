#include<bits/stdc++.h>
/*

User : ATUL BAHUGUNA
GITHUB: https://github.com/AtulBahuguna

*/
using namespace std;
void recursion(vector<int>&arr, int freq[], vector<int>&ds, vector<vector<int>>&ans) {
	if (ds.size() == arr.size()) {
		ans.push_back(ds);
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (!freq[i]) {
			ds.push_back(arr[i]);
			freq[i] = 1;
			recursion(arr, freq, ds, ans);
			freq[i] = 0;
			ds.pop_back();
		}
	}
}
vector<vector<int>> solve(vector<int>arr) {
	vector<vector<int>>ans;
	vector<int>ds;
	int freq[arr.size()] = {0};
	recursion(arr, freq, ds, ans);
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	vector<vector<int>> ans = solve(arr);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}