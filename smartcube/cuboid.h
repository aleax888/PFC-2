#ifndef CUBOID_H
#define CUBOID_H

#include "data.h"
#include "node.h"

#include <iostream>
#include <vector>
#include <string>
#include <utility>

template<typename numeric>
class cuboid
{
private:
	//data<numeric>* raw_data;
	node<numeric>* root;

public:
	// constructors
	cuboid(std::string p, data<numeric>* rd);

	// logic 
		// to spatial
	std::pair<point<numeric>, point<numeric>> get_mbr(node<numeric>* n);
	std::vector<std::pair<point<numeric>, point<numeric>>> get_quad_partition(std::pair<point<numeric>, point<numeric>> mbr);
	bool is_into(point<numeric> p, std::pair<point<numeric>, point<numeric>> mbr);
		// to categorical
	bool is_in(std::vector<category>* categories, category target);
	std::vector<category>* get_all_categories(node<numeric>* n);
		// to temporal
	bool is_interval(std::vector<int>* tempories, int target);
	std::vector<int>* get_all_tempories(node<numeric>* n);

	// indexers
	void index_spatial(node<numeric>*& n);
	void index_categorical(node<numeric>*& n);
	void index_temporal(node<numeric>*& n, int deep);
};

// constructors -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
cuboid<numeric>::cuboid(std::string p, data<numeric>* rd)
{
	//raw_data = rd;
	root = new node<numeric>(rd);

	// indexing process
	//index_spatial(root);
	//index_categorical(root);
	index_temporal(root, 2);
	
	std::cout << "root" << std::endl;
	root->get_data_fragment()->print_data_set();
	std::cout << "amount childs: " << root->get_childs()->size() << std::endl;
	for (size_t i = 0; i < root->get_childs()->size(); ++i)
	{
		std::cout << "child " << i << std::endl;
		(*root->get_childs())[i]->get_data_fragment()->print_data_set();
	}
}

// logic -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

// spatial --------------------------------------------------------------------------------------------------------------
template<typename numeric>
std::pair<point<numeric>, point<numeric>> cuboid<numeric>::get_mbr(node<numeric>* n)
{
	point<numeric> up_left, down_right;
	std::vector<datum<numeric>*>* tmp = n->get_data_fragment()->get_data();
	up_left = *((*tmp)[0])->get_spatial();
	down_right = *((*tmp)[0])->get_spatial();
	
	//std::cout << *((*tmp)[0])->get_spatial() << std::endl; // gaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	
	for (size_t i = 1, s = tmp->size(); i < s; i++)
	{

		//std::cout << *((*tmp)[i])->get_spatial() << std::endl; // gaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

		if ((*((*tmp)[i])->get_spatial())[0] <= up_left[0])
		{
			up_left.set_coordinates(0, (*((*tmp)[i])->get_spatial())[0]);
		}
		else if ((*((*tmp)[i])->get_spatial())[0] >= down_right[0])
		{
			down_right.set_coordinates(0, (*((*tmp)[i])->get_spatial())[0]);
		}
		if ((*((*tmp)[i])->get_spatial())[1] >= up_left[1])
		{
			up_left.set_coordinates(1, (*((*tmp)[i])->get_spatial())[1]);
		}
		else if ((*((*tmp)[i])->get_spatial())[1] <= down_right[1])
		{
			down_right.set_coordinates(1, (*((*tmp)[i])->get_spatial())[1]);
		}
	}
	return std::pair<point<numeric>, point<numeric>>(up_left, down_right);
}

template<typename numeric>
std::vector<std::pair<point<numeric>, point<numeric>>> cuboid<numeric>::get_quad_partition(std::pair<point<numeric>, point<numeric>> mbr)
{
	//std::cout << mbr.first << " - " << mbr.second << std::endl; // gaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

	std::vector<std::pair<point<numeric>, point<numeric>>> quad_partition(4);
	quad_partition[0].first = mbr.first;
	quad_partition[0].second = mbr.first;
	quad_partition[0].second.set_coordinates(0, (mbr.first[0] + mbr.second[0]) / 2.0f);
	quad_partition[0].second.set_coordinates(1, (mbr.first[1] + mbr.second[1]) / 2.0f);
	
	quad_partition[1].first = mbr.first; 
	quad_partition[1].first.set_coordinates(0, (mbr.first[0] + mbr.second[0]) / 2.0f);
	quad_partition[1].second = mbr.second; 
	quad_partition[1].second.set_coordinates(1, (mbr.first[1] + mbr.second[1]) / 2.0f);
	
	quad_partition[2].first = mbr.first; 
	quad_partition[2].first.set_coordinates(1, (mbr.first[1] + mbr.second[1]) / 2.0f);
	quad_partition[2].second = mbr.second; 
	quad_partition[2].second.set_coordinates(0, (mbr.first[0] + mbr.second[0]) / 2.0f);
	
	quad_partition[3].first = mbr.second;
	quad_partition[3].first.set_coordinates(0, (mbr.first[0] + mbr.second[0]) / 2.0f);
	quad_partition[3].first.set_coordinates(1, (mbr.first[1] + mbr.second[1]) / 2.0f);
	quad_partition[3].second = mbr.second;

	return quad_partition;
	//for (size_t i = 0; i < quad_partition.size(); i++)	std::cout << quad_partition[i].first << " - " << quad_partition[i].second << std::endl; // gaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
}

template<typename numeric>
bool cuboid<numeric>::is_into(point<numeric> p, std::pair<point<numeric>, point<numeric>> mbr)
{
	return (mbr.first[0] <= p[0] and mbr.first[1] >= p[1] and mbr.second[0] >= p[0] and mbr.second[1] <= p[1]);
}

