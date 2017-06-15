#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXSIZE = 10000;
int arr[MAXSIZE];
int n;

void input()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

bool check()
{
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
	{
		if (abs(arr[i] - arr[i + 1]) != 1)
			return false;
	}
	return true;
}

int main()
{
	input();
	bool flag;
	flag=check();
	cout<<flag;
	return 0;
}