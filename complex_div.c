#include "complex.h"
complex* complex_div(complex* z, complex* w){
	return complex_new(((z->x * w->x) + (z->y * w->y))/((z->x * z->x)+(w->y * w->y)),((z->y * w->x) + (z->x * w->y))/((z->x*z->x)+(w->y*w->y)));
}
