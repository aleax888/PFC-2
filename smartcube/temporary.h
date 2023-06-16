#ifndef TEMPORARY_H
#define TEMPORARY_H

#include <iostream>
#include <chrono>
#include <ctime>

class temporary
{
private:
	std::time_t timer;

public:
	typedef int(temporary::* fp)();

	// constructors
	temporary();
	temporary(time_t t);
	temporary(int t);
	temporary(const temporary &t);

	// methods
	struct tm* fecha;
	int get_year();
	int get_month();
	int get_day();
	int get_time(fp gt);

	// overload operators
		// assignment
	temporary& operator=(const temporary& t)
	{
		this->timer = t.timer;
		return *this;
	}
		// comparison
	bool operator==(const temporary& t)
	{
		if (timer == t.timer)
			return true;
		return false;
	}
	bool operator!=(const temporary& t)
	{
		return !(*this == t);
	}
		// output
	friend std::ostream& operator<<(std::ostream& os, const temporary& t)
	{
		os << t.timer;
		return os;
	}
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
temporary::temporary()
{
	timer = time(NULL);
	fecha = localtime(&timer);
}

temporary::temporary(time_t t)
{
	timer = t;
	fecha = localtime(&timer);
}

temporary::temporary(int t)
{
	timer = static_cast<time_t>(t);
	fecha = localtime(&timer);
}

temporary::temporary(const temporary &t)
{
	timer = t.timer;
	fecha = localtime(&timer);
}

// methods -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

int temporary::get_year()
{
	//struct tm* fecha = get_date();
	return fecha->tm_year + 1900;  // Se suma 1900 a tm_year
}

int temporary::get_month()
{
	return fecha->tm_mon + 1;  // El rango de tm_mon es de 0 a 11
}

int temporary::get_day()
{
	return fecha->tm_mday;
}

int temporary::get_time(fp gt)
{
	return (this->*gt)();
}

#endif TEMPORARY_H