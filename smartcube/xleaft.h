#ifndef XLEAFT_H
#define XLEAFT_H

#include "leaft.h"

#include <iostream>
#include <vector>

class xleaft : public leaft
{
private:
	std::vector<float> variance;
	std::vector<float> mean;
	std::vector<float> median;

public:
	// constructors
	xleaft(int c, std::vector<float>  v, std::vector<float>  mn, std::vector<float>  md);

	// getters
	int get_count();
	std::vector<float>* get_variance();
	std::vector<float>* get_mean();
	std::vector<float>* get_median();
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
xleaft::xleaft(int c, std::vector<float>  v, std::vector<float>  mn, std::vector<float>  md) : leaft(c)
{
	variance = v;
	mean = mn;
	median = md;
}

// getters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
int xleaft::get_count()
{
	return leaft::get_count();
}

std::vector<float>*  xleaft::get_variance()
{
	return &variance;
}

std::vector<float>*  xleaft::get_mean()
{
	return &mean;
}

std::vector<float>* xleaft::get_median()
{
	return &median;
}

#endif XLEAFT_H
