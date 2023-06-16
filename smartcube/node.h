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
	node(std::vector<datum<numeric>*> d);

	// setters
	void add_child(node<numeric>* n);
	void set_childs(std::vector<data<numeric>*> d);

	// getters
	data<numeric>* get_data_fragment();
	std::vector<node<numeric>*>* get_childs();
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
node<numeric>::node(data<numeric>* d) 
{
	data_fragment = d;
}

template<typename numeric>
node<numeric>::node(std::vector<datum<numeric>*> d)
{
	for (size_t i = 0, s = d.size(); i < s; i++)
	{
		data_fragment->get_data[i] = d;
	}
}

// setters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
void node<numeric>::add_child(node<numeric>* n)
{
	childs.push_back(n);
}

template<typename numeric>
void node<numeric>::set_childs(std::vector<data<numeric>*> d)
{
	for (auto& i : d)
	{
		node<numeric>* aux = new node<numeric>(i);
		if (i->get_lenght())
			add_child(aux);
	}
}

// getters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
template<typename numeric>
data<numeric>* node<numeric>::get_data_fragment()
{
	return data_fragment;
}

template<typename numeric>
std::vector<node<numeric>*>* node<numeric>::get_childs()
{
	return &childs;
}


#endif NODE_H
