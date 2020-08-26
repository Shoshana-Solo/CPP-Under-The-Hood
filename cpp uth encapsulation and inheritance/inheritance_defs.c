#include <stdio.h>
#include "inheritance_defs.h"

const char* Materials_getName_t(enum Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}


const char* Material_t_namec(const Material_t * const this)
{
    return Materials_getName_t(this -> types);
}

void CTOR_Material_t_t(Material_t * const this ,  enum Types mat /* OTHER*/)
{
    this -> types = mat;

    printf("Material created, set to %s\n", Material_t_namec(this));
}


void CTOR_PhysicalBox_ddd(PhysicalBox * const this , double l, double w, double h)
{
    CTOR_Box_ddd(&(this -> box) , l ,w , h);
    this -> material_t.types = OTHER;
    CTOR_Material_t_t(this , this -> material_t.types);
    PhysicalBox_printpc(this);
}

void CTOR_PhysicalBox_dddenum(PhysicalBox * const this ,double l, double w, double h, Types t)
{
    CTOR_Box_ddd(&(this -> box) , l ,w , h);
    CTOR_Material_t_t(this , t);
    this -> material_t.types = t;
    PhysicalBox_printpc(this);
}

void CTOR_PhysicalBox_enum(PhysicalBox * const this , enum Types t)
{
    CTOR_Box_d(&(this -> box) ,1);
    CTOR_Material_t_t(this , t);
    this -> material_t.types = t;
    PhysicalBox_printpc(this);
}

void DTR_PhysicalBox(PhysicalBox * const this)
{
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this -> box.length, this -> box.width, this -> box.height, Material_t_namec(&(this -> material_t)));
    DTOR_Box(&(this -> box));
}

void PhysicalBox_printpc(const PhysicalBox * const this)
{
    printf("PhysicalBox, made of %s; ", Material_t_namec(&(this -> material_t.types)));
    print_Box(&(this -> box));

}


void CTOR_WeightBox_dddd(WeightBox * const this ,double l, double w, double h, double wgt /*= 0.0*/)
{
    CTOR_Box_ddd(&(this -> box) , l ,w , h);
    this -> weight = wgt;
    WeightBox_printwc(this);
}

void CTOR_WeightBox_WeightBox(WeightBox * const this , const WeightBox * const other)
{
    CTOR_Box_d(&(this -> box) , 1);
    this -> weight = other -> weight;
    WeightBox_printwc(this);
}

void DTOR_WeightBox(WeightBox * const this)
{
    printf("Destructing WeightBox; ");
    WeightBox_printwc(this);
    DTOR_Box(&(this -> box));
}

WeightBox * operator_WeightBox_EQ(WeightBox * const this , const WeightBox * const other)
{
    this -> weight = other -> weight;
    return this;
}

void WeightBox_printwc(const WeightBox * const this)
{
    printf("WeightBox, weight: %f; ", this -> weight);
    print_Box(&(this -> box));
}



