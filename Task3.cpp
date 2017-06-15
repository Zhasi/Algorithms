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

int max_P()
{
	sort(arr, arr + n);

	int i = 0, j = n - 1;
	int num1, num2, num3;
	if (abs(arr[j])> abs(arr[i]))
	{
		num1 = arr[j];
		j--;
	}
	else {
		num1 = arr[i];
		i++;
	}
	printf_s("%d \n", num1);
	if (abs(arr[j])> abs(arr[i]))
	{
		num2 = arr[j];
		j--;
	}
	else {
		num2 = arr[i];
		i++;
	}
	printf_s("%d \n", num2);

	if (num1 > 0 && num2 > 0 || num1<0 && num2<0)
	{
		num3 = arr[j];
	}
	else
	{
		num3 = arr[i];
	}
	printf_s("%d \n", num3);

	return num1*num2*num3;
}

int main()
{
	input();
	int max_;
	max_ = max_P();
	cout << max_;
	system("pause");
	return 0;
}