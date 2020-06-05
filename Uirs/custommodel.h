#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include "mathmodel.h"
#include "simplealgorithms.h"

class satellite : public IMathModel
{
private:
    const long double nu{398600.436e9}; //грав параметр
    long double i;//наклонение (рад)
    long double eccentricity;//безразмерная (доли единицы)
    long double mainAxis;//большая полуось орбиты
    vector X0_oscul;//начальный вектор состояния в оскулирующих элементах
public:
    satellite();
    void preStart() override;
    void getRP(const vector &X,long double t, vector &Y) const override;
};

#endif // CUSTOMMODEL_H
