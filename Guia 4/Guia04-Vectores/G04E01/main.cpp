#include <iostream>

using namespace std;

int main()
{
	const int dim {10};
	int vec[dim] {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int sum {0};
	for (int i = 0; i < dim; ++i)
		sum += vec[i];
	cout << "La sumatoria da: " << sum << endl;
	return 0;
}
