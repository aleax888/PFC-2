#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <type_traits>
#include <random>
#include <climits>
#include <cfloat>

#include "datum.h"
#include "point.h"
#include "temporary.h"
#include "category.h"


template<typename numeric>
class data
{
private:
	datum<numeric> *data_set;
	int length;
	int dimension;

public:
	typedef numeric(data<numeric>::* fp)(numeric, numeric);

	data(int l, int d);

	numeric generate_random_int(numeric down, numeric up);
	numeric generate_random_float(numeric down, numeric up);
	void generate_data_set(float percentage_s, float percentage_c, float percentage_t, numeric down, numeric up, fp gr);
	void print_data_set();
};

template<typename numeric>
data<numeric>::data(int l, int d)
{
	length = l;
	dimension = d;
}

template<typename numeric>
numeric data<numeric>::generate_random_int(numeric down, numeric up)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<numeric> distribution(down, up);
	return distribution(generator);
}

template<typename numeric>
numeric data<numeric>::generate_random_float(numeric down, numeric up)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_real_distribution<numeric> distribution(down, up);
	return distribution(generator);
}

template<typename numeric>
void data<numeric>::generate_data_set(float percentage_s, float percentage_c, float percentage_t, numeric down, numeric up, fp gr)
{
	data_set = new datum<numeric>[length];
	for (size_t i = 0; i < length; i++)
	{
		//data_set[i].spatial.set_dimension(dimension);

		for (size_t j = 0; j < dimension; j++)
		{
			//data_set[i].spatial.set_coordinates(j, gr(down, up));
		}
		for (size_t j = 0; j < dimension; j++)
		{
			//data_set[i].categorical;
		}
		for (size_t j = 0; j < dimension; j++)
		{
			//data_set[i].temporal;
		}
	}
}

template<typename numeric>
void data<numeric>::print_data_set()
{
	for (size_t i = 0; i < length; i++)
		data_set[i].print_point();
}
#endif DATA_H