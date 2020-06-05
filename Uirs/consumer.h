#ifndef CONSUMER_H
#define CONSUMER_H
#include "linearalgebra.h"
#include "simplealgorithms.h"
#include "generator.h"

class consumer
{
private:
    long double lat, lon, h{6371000.0L}, omega{7.292115E-5};
    vector Xcons;
    bool visible;
    generator *g;
public:
    consumer(long double lat,long double lon);
    matrix getMeasures(const matrix &results,long double m, long double d);
};

#endif // CONSUMER_H
