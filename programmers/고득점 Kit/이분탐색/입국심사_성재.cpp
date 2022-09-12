#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	int max = -1;
	for (int i = 0; i < times.size(); i++) {
		if (times[i] > max) {
			max = times[i];
		}
	}
	long long l = 1, r = (long long)max * n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		long long count = 0;
		long long maxTime = -1;
		for (int i = 0; i < times.size(); i++) {
			count += (mid / times[i]);
			if ((mid / times[i]) * times[i] > maxTime) {
				maxTime = (mid / times[i]) * times[i];
			}
		}
		if (count >= n) {
			answer = maxTime;
			if (count == n) {
				break;
			}
			r = mid - 1;
		}
		else if (count < n) {
			l = mid + 1;
		}
	}

	return answer;
}