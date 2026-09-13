#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int MaxSum(vector<int>& v)
{
	int maxsum = INT_MIN;
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{	
		sum += v[i];
		if (sum > maxsum)
			maxsum = sum;
		
		if (sum < 0)
			sum = 0;
	}
	return maxsum;
}

int main() 
{
	vector<int> v = {1, 2, -2, 4, 8, -10};

	int n;
	
	cout << "Nhap so phan tu: ";
	cin >> n;

	if (n < 0)
	{	
		cout << "So phan tu khong duoc < 0!";
		return 0;
	}

	srand(time(0));

	for (int i = 0; i < n; i++)
	v.push_back(rand() / 201 - 100);

	cout << MaxSum(v);

}