#ifndef LEAFT_H
#define LEAFT_H

#include <iostream>

class leaft
{
private:
	int count;

public:
	// constructors
	leaft(int c);

	// getters
	int get_count();

	virtual std::vector<float>* get_variance() { return 0; }
	virtual std::vector<float>* get_mean() { return 0; }
	virtual std::vector<float>* get_median() { return 0; }
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
leaft::leaft(int c)
{
	count = c;
}

// getters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
int leaft::get_count()
{
	return count;
}

#endif LEAFT_H