// categorical ----------------------------------------------------------------------------------------------------------
template<typename numeric>
bool cuboid<numeric>::is_in(std::vector<category>* categories, category target)
{
	for (size_t i = 0, s = categories->size(); i < s; i++)
	{
		if ((*categories)[i] == target)
		{
			return true;
		}
	}
	return false;
}

template<typename numeric>
std::vector<category>* cuboid<numeric>::get_all_categories(node<numeric>* n)
{
	std::vector<category>* categories = new std::vector<category>;

	std::vector<datum<numeric>*>* tmp = n->get_data_fragment()->get_data();
	
	for (size_t i = 0, s = tmp->size(); i < s; i++)
	{
		std::vector<category>* aux = ((*tmp)[i])->get_categorical();
		for (size_t j = 0, sc = aux->size(); j < sc; j++)
		{
			if (!is_in(categories, (*aux)[j]))
			{
				categories->push_back((*aux)[j]);
			}
		}
	}
	
	return categories;
}

// temporal
template<typename numeric>

bool cuboid<numeric>::is_interval(std::vector<int>* tempories, int target)
{
	for (size_t i = 0, s = tempories->size(); i < s; i++)
	{
		if ((*tempories)[i] == target)
		{
			return true;
		}
	}
	return false;
}

template<typename numeric>
std::vector<int>* cuboid<numeric>::get_all_tempories(node<numeric>* n)
{
	std::vector<int>* tempories = new std::vector<int>;

	std::vector<datum<numeric>*>* tmp = n->get_data_fragment()->get_data();
	tempories->push_back(((*tmp)[0])->get_temporal()->get_time(&temporary::get_year));
	
	for (size_t i = 1, s = tmp->size(); i < s; i++)
	{
		temporary* aux = ((*tmp)[i])->get_temporal();
		/*std::cout << *aux << std::endl;
		std::cout << aux->get_time(&temporary::get_year) << std::endl;
		std::cout << aux->get_time(&temporary::get_month) << std::endl;
		std::cout << aux->get_time(&temporary::get_day) << std::endl;*/
		for (size_t j = 0, st = tempories->size(); j < st; j++)
		{
			if (!is_interval(tempories, aux->get_time(&temporary::get_year)))
			{
				tempories->push_back(aux->get_time(&temporary::get_year));
			}
		}
	}

	return tempories;
}

// indexers -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

template<typename numeric>
void cuboid<numeric>::index_spatial(node<numeric>*& n)
{
	// get a data's fragment to assign a node (bouding rectangles)
	
	std::vector<data<numeric>*> data_fragments(4);
	for (size_t i = 0; i < 4; i++)
	{
		data_fragments[i] = new data<numeric>();
	}

	std::pair<point<numeric>, point<numeric>> mbr = get_mbr(n);
	std::vector<std::pair<point<numeric>, point<numeric>>> quad_partition = get_quad_partition(mbr);

	// get fragments
	std::vector<datum<numeric>*>* tmp = n->get_data_fragment()->get_data();
	
	for (size_t i = 0, st = tmp->size(), sqp = quad_partition.size(); i < st; i++)
	{
		for (size_t j = 0; j < sqp; ++j)
		{
			if (is_into(*((*tmp)[i]->get_spatial()), quad_partition[j]))
			{
				data_fragments[j]->set_data((*tmp)[i]);
				break;
			}
		}
	}

	n->set_childs(data_fragments);
}

template<typename numeric>
void cuboid<numeric>::index_categorical(node<numeric>*& n)
{
	// split data to get each categories in each node
	
	std::vector<category>* tmp_cat = get_all_categories(n);
	std::vector<data<numeric>*> data_fragments(tmp_cat->size());
	for (size_t i = 0, s = tmp_cat->size(); i < s; i++)
	{
		data_fragments[i] = new data<numeric>();
	}

	// get fragments

	std::vector<datum<numeric>*>* tmp = n->get_data_fragment()->get_data();

	for (size_t i = 0, st = tmp->size(), stc = tmp_cat->size(); i < st; i++)
	{
		std::vector<category>* aux = ((*tmp)[i])->get_categorical();
		for (size_t j = 0, sc = aux->size(); j < sc; j++)
		{
			for (size_t k = 0; k < stc; k++)
			{
				if ((*tmp_cat)[k] == (*aux)[j])
				{
					data_fragments[k]->set_data((*tmp)[i]);
				}
			}
		}
	}

	n->set_childs(data_fragments);
}

template<typename numeric>
void cuboid<numeric>::index_temporal(node<numeric>*& n, int deep)
{
	// split a data in intervals of time
	std::vector<int>* tmp_t = get_all_tempories(n);
	std::vector<data<numeric>*> data_fragments(tmp_t->size());
	for (size_t i = 0, s = tmp_t->size(); i < s; i++)
	{
		data_fragments[i] = new data<numeric>();
	}

	// get fragments
	std::vector<datum<numeric>*>* tmp = n->get_data_fragment()->get_data();

	for (size_t i = 0, s = tmp->size(), st = tmp_t->size(); i < s; i++)
	{
		temporary* aux = ((*tmp)[i])->get_temporal();
		for (size_t j = 0; j < st; j++)
		{
			if ((*tmp_t)[j] == aux->get_time(&temporary::get_year))
			{
				data_fragments[j]->set_data((*tmp)[i]);
			}
		}
	}

	n->set_childs(data_fragments);
}


#endif CUBOID_H
