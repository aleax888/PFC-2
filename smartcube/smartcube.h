#ifndef SMARTCUBE_H
#define SMARTCUBE_H

#include "data.h"
#include "cuboid.h"

#include <iostream>
#include <vector>
#include <string>

template<typename numeric>
class smartcube
{
private:
	data<numeric>* raw_data;
	std::vector<std::string> posibilities;
	cuboid<numeric>* current_cuboid;

public:
	// constructor
	smartcube(size_t lenght, size_t a_spatial, size_t a_categorica, numeric down, numeric up);
	
	// logic
	void get_posibilities(std::string p = "");
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
smartcube<numeric>::smartcube(size_t lenght, size_t a_spatial, size_t a_categorical, numeric down, numeric up)
{
	raw_data = new data<numeric>();
	raw_data->generate_random_data_set(lenght, a_spatial, a_categorical, down, up, &data<float>::generate_random_float);
	//raw_data->print_data_set();

	get_posibilities();
	//for (auto i : posibilities) std::cout << i << std::endl; 

	// create a finest cuboid
	current_cuboid = new cuboid<numeric>(posibilities[0], raw_data);
}

// logic -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
void smartcube<numeric>::get_posibilities(std::string p)
{
	if (p.size() < raw_data->get_dimension())
	{
		get_posibilities(p + "1");
		get_posibilities(p + "0");
	}
	else posibilities.push_back(p);
}

#endif SMARTCUBE_H
