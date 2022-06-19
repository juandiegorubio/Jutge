#include <bits/stdc++.h>
using namespace std;

void find_sum(const int sum, const int *nums, int pos, const int *set) {
    if(sum == 0) return;
    for(int i=pos; i<*(nums).size(); ++i) {
        
    }

}

void equal_sums(const int sum, const int *nums) {
    vector<vector<int>> sets_sums;
    vector<int> set_sum;
    for(int i=0; i<*(nums).size(); ++i) {
        int num = nums[i];
        if(sum-num>=0) {
            find_sum(sum-num, &nums, i+1, &set_sum);
        }
    }

}


int main() {
	// Get the values
	int s, n;
	cin >> s >> n;
	int nums[n];
	for(int i=0; i<n; ++i) {
        cin >> x[i];
    }
	equal_sums(s, num_pos);
}
