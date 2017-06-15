#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int n;
vector <int> arr(n);
int max, j, lM;

void input()
{
	int el;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &el);
		arr.push_back(el);
	}
}

vector <string> numbers(n);
void change()
{
	for (int i = 0; i < n; i++)
	{
		string str = to_string(arr[i]);
		numbers.push_back(str);
	}
}

int main()
{
	input();
	change();
	sort(numbers.begin(), numbers.end());
	for (int i = numbers.size()-1; i >=0; i--)
	{
		cout << numbers[i];
	}
	system("pause");
	return 0;
}