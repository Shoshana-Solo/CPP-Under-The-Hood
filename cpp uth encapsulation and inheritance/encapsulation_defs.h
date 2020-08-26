#ifndef __ENCAPSULATION_DEFS_H__
#define __ENCAPSULATION_DEFS_H__

const char * const DEF_MSG;
const char * message;

//// Box ////////////

typedef struct Box
{
    double length;
    double width;
    double height;
}Box;

void CTOR_Box_d(Box * const this , double dim);

void CTOR_Box_ddd(Box * const this , double l, double w, double h);

void DTOR_Box(Box * this);

Box * operator_Box_multEQd(Box * const this , double mult);


//// Shelf ////////////

typedef struct  Shelf
{
    Box boxes[3];

}Shelf;

void Shelf_setBox(Shelf * const this , int index, const Box * dims);

double Shelf_getVolumec(Shelf * const this);

void Shelf_printc(Shelf * const this);


#endif