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
	int amount_categorys;
	int amount_temporarys;

	point<numeric> spatial;
	category* categorical;
	temporary* temporal;

public:
	// constructors
	datum();
	datum(point<numeric> p, int ac, category* c, int at, temporary* t);
	datum(std::vector<numeric> p, std::vector<std::string> c, std::vector<std::time_t> t);

	// setters
	void set_spatial(point<numeric> s);
	void set_categorical(int ac, category* c);
	void set_categorical(std::vector<category> c);
	void set_temporal(int at, temporary* t);
	void set_temporal(std::vector<temporary> t);

	// debug
	void print_datum();
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
datum<numeric>::datum()
{

}

template<typename numeric>
datum<numeric>::datum(point<numeric> p, int ac, category* c, int at, temporary* t)
{
	spatial = p;
	amount_categorys = ac;
	categorical = c;
	amount_temporarys = at;
	temporal = t;
}

template<typename numeric>
datum<numeric>::datum(std::vector<numeric> p, std::vector<std::string> c, std::vector<std::time_t> t)
{
	spatial = point<numeric>(p);
	amount_categorys = c.size();
	categorical = new category[amount_categorys];
	for (int i = 0; i < amount_categorys; ++i)
		categorical[i] = category(c[i]);
	amount_temporarys = t.size();
	temporal = new temporary[amount_temporarys];
	for (int i = 0; i < amount_temporarys; ++i)
		temporal[i] = temporary(t[i]);
}

// setters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

template<typename numeric>
void datum<numeric>::set_spatial(point<numeric> s) 
{
	spatial = s;
}

template<typename numeric>
void datum<numeric>::set_categorical(int ac, category* c)
{
	amount_categorys = ac;
	categorical = new category[amount_categorys];
	for (size_t i = 0; i < amount_categorys; i++)
	{
		categorical[i] = c[i];
	}
}

template<typename numeric>
void datum<numeric>::set_categorical(std::vector<category> c)
{
	amount_categorys = c.size();
	categorical = new category[amount_categorys];
	for (size_t i = 0; i < amount_categorys; i++)
	{
		categorical[i] = c[i];
	}
}

template<typename numeric>
void datum<numeric>::set_temporal(int at, temporary* t)
{
	amount_temporarys = at;
	temporal = new temporary[amount_temporarys];
	for (size_t i = 0; i < amount_temporarys; i++)
	{
		temporal[i] = t[i];
	}
}

template<typename numeric>
void datum<numeric>::set_temporal(std::vector<temporary> t)
{
	amount_temporarys = t.size();
	temporal = new temporary[amount_temporarys];
	for (size_t i = 0; i < amount_temporarys; i++)
	{
		temporal[i] = t[i];
	}
}

// debug -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

template<typename numeric>
void datum<numeric>::print_datum()
{
	std::cout << spatial << std::endl;
	for (size_t i = 0; i < amount_categorys; ++i)
		std::cout << categorical[i] << std::endl;
	for (size_t i = 0; i < amount_temporarys; ++i)
		std::cout << temporal[i] << std::endl;
}

#endif DATUM_H