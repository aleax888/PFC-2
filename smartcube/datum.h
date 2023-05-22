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
	datum();
	datum(point<numeric> p, int ac, category* c, int at, temporary* t);
	datum(std::vector<numeric> p, std::vector<std::string> c, std::vector<std::time_t> t);
	void print_datum();
};

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