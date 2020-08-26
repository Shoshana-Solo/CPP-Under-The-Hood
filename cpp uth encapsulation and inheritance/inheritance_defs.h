#ifndef __INHERITANCE_DEFS_H__
#define __INHERITANCE_DEFS_H__

#include <stdio.h>
#include "encapsulation_defs.h"

typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

typedef struct Materials
{
    char c;
}Materials;


const char* Materials_getName_t(enum Types type);


typedef struct Material_t
{
    Types types;

}Material_t;

const char* Material_t_namec(const Material_t * const this);

void CTOR_Material_t_t(Material_t * const this ,  Types mat /* OTHER*/);

/*/// PhysicalBox ///////////*/

typedef struct PhysicalBox
{
    Box box;
    Material_t material_t;
}PhysicalBox;

void CTOR_PhysicalBox_ddd(PhysicalBox * const this , double l, double w, double h);

void CTOR_PhysicalBox_dddenum(PhysicalBox * const this ,double l, double w, double h, enum Types t);

void CTOR_PhysicalBox_enum(PhysicalBox * const this , enum Types t);

void DTR_PhysicalBox(PhysicalBox * const this);

void PhysicalBox_printpc(const PhysicalBox * const this);





inline Materials::Types PhysicalBox::getMaterial() const
{
return material.material;
}

inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
return !(lhs == rhs);
}



typedef struct WeightBox
{
    Box box;
    double weight;
}WeightBox;

void CTOR_WeightBox_dddd(WeightBox * const this ,double l, double w, double h, double wgt /*= 0.0*/);

void CTOR_WeightBox_WeightBox(WeightBox * const this , const WeightBox * const other);

void DTOR_WeightBox(WeightBox * const this);

WeightBox * operator_WeightBox_EQ(WeightBox * const this , const WeightBox * const other);

void WeightBox_printwc(const WeightBox * const this);



inline double WeightBox::getWeight() const
{
return weight;
}

inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}

inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
{
return !(lhs == rhs);
}

#endif


