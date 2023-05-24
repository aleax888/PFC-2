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
	// constructors
	temporary();
	temporary(time_t t);
	temporary(int t);
	temporary(const temporary &t);

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
}

temporary::temporary(time_t t)
{
	timer = t;
}

temporary::temporary(int t)
{
	timer = static_cast<time_t>(t);
}

temporary::temporary(const temporary &t)
{
	timer = t.timer;
}

#endif TEMPORARY_H