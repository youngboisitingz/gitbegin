#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int Sum(vector<int>& v)
{
	int maxsum = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j < v.size(); j++)
		{
			int tsum = 0;
			for (int k = i; k <= j; k++)
			{
				tsum += v[k];
			}
			if (tsum > maxsum)
				maxsum = tsum;
		}
	}
	return maxsum;
};

int main()
{
	int n;

	cout << "Nhap so phan tu cua mang: ";
	cin >> n;

	vector<int> v;

	srand(time(0));

	for (int i = 0;i < n; i++)
		v.push_back(rand() % 201 - 100);

	cout << Sum(v);
	return 0;
}
