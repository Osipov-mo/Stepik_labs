#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	vector<int> arr;
	while (--num >= 0) {
		int val = 0;
		cin >> val;
		arr.push_back(val);
	}
	auto size = arr.size();
	vector<int> path_len(size);
	for (int i = 0; i < size; ++i) {
		path_len[i] = 1;
		for (int j = 0; j < i; ++j) {
			if ((arr[i] % arr[j] == 0) && (path_len[j] + 1 > path_len[i])) {
				path_len[i] = path_len[j] + 1;
			}
		}
	}
	auto res = max_element(path_len.begin(), path_len.end(), [](int e1, int e2) {return e1 < e2;});
	cout << *res << std::endl;

	return 0;
}
