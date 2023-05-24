#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <iostream>

class category
{
private:
	std::string name;
	long long id;

public:
	// constructors
	category();
	category(long long i, std::string n);
	category(std::string n);
	category(const category& c);

	// debug
	void print_category();

	// overload operators
		// assignment
	category& operator=(const category& c)
	{
		this->id = c.id;
		this->name = c.name;
		return *this;
	}

	category& operator=(std::string str)
	{
		category c(str);
		return c;
	}
		// comparison
	bool operator==(const category& c)
	{
		if (id == c.id)
			return true;
		return false;
	}
	bool operator!=(const category& c)
	{
		return !(*this == c);
	}
		// output
	friend std::ostream& operator<<(std::ostream& os, const category& c)
	{
		os << c.id << '(' << c.name << ')';
		return os;
	}
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
category::category()
{
	id = 0;
	name = "";
}

category::category(long long i, std::string n)
{
	id = i;
	name = n;
}

category::category(std::string n)
{
	std::string todigit = "";
	for (size_t i = 0, s = n.size(); i < s; i++)
		id += int(n[i]);
	name = n;
}

category::category(const category& c)
{
	*this = c;
}

// debug -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void category::print_category()
{
	std::cout << "id:   " << id << std::endl;
	std::cout << "name: " << name << std::endl;
}

#endif CATEGORY_H