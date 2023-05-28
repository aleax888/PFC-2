#ifndef NODE_H
#define NODE_H

#include "datum.h"

#include <iostream>

template<typename numeric>
class node
{
private:
	point<numeric>* spatial;
	category* categorical;
	temporary* temporal;


public:

	// constructors
	node(point<numeric>* s, category* c, temporary* t);

	// logic

};

template<typename numeric>
node<numeric>::node(point<numeric>* s, category* c, temporary* t)
{
	spatial = s;
	categorical = c;
	temporal = t;

}


#endif NODE_H
