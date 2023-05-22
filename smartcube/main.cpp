#include <iostream>
#include <string>
#include <type_traits>
#include <random>
#include <climits>
#include <cfloat>
#include <chrono>
#include <ctime>

#include "data.h"
#include "datum.h"
#include "point.h"
#include "temporary.h"
#include "category.h"

#define data_set_length 5
#define data_set_dimension 3

int main()
{
	data<float> d(data_set_length, data_set_dimension);
	d.generate_data_set(0.8, 0.1, 0.1, 0, 100, &data<float>::generate_random_float);
	//d.print_data_set();
	
	
	// short int data set
	//point<short int>* data_set; generate_data_set<short int>(data_set, data_set_length, 3, 0, SHRT_MAX, generate_random_int);	print_data_set(data_set, data_set_length);
	
	// int data set
	//point<int>* data_set; generate_data_set<int>(data_set, data_set_length, 3, 0, INT_MAX, generate_random_int);	print_data_set(data_set, data_set_length);
	
	// unsigned int data set
	//point<unsigned int>* data_set; generate_data_set<unsigned int>(data_set, data_set_length, 3, 0, UINT_MAX, generate_random_int);	print_data_set(data_set, data_set_length);

	// long int data set
	//point<long int>* data_set; generate_data_set<long int>(data_set, data_set_length, 3, 0, LONG_MAX, generate_random_int);	print_data_set(data_set, data_set_length);
	
	// long long int data set
	//point<long long>* data_set; generate_data_set<long long>(data_set, data_set_length, 3, 0, LLONG_MAX, generate_random_int);	print_data_set(data_set, data_set_length);
	
	// unsigned long long int data set
	//point<unsigned long long>* data_set; generate_data_set<unsigned long long>(data_set, data_set_length, 3, 0, ULLONG_MAX, generate_random_int);	print_data_set(data_set, data_set_length);

	// float data set
	//point<float>* data_set; generate_data_set<float>(data_set, data_set_length, 3, 0.0f, FLT_MAX, generate_random_float);	print_data_set(data_set, data_set_length);
	 
	// double data set
	//point<double>* data_set; generate_data_set<double>(data_set, data_set_length, 3, 0.0f, DBL_MAX, generate_random_float);	print_data_set(data_set, data_set_length);
	
	// long double data set
	//point<long double>* data_set; generate_data_set<long double>(data_set, data_set_length, 3, 0.0f, LDBL_MAX, generate_random_float);	print_data_set(data_set, data_set_length);
}