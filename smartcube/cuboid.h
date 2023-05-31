#ifndef CUBOID_H
#define CUBOID_H

#include "data.h"
#include "node.h"

#include <iostream>
#include <vector>
#include <string>

template<typename numeric>
class cuboid
{
private:
	//data<numeric>* raw_data;
	node<numeric>* root;

public:

	// constructors
	cuboid(std::string p, data<numeric>* rd);

	// indexers
	void index_spatial(node<numeric>*& n);
	void index_categorical(node<numeric>*& n);
	void index_temporal(node<numeric>*& n);
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
cuboid<numeric>::cuboid(std::string p, data<numeric>* rd)
{
	//raw_data = rd;
	root = new node<numeric>(rd);

	// indexing process

}

// indexers -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
void cuboid<numeric>::index_spatial(node<numeric>*& n)
{
	// get a row_data's fragment to assign a node (br)
	// this method returns between 1 - 4 nodes
}

template<typename numeric>
void cuboid<numeric>::index_categorical(node<numeric>*& n)
{
	// split a row_data to get diferents categories in each node
	// this method returns n fragments, where n is amount of categories in row_data

	std::vector<data<numeric>*> data_fragments;

	// get fragments

	for (size_t i = 0, s = data_fragments.size(); i < s; i++)
	{
		node<numeric>* aux = new node<numeric>(data_fragments[i]);
		n->add_child(aux);
	}

}

template<typename numeric>
void cuboid<numeric>::index_temporal(node<numeric>*& n)
{
	// split a row_data in intervals of time
	// this method returns n fragments of n intervals of time we can make
}


#endif CUBOID_H
