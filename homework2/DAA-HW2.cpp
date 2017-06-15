#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

const int MAXN = 2500;
long long int firstArr[MAXN * MAXN];
int n;

void in()
{
	scanf("%d", &n);
	for (int i = 0; i<(n * n); i++)
	{
		scanf("%lld", &firstArr[i]);
	}
	sort(firstArr, firstArr + (n * n));
}

long long int sumDiag()
{
	long long int sum = 0;
	for (int i = 1; i<=n; i++)
	{
		sum +=firstArr[n*n - i*i];
	}
	/*for (int i = 0; i<n; i++)
	{
		sum += firstArr[i*n + i*(n - i)];
	}*/
	return sum;
}

int main()
{
	in();
	long long int diag = sumDiag();
	printf("%lld\n", diag);
	return 0;
}
