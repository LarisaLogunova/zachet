#include "consumer.h"

consumer::consumer(long double lat,long double lon)
{
    this->lat = lat;
    this->lon = lon;
    this->visible = false;
    this->Xcons.resize(3);
    this->g = new generator;
}

matrix consumer::getMeasures(const matrix &results,long double m, long double d){
    matrix measures(0,2);
    for (int i = 0; i < results.rowsCount(); i++){
        long double cur_lon = this->lon + omega*results(i,6);
        this->Xcons = simpleAlgorithms::polarToXYZ(lat, cur_lon, h);
        vector temp(3);
        temp[0] = results(i, 0);
        temp[1] = results(i, 1);
        temp[2] = results(i, 2);
        long double alpha = acos(temp*Xcons/(temp.length()*Xcons.length()));
        if (alpha < 2.269){
            measures.resize(measures.rowsCount() + 1, 2);
            vector velocity(3);
            vector pos(3);
            velocity[0] = results(i, 3);
            velocity[1] = results(i, 4);
            velocity[2] = results(i, 5);
            pos[0] = results(i,0);
            pos[1] = results(i,1);
            pos[2] = results(i,2);
            measures(measures.rowsCount(), 0) = pos.length() + g->white_noise_generator(m, d);
            measures(measures.rowsCount(), 1) = velocity.length() + g->white_noise_generator(m, d);
        }
    }
    return measures;
}
