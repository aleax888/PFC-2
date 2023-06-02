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
	// get a data's fragment to assign a node (bouding rectangles)
	
	std::vector<data<numeric>*> data_fragments;

	// get fragments
	for (auto& i : n->get_data_fragment())
	{

	}

	n->set_childs(data_fragments);
}

template<typename numeric>
void cuboid<numeric>::index_categorical(node<numeric>*& n)
{
	// split data to get each categories in each node
	
	std::vector<data<numeric>*> data_fragments;

	// get fragments
	for (auto& i : n->get_data_fragment())
	{

	}

	n->set_childs(data_fragments);
}

template<typename numeric>
void cuboid<numeric>::index_temporal(node<numeric>*& n)
{
	// split a data in intervals of time
	
	std::vector<data<numeric>*> data_fragments;

	// get fragments
	for (auto& i : n->get_data_fragment())
	{

	}

	n->set_childs(data_fragments);
}


#endif CUBOID_H
