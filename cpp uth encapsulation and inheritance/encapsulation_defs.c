#include <stdio.h>
#include "encapsulation_defs.h"

const char * const DEF_MSG = "The total volume held on the shelf is";
const char * message = DEF_MSG;

/*/// Box ///////////*/

void print_Box(Box * const this)
{
    printf("Box: %f x %f x %f\n", this -> length, this -> width, this -> height);
}


void CTOR_Box_d(Box * const this , double dim)
{
    this -> length = dim;
    this -> width = dim;
    this -> height = dim;
    print_Box(this);
}

void CTOR_Box_ddd(Box * const this , double l, double w, double h)
{
    this -> length = l;
    this -> width = w;
    this -> height = h;
    print_Box(this);
}


void DTOR_Box(Box * const this)
{
    printf("Box destructor, %f x %f x %f\n", this -> width, this -> height, this -> length);
}

Box * operator_Box_multEQd(Box * const this , double mult)
{
    this -> width *= mult;
    this -> height *= mult;
    this -> length *= mult;

    return this;
}


/*/// Shelf ///////////*/


void Shelf_setBox(Shelf * const this , int index, const Box * dims)
{
    this -> boxes[index] = *dims;
}

double Shelf_getVolumec(Shelf * const this)
{
    double vol = 0;
    for (size_t i = 0; i < 3; ++i)
        vol += (this -> boxes[i].length * this -> boxes[i].width * this -> boxes[i].height);

    return vol;
}

void Shelf_printc(Shelf * const this)
{
    printf("%s %f\n", message, Shelf_getVolumec(this));
}






