#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <type_traits>
#include <random>
#include <climits>
#include <cfloat>
#include <chrono>
#include <ctime>

#include "smartcube.h"
#include "leaft.h"
#include "xleaft.h"

#define data_set_length 100000
#define amount_spatial 2
#define amount_categorical 3
#define deep_spatial 2
#define deep_temporal 1


int main()
{
	auto started = std::chrono::high_resolution_clock::now();

	smartcube<float> s(data_set_length, amount_spatial, amount_categorical, 0, 90, deep_spatial, deep_temporal, true);
	
	auto done = std::chrono::high_resolution_clock::now();
	std::cout << "Indexing Time: " << std::fixed 
		<< std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() 
		<< " milliseconds " << std::endl << std::endl;
	std::cout << "Indexing Time: " << std::fixed 
		<< std::chrono::duration_cast<std::chrono::seconds>(done - started).count() 
		<< " seconds " << std::endl << std::endl;
}