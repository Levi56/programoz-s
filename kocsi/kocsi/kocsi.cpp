#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int stop(vector<pair<int, int>> v, int range) {
	int next_stop = 0;
	// finding index of the gas station with the most gas in range
	for (int i = 0; i < v.size() && v[i].first <= range; i++)
		if (v[next_stop].second < v[i].second)
			next_stop = i;
	return next_stop;
}

int main()
{
#pragma region read K = kilometer, N = number of fuel stations, F = current/starting fuel, L = consumption
	int K, N, F, L;

	cin >> K >> N >> F >> L;
	vector<pair<int, int>> v(N, pair<int, int>());

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	cerr << "-------------------------" << endl;
	/*for (int i = 0; i < N; i++)
		cerr << v[i].first/100 << " " << v[i].second << endl;*/
#pragma endregion

	int stops = 0;
	int range = 100 * F / L;
	int current_stop;
	while (!(K <= range))
	{
		current_stop = stop(v, range);
		range += (100 * v[current_stop].second / L);
		v.erase(v.begin() + current_stop);
		stops++;
	}
	cout << stops;
}
