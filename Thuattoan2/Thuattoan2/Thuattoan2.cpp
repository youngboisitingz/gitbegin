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
		int sumt = 0;
		for (int j = i; j < v.size(); j++)
		{
			sumt += v[j];
			if (sumt > maxsum)
				maxsum = sumt;
		}
	}
	return maxsum;
};

int main() 
{
	vector<int> v;

	int n;

	cout << "Nhap so phan tu mang: ";
	cin >> n;

	srand(time(0));

	for (int i = 0; i < n; i++)
		v.push_back(rand() % 201 - 100);

	cout << Sum(v);
	
	return 0;
}

