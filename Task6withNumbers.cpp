#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>

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

int lengthNumb(int numb)
{
	if (numb >= 0 && numb < 10) return 1;
	return 1 + lengthNumb(numb / 10);
}

int getDig(int numb, int l)
{
	return numb / (int)pow(10, l - 1) % 10;
}

void change(int max_, int j_, int lm_)
{
	//printf_s("max = %d , max_ = %d \n", max, max_);
	max = max_;
	//printf_s("max = %d \n", max);
	//printf_s("j= %d , j_ = %d \n", j, j_);
	j = j_;
	/*printf_s("j = %d \n", j);
	printf_s("lM= %d , lm_ = %d \n", lM, lm_);*/
	lM = lm_;
	//cout << "lM=" << lM << endl;
}

void check(int fd_, int i_, int lengthC)
{
	if (lM > lengthC)
	{
		int lastD = getDig(arr[j], 1);
	//	cout << "lastD=" << lastD << endl;
		if (lastD < fd_)
			change(fd_, i_, lengthC);
	}
	else
		if (lM < lengthC)
			{
				int lastD = getDig(arr[i_], 1);
				cout << "lastD=" << lastD << endl;
				if (lastD > fd_)
					change(fd_, i_, lengthC);
			}
			else 
			{
				int k = 2;
				int secM = getDig(arr[j], lM -k);
				int secF = getDig(arr[i_], lengthC - k);
				while (secM == secF)
				{
					k++;
					secM = getDig(arr[j], lM - k);
					secF = getDig(arr[i_], lengthC - k);
				}
				if (secM < secF)
					change(fd_, i_, lengthC);
			}
	
}

long long maxNumb()
{
	long long number = 0;
	while (n != 0) {
		int i = 0;
		int lengthI = lengthNumb(arr[i]);
		int firstDig = getDig(arr[i], lengthI);
		change(firstDig, i, lengthI);
		i++;
		while (i < n)
		{
			int lengthCurr = lengthNumb(arr[i]);
			int fD = getDig(arr[i], lengthCurr);
			cout << "max=" << max << "  fD= " << fD << endl;
			if (max < fD) {
				cout << "change" << endl;
				change(fD, i, lengthCurr);
				
			}
			else
				if (max == fD) {
					cout << "check" << endl;
					check(fD, i, lengthCurr);
				}
			i++;
		}
		number = number * (int) pow(10,lM)+ arr[j];
		arr.erase(arr.begin() + j);
		n--;
	}
	return number;
}

int main()
{
	input();

	long int number = maxNumb();
	cout << number;
	system("pause");
	return 0;
}