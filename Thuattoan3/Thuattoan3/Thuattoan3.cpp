#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;

int MaxSumCross(vector<int>& v, int left, int mid, int right)
{
	int Sum = 0;
	int Sumleft = INT_MIN;

	for (int i = mid; i >= left; i--)
	{
		Sum += v[i];
		if (Sum > Sumleft) Sumleft = Sum;
	}

	Sum = 0;
	int Sumright = INT_MIN;

	for (int i = mid + 1; i <= right; i++)
	{
		Sum += v[i];
		if (Sum > Sumright) Sumright = Sum;
	}

	return Sumleft + Sumright;
}

int MaxSum(vector<int>& v, int left, int right) 
{
	if (left == right) return v[left];

	int mid = left + (right - left) / 2;

	int maxsumleft = MaxSum(v, left, mid);
	int maxsumright = MaxSum(v, mid + 1, right);
	int maxsumcross = MaxSumCross(v, left, mid, right);

	return max(max(maxsumleft, maxsumright), maxsumcross);
}

int main() 
{
	vector<int> v;
	int n;

	cout << "Nhap so phan tu: ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Mang rong!";
		return 0 ;
	}
	srand(time(0));
	for (int i = 0; i < n; i++)
		v.push_back(rand() % 201 - 100);
	
	int left = 0;
	int right = n - 1;

	cout << MaxSum(v, left, right);
	return 0;
}