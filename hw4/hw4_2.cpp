/* WARNING */
/*为了偷懒，本程序为windows程序,不能在Linux下运行*/
#include <atltime.h>
#include <iostream>
class Date
{
public:
	friend Date operator+(const Date& date, int day);
	friend Date operator-(const Date& date, int day);
	Date()
	{
		cur = CTime::GetCurrentTime();
	}
	Date(const CTime& date)
	{
		cur = date;
	}
	Date(int year, int month, int day)
		:cur(year,month,day,0,0,0)
	{
	}

	Date& operator =(const Date& another)
	{
		if (&another == this) return *this;
		cur = another.cur;
		return *this;
	}
	Date& operator++()
	{
		cur += one_day;
		return *this;
	}
	const Date operator++(int)
	{
		cur += one_day;
		return *this;
	}
	Date& operator--()
	{
		cur -= one_day;
		return *this;
	}
	const Date operator--(int)
	{
		cur -= one_day;
		return *this;
	}
	int operator-(const Date& another)
	{
		return (cur - another.cur).GetDays();
	}

	void output() const
	{
		std::cout<<cur.GetYear()<<"-"<<cur.GetMonth()<<"-"<<cur.GetDay()<<"\n";
	}
private:
	CTime cur;
	static CTimeSpan one_day;
};
CTimeSpan Date::one_day(1, 0, 0, 0);

Date operator+(const Date& date, int day)
{
	CTimeSpan add_days(day, 0, 0, 0);
	CTime new_cdate(date.cur);
	new_cdate += add_days;
	Date new_date(new_cdate);
	return new_date;
}
Date operator-(const Date& date, int day)
{
	CTimeSpan add_days(day, 0, 0, 0);
	CTime new_cdate(date.cur);
	new_cdate -= add_days;
	Date new_date(new_cdate);
	return new_date;
}

