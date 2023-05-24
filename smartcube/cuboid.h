#ifndef CUBOID_H
#define CUBOID_H

#include "data.h"

#include <iostream>
#include <vector>
#include <string>

template<typename numeric>
class cuboid
{
private:
	data<numeric>* raw_data;

public:

	// constructors
	cuboid(std::string p, data<numeric>* rd);

	// logic

};

template<typename numeric>
cuboid<numeric>::cuboid(std::string p, data<numeric>* rd)
{
	raw_data = rd;

	// indexing process

}


#endif CUBOID_H
