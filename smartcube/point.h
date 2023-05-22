#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>

template<typename numeric>
class point
{
private:
	int dimension;
	numeric *coordinates;

public:
	// constructors
	point();
	point(int d);
	point(int d, numeric *c);
	point(std::vector<numeric> c);
	point(const point<numeric> &p);
	
	// setters
	void set_dimension(int d);
	void set_coordinates(int index, numeric value);
	void set_coordinates(numeric *c);
	void set_coordinates(std::vector<numeric> c);

	// debug
	void print_point(bool complete = false);

	// overload operators
		// arithmetic
	point<numeric> operator+(const point<numeric>& p)
	{
		point<numeric> answer(p.dimension);
		for (size_t i = 0; i < p.dimension; i++)
			answer.set_coordinates(i, coordinates[i] + p.coordinates[i]);
		return answer;
	}
	point<numeric> operator+(numeric k)
	{
		point<numeric> answer(dimension);
		for (size_t i = 0; i < dimension; i++)
			answer.set_coordinates(i, coordinates[i] + k);
		return answer;
	}
	point<numeric> operator-(const point<numeric>& p)
	{
		point<numeric> answer(p.dimension);
		for (size_t i = 0; i < p.dimension; i++)
			answer.set_coordinates(i, coordinates[i] - p.coordinates[i]);
		return answer;
	}
	point<numeric> operator-(numeric k)
	{
		point<numeric> answer(dimension);
		for (size_t i = 0; i < dimension; i++)
			answer.set_coordinates(i, coordinates[i] - k);
		return answer;
	}
		// increment and decrement
	point<numeric> operator++()
	{
		*this = *this + 1;
		return *this;
	}
	point<numeric> operator++(int)
	{
		point<numeric> old = *this;
		*this = *this + 1;
		return old;
	}
	point<numeric> operator--()
	{
		*this = *this - 1;
		return *this;
	}
	point<numeric> operator--(int)
	{
		point<numeric> old = *this;
		*this = *this - 1;
		return old;
	}
		// assignment	
	void operator=(const point<numeric> &p)
	{
		set_dimension(p.dimension);
		set_coordinates(p.coordinates);
	}
	point<numeric> operator+=(const point<numeric>& p)
	{
		*this = *this + p;
		return *this;
	}
	point<numeric> operator+=(numeric k)
	{
		*this = *this + k;
		return *this;
	}
	point<numeric> operator-=(const point<numeric>& p)
	{
		*this = *this - p;
		return *this;
	}
	point<numeric> operator-=(numeric k)
	{
		*this = *this - k;
		return *this;
	}
		// array subscriptor
	numeric& operator[](size_t index) 
	{ 
		return coordinates[index];
	}
	const numeric operator[](size_t index) const 
	{ 
		return coordinates[index];
	}
		// comparison
	bool operator==(const point<numeric>& p)
	{ 
		for (size_t i = 0; i < dimension; i++)
			if ((*this)[i] != p[i])
				return false;
		return true;
	}
	bool operator!=(const point<numeric>& p)
	{ 
		return !(*this == p);
	}
		// output
	friend std::ostream& operator<<(std::ostream& os, const point<numeric>& p)
	{
		os << p.dimension << "(" << p[0];
		for (size_t i = 1; i < p.dimension; i++)
			os << ", " << p[i];
		os << ")";
		return os;
	}
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
template<typename numeric>
point<numeric>::point()
{
	dimension = 0;
	coordinates = nullptr;
}

template<typename numeric>
point<numeric>::point(int d)
{
	dimension = d;
	coordinates = new numeric[dimension];
}

template<typename numeric>
point<numeric>::point(int d, numeric* c)
{
	dimension = d;
	coordinates = new numeric[dimension];
	set_coordinates(c);
}

template<typename numeric>
point<numeric>::point(std::vector<numeric> c)
{
	dimension = c.size();
	coordinates = new numeric[dimension];
	set_coordinates(c);
}

template<typename numeric>
point<numeric>::point(const point<numeric> &p)
{
	*this = p;
}

// setters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
template<typename numeric>
void point<numeric>::set_dimension(int d)
{
	dimension = d;
	coordinates = new numeric[dimension];
}

template<typename numeric>
void point<numeric>::set_coordinates(int index, numeric value)
{
	coordinates[index] = value;
}

template<typename numeric>
void point<numeric>::set_coordinates(numeric *c)
{
	for (size_t i = 0; i < dimension; i++)
		coordinates[i] = c[i];
}

template<typename numeric>
void point<numeric>::set_coordinates(std::vector<numeric> c)
{
	for (size_t i = 0; i < dimension; i++)
		coordinates[i] = c[i];
}

// debug -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
template<typename numeric>
void point<numeric>::print_point(bool complete)
{
	int limit = complete ? dimension : dimension < 5 ? dimension : 5;
	
	if (complete)
		std::cout << "dimension: " << dimension << std::endl;
	std::cout << "(" << coordinates[0];
	for (size_t i = 1; i < limit; i++)
		std::cout << ", " << coordinates[i];
	if (complete or limit == dimension)
		std::cout << ")" << std::endl;
	else
		std::cout << "..." << std::endl;
}

#endif