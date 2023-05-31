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

	// constructors
	data();
	data(int l, int d);

	// setters
	void set_ld(int l, int d);
	void set_lenght(int l);
	void set_dimension(int d);
	void set_data(datum<numeric>* d);
	
	// getters
	int get_lenght();
	int get_dimension();

	// generators
	numeric generate_random_int(numeric down, numeric up);
	numeric generate_random_float(numeric down, numeric up);
	std::string generate_random_string(int size);
	void generate_random_data_set(float percentage_s, float percentage_c, float percentage_t, numeric down, numeric up, fp gr);
	
	// debug
	void print_data_set();
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
data<numeric>::data() {}

template<typename numeric>
data<numeric>::data(int l, int d)
{
	length = l;
	dimension = d;
}

// setters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
template<typename numeric>
void data<numeric>::set_ld(int l, int d)
{
	length = l, dimension = d;
}

template<typename numeric>
void data<numeric>::set_lenght(int l)
{
	length = l;
}

template<typename numeric>
void data<numeric>::set_dimension(int d)
{
	dimension = d;
}

template<typename numeric>
void data<numeric>::set_data(datum<numeric>* d)
{
	data_set = d;
}


// getters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
int data<numeric>::get_lenght()
{
	return length;
}

template<typename numeric>
int data<numeric>::get_dimension()
{
	return dimension;
}

// generators -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

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
std::string data<numeric>::generate_random_string(int size) 
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(97, 122); // Rango de caracteres ASCII (mayúsculas)

	std::string answer;

	for (int i = 0; i < size; ++i) 
	{
		char caracter = static_cast<char>(distribution(generator));
		answer.push_back(caracter);
	}

	return answer;
}

template<typename numeric>
void data<numeric>::generate_random_data_set(float percentage_s, float percentage_c, float percentage_t, numeric down, numeric up, fp gr)
{
	data_set = new datum<numeric>[length];
	for (size_t i = 0, j, s,
		s1 = dimension * percentage_s, 
		s2 = dimension * percentage_c,
		s3 = dimension * percentage_t
		; i < length; i++)
	{
		std::vector<numeric> p(s1);
		for (j = 0; j < s1; j++)
		{
			p[j] = (this->*gr)(down, up);
		}
		data_set[i].set_spatial(point<numeric>(p));
		std::vector<category> c(s2);
		for (j = 0; j < s2; j++)
		{
			c[j] = category(generate_random_string(5));
		}
		data_set[i].set_categorical(c);
		std::vector<temporary> t(s3);
		for (j = 0; j < s3; j++)
		{
			//t[j] = temporary(generate_random_int(down, up));
			t[j] = temporary();
		}
		data_set[i].set_temporal(t);
	}
}

// debug -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
void data<numeric>::print_data_set()
{
	for (size_t i = 0; i < length; i++)
	{
		data_set[i].print_datum();
	}
}
#endif DATA_H