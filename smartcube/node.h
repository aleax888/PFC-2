#ifndef NODE_H
#define NODE_H

#include "datum.h"
#include "leaft.h"
#include "xleaft.h"

#include <iostream>
#include <vector>
#include <algorithm>

template<typename numeric>
class node
{
private:
	data<numeric>* data_fragment;
	std::vector<node<numeric>*> childs;
	leaft* pre;

public:

	// constructors
	node(data<numeric>* d);
	node(std::vector<datum<numeric>*> d);

	// setters
	void add_child(node<numeric>* n);
	void set_childs(std::vector<data<numeric>*> d);
	void set_leaft();
	void set_xleaft();

	// getters
	data<numeric>* get_data_fragment();
	std::vector<node<numeric>*>* get_childs();

	// debug
	void print_node();
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

template<typename numeric>
void node<numeric>::set_leaft()
{
	std::vector<datum<numeric>*>* tmp = data_fragment->get_data();
	pre = new leaft((*tmp).size());
}

template<typename numeric>
void node<numeric>::set_xleaft()
{
	std::vector<datum<numeric>*>* tmp = data_fragment->get_data();
	int c = (*tmp).size();
	std::vector<float> v(2, 0.0f), mn(2, 0.0f), md(2, 0.0f);

	for (size_t i = 0, s = c; i < s; i++)
	{
		md[0] += (*((*tmp)[i])->get_spatial())[0];
		md[1] += (*((*tmp)[i])->get_spatial())[1];
	}

	md[0] /= c;
	md[1] /= c;

	std::vector<float> aux1, aux2;
	for (size_t i = 0, s = c; i < s; i++)
	{
		aux1.push_back((*((*tmp)[i])->get_spatial())[0]);
		aux2.push_back((*((*tmp)[i])->get_spatial())[1]);
	}
	std::sort(aux1.begin(), aux1.end());
	std::sort(aux2.begin(), aux2.end());
	mn[0] = aux1[aux1.size() / 2];
	mn[1] = aux2[aux2.size() / 2];

	for (size_t i = 0, s = c; i < s; i++)
	{
		aux1[i] -= md[0];
		aux1[i] *= aux1[i];
		v[0] += aux1[i];
		aux2[i] -= md[1];
		aux2[i] *= aux2[i];
		v[1] += aux2[i];
	}
	v[0] /= c;
	v[1] /= c;

	//std::cout << md[0] << " " << md[1] << std::endl;
	//std::cout << mn[0] << " " << mn[1] << std::endl;
	//std::cout << v[0] << " " << v[1] << std::endl << std::endl;
	
	pre = new xleaft(c, v, mn, md);
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

// getters -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
template<typename numeric>
void node<numeric>::print_node()
{
	std::cout << "begin node" << std::endl;
	data_fragment->print_data_set();
	std::cout << "end node" << std::endl;
}

#endif NODE_H
