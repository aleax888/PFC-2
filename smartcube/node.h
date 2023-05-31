#ifndef NODE_H
#define NODE_H

#include "datum.h"

#include <iostream>
#include <vector>

template<typename numeric>
class node
{
private:
	data<numeric>* data_fragment;

	std::vector<node<numeric>*> childs;

public:

	// constructors
	node(data<numeric>* d);

	// setters
	void add_child(node<numeric>* n);
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
node<numeric>::node(data<numeric>* d)
{
	data_fragment = d;
}

// setters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
template<typename numeric>
void node<numeric>::add_child(node<numeric>* n)
{
	childs.push_back(n);
}


#endif NODE_H
