#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
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
	std::vector<datum<numeric>*> data_set;

public:
	typedef numeric(data<numeric>::* fp)(numeric, numeric);

	// constructors
	data();
	data(int l, int d);

	// setters
	void set_data(datum<numeric>* d);
	void set_data(size_t l, datum<numeric>** d);
	void set_data(std::vector<datum<numeric>*> d);
	
	// getters
	int get_lenght();
	int get_dimension();
	std::vector<datum<numeric>*>* get_data();

	// generators
	numeric generate_random_int(numeric down, numeric up);
	numeric generate_random_float(numeric down, numeric up);
	std::string generate_random_string(int size);
	time_t generate_random_date();
	void generate_random_data_set(size_t l, size_t s, size_t c, numeric down, numeric up, fp gr);
	
	// debug
	void print_data_set();
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
data<numeric>::data() {}

// setters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
template<typename numeric>
void data<numeric>::set_data(datum<numeric>* d)
{
	data_set.push_back(d);
}

template<typename numeric>
void data<numeric>::set_data(size_t l, datum<numeric>** d)
{
	data_set.resize(l);
	for (size_t i = 0; i < l; i++)
	{
		data_set[i] = d[i];
	}
}

template<typename numeric>
void data<numeric>::set_data(std::vector<datum<numeric>*> d)
{
	data_set = d;
}


// getters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
int data<numeric>::get_lenght()
{
	return data_set.size();
}

template<typename numeric>
int data<numeric>::get_dimension()
{
	return data_set[0]->get_spatial()->get_dimension() + data_set[0]->get_categorical()->size() + 1;
}

template<typename numeric>
std::vector<datum<numeric>*>* data<numeric>::get_data()
{
	return &data_set;
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
time_t data<numeric>::generate_random_date() 
{
	std::random_device rd;
	std::mt19937_64 generador(rd());

	// Establecer el rango de tiempo
	std::uniform_int_distribution<time_t> distribucion(0, std::numeric_limits<time_t>::max());

	return distribucion(generador);
}

template<typename numeric>
void data<numeric>::generate_random_data_set(size_t l, size_t s, size_t cs, numeric down, numeric up, fp gr)
{
	data_set.resize(l);
	for (size_t i = 0; i < l; i++) 
	{
		data_set[i] = new datum<numeric>();
	}

	for (size_t i = 0, j; i < l; i++)
	{
		std::vector<numeric> p(s);
		for (j = 0; j < s; j++)
		{
			p[j] = (this->*gr)(down, up);
		}
		data_set[i]->set_spatial(point<numeric>(p));
		std::vector<category> c(cs);
		for (j = 0; j < cs; j++)
		{
			c[j] = category(generate_random_string(1));
		}
		data_set[i]->set_categorical(c);
		data_set[i]->set_temporal(temporary(generate_random_date()));
	}
}

// debug -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
void data<numeric>::print_data_set()
{
	for (size_t i = 0, s = data_set.size(); i < s; i++)
	{
		data_set[i]->print_datum();
	}
}
#endif DATA_H