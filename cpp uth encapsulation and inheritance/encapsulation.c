#include <stdio.h>
#include <stdbool.h>
#include "encapsulation_defs.h"

extern const char * const DEF_MSG;
extern const char * message;

Box largeBox;

static char bThis = 0;
static char bThat = 0;
static Box box99;
static Box box88;

void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n");

    if(!bThis++)
        CTOR_Box_ddd(&box99 , 99 , 99 , 99 );

    operator_Box_multEQd(&box99 , 10);
}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");

    if(!bThat++)
        CTOR_Box_ddd(&box88 , 88, 88, 88);

    operator_Box_multEQd(&box88 , 10);
}

void doBoxes()
{
    Box b1  ,b2 , b3  ,b4;
    printf("\n--- Start doBoxes() ---\n\n");
    CTOR_Box_d(&b1 ,3);
    CTOR_Box_ddd(&b2 ,4, 5, 6);
    printf("b1 volume: %f\n", b1.length * b1.width * b1.height);
    printf("b2 volume: %f\n", b2.length * b2.width * b2.height);

    operator_Box_multEQd(&b1 , 1.5);
    operator_Box_multEQd(&b2 , 0.5);

    printf("b1 volume: %f\n", b1.length * b1.width * b1.height);
    printf("b2 volume: %f\n", b2.length * b2.width * b2.height);

    b3 = b2;
    b4 = b2;
    operator_Box_multEQd(&b4 ,3);
    printf("b3 %s b4\n", b3.length == b4.length && b3.width == b4.width && b3.length == b4.length ? "equals" : "does not equal");

    operator_Box_multEQd(&b3 , 1.5);
    operator_Box_multEQd(&b4 , 0.5);
    printf("Now, b3 %s b4\n", b3.length == b4.length && b3.width == b4.width && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    DTOR_Box(&b4);
    DTOR_Box(&b3);
    DTOR_Box(&b2);
    DTOR_Box(&b1);
}



void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox , box;
    CTOR_Box_d(&aBox , 5);

    Shelf aShelf;

    CTOR_Box_d(&aShelf.boxes[0] ,1);
    CTOR_Box_d(&aShelf.boxes[1]  ,1);
    CTOR_Box_d(&aShelf.boxes[2]  ,1);
    Shelf_printc(&aShelf);
    Shelf_setBox(&aShelf , 1, &largeBox);
    Shelf_setBox(&aShelf , 0, &aBox);

    Shelf_printc(&aShelf);
    message = "This is the total volume on the shelf:";
    Shelf_printc(&aShelf);
    message = "Shelf's volume:";
    Shelf_printc(&aShelf);

    CTOR_Box_ddd(&box ,2, 4, 6);
    Shelf_setBox(&aShelf ,1, &box);
    DTOR_Box(&box);

    CTOR_Box_d(&box , 2);
    Shelf_setBox(&aShelf , 2, &box);
    DTOR_Box(&box);
    Shelf_printc(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
    DTOR_Box(&(aShelf.boxes[2]));
    DTOR_Box(&(aShelf.boxes[1]));
    DTOR_Box(&(aShelf.boxes[0]));
    DTOR_Box(&aBox);
}

int main()
{
    CTOR_Box_ddd(&largeBox , 10 , 20 ,30);
    printf("\n--- Start main() ---\n\n");
    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");
    DTOR_Box(&box88);

    if(bThis)
        DTOR_Box(&box99);

    if(bThat)
        DTOR_Box(&largeBox);

    return 0;
}

