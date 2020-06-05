#include "custommodel.h"

satellite::satellite():IMathModel(){
    X0.resize(6);
    X0[0] = 0.9;  //big omega
    X0[1] = 1.2;  //naklonenie
    X0[2] = 0.85;  //pericenter latitude
    X0[3] = 19440000.0; //big axis
    X0[4] = 0.0; //e
    X0[5] = 0.8;  //true anomal
    preStart();
}

void satellite::preStart() {
    this->X0 = simpleAlgorithms::orbitToXYZ(X0[0], X0[1], X0[2], X0[3], X0[4], X0[5], nu);
}

void satellite::getRP(const vector &X,long double t, vector &Y) const{
    Y.resize(X.size());
    Y[0] = X[3];
    Y[1] = X[4];
    Y[2] = X[5];
    long double ro = sqrt(pow(X[0],2.) + pow(X[1], 2.) + pow(X[2], 2.));
    Y[3] = -nu*X[0]/pow(ro,3.);
    Y[4] = -nu*X[1]/pow(ro,3.);
    Y[5] = -nu*X[2]/pow(ro,3.);
}

