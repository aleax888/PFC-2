#include "point.h"


template<typename numeric>
point<numeric>::point(int d, numeric *c)
{
	dimension = d;
	//coordinates = new numeric[dimension];
	coordinates = c;
}

template class point<int>;
template class point<long>;
template class point<long long>;
template class point<float>;
template class point<double>;