#include<iostream>
#include<cstdio>

using namespace std;

int year;

enum DAYS{MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
DAYS day;
const int CURRENT_YEAR = 2017, MAX_DIFR=6;

void input()
{
	int h;
	scanf_s("%d", &year);
	scanf_s("%d", &h);
	day = (DAYS)h;
}

bool leapYear(int year_)
{
	if (year_ % 400 == 0 || year_%4==0 && year_%100!=0)
		return true;
	return false;
}

int getDifr()
{
	int difr = 0;
	switch (day)
	{
	case MONDAY: difr = difr + 2;
		break;
	case TUESDAY: difr = difr + 1;
		break;
	case WEDNESDAY: difr = difr + 0;
		break;
	case THURSDAY: difr = difr + 6;
		break;
	case FRIDAY: difr = difr + 5;
		break;
	case SATURDAY: difr = difr + 4;
		break;
	case SUNDAY: difr = difr + 3;
		break;
	}
	return difr;
}

int countW(int year_,int difr_)
{
	cout << "year_ = " << year_ << endl;
	cout << "difr_ = " << difr_ << endl;
	while (year_<CURRENT_YEAR && difr_ > 0) {
		year_++;
		if (leapYear(year_))
			difr_=difr_-2;
		else 
			difr_--;
		cout << "In WHILE year_ = " << year_ << " and difr_ = " << difr_ << endl;
	}

	if (year_ < CURRENT_YEAR && difr_==0)
	{
		return 1 + countW(year_+1, MAX_DIFR+difr_);
	}
	else {
		if (year_ < CURRENT_YEAR && difr_ < 0) return countW(year_ + 1, MAX_DIFR + difr_);
		if (year_ == CURRENT_YEAR && difr_ == 0) return 1;
		return 0;
	}
}

int main()
{
	input();
	int count = 0;
	count = countW(year, getDifr());
	cout << count;
	system("pause");
	return 0;
}