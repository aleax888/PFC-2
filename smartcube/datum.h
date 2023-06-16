#ifndef DATUM_H
#define DATUM_H

#include <iostream>
#include <vector>
#include <string>

#include "point.h"
#include "category.h"
#include "temporary.h"

template<typename numeric>
class datum
{
private:
	point<numeric> spatial;
	std::vector<category> categorical;
	temporary temporal;

public:
	// constructors
	datum();
	datum(point<numeric> p, int ac, category* c, temporary t);
	datum(std::vector<numeric> p, std::vector<std::string> c, std::time_t t);

	// setters
	void set_spatial(std::vector<numeric> s);
	void set_spatial(point<numeric> s);
	void set_categorical(int ac, category* c);
	void set_categorical(std::vector<category> c);
	void set_temporal(temporary t);
	
	// getters
	point<numeric>* get_spatial();
	std::vector<category>* get_categorical();
	temporary* get_temporal();

	// debug
	void print_datum();

	// overload operators
		// assignment
	void operator=(const datum<numeric>& d)
	{
		set_spatial(d.spatial);
		set_categorical(d.categorical);
		set_temporal(d.temporal);
	}
		// output
	friend std::ostream& operator<<(std::ostream& os, const datum<numeric>& d)
	{
		os << d.spatial << std::endl;
		for (size_t i = 0, s = d.categorical.size(); i < s; ++i)
			os << d.categorical[i] << std::endl;
		os << d.temporal << std::endl;
		return os;
	}
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
datum<numeric>::datum()
{
	// ga
}

template<typename numeric>
datum<numeric>::datum(point<numeric> p, int ac, category* c, temporary t)
{
	spatial = p;
	categorical.resize(ac);
	for (size_t i = 0; i < ac; i++)
	{
		categorical[i] = c[i];
	}
	temporal = t;
}

template<typename numeric>
datum<numeric>::datum(std::vector<numeric> p, std::vector<std::string> c, std::time_t t)
{
	spatial = point<numeric>(p);
	categorical.resize(c.size());
	for (size_t i = 0, s = c.size(); i < s; ++i)
		categorical[i] = category(c[i]);
	temporal = temporary(t);
}


// setters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

template<typename numeric>
void datum<numeric>::set_spatial(std::vector<numeric> s) 
{
	spatial = point<numeric>(s);
}

template<typename numeric>
void datum<numeric>::set_spatial(point<numeric> s) 
{
	spatial = s;
}

template<typename numeric>
void datum<numeric>::set_categorical(int ac, category* c)
{
	categorical.resize(ac);
	for (size_t i = 0; i < ac; i++)
	{
		categorical[i] = c[i];
	}
}

template<typename numeric>
void datum<numeric>::set_categorical(std::vector<category> c)
{
	categorical = c;
}

template<typename numeric>
void datum<numeric>::set_temporal(temporary t)
{
	temporal = t;
}

// getter -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
template<typename numeric>
point<numeric>* datum<numeric>::get_spatial()
{
	return &spatial;
}

template<typename numeric>
std::vector<category>* datum<numeric>::get_categorical()
{
	return &categorical;
}

template<typename numeric>
temporary* datum<numeric>::get_temporal()
{
	return &temporal;
}

// debug -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

template<typename numeric>
void datum<numeric>::print_datum()
{
	std::cout << spatial << std::endl;
	for (size_t i = 0, s = categorical.size(); i < s; ++i)
		std::cout << categorical[i] << std::endl;
	std::cout << temporal << std::endl;
}

#endif DATUM_H