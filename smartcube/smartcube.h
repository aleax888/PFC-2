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
	bool x;

public:
	// constructor
	smartcube(size_t lenght, size_t a_spatial, size_t a_categorical, numeric down, numeric up, size_t d_spatial, size_t d_temporal, bool x = false);
	
	// logic
	void get_posibilities(size_t s, std::string p = "");
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
smartcube<numeric>::smartcube(size_t lenght, size_t a_spatial, size_t a_categorical, numeric down, numeric up, size_t d_spatial, size_t d_temporal, bool _x)
{
	x = _x;
	raw_data = new data<numeric>();
	raw_data->generate_random_data_set(lenght, a_spatial, a_categorical, down, up, &data<float>::generate_random_float);

	get_posibilities(a_categorical + d_spatial + d_temporal);

	// create a finest cuboid
	current_cuboid = new cuboid<numeric>(posibilities[0], d_spatial, a_categorical, d_temporal, raw_data, x);
}

// logic -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
void smartcube<numeric>::get_posibilities(size_t s, std::string p)
{
	if (p.size() < s)
	{
		get_posibilities(s, p + "1");
		get_posibilities(s, p + "0");
	}
	else posibilities.push_back(p);
}

#endif SMARTCUBE_H
