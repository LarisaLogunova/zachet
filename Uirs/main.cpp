#include <iostream>
#include "custommodel.h"
#include "integrator.h"
#include "consumer.h"

using namespace std;

int main()
{
    satellite *s = new satellite();
    s->setSampIncrement(100.0);
    s->setT_st(0.0);
    s->setT_fin(86400.0);
    dormandPrinceIntgrator *dp_integrator = new dormandPrinceIntgrator();
    dp_integrator->run(s);
    print(s->getResult());
    long double lat, lon, m, d;
    cout<<"input consumer's lattitude: "<<endl;
    cin >> lat;
    cout<<"input consumer's longtitude: "<<endl;
    cin >> lon;
    cout<<"input M: "<<endl;
    cin >> m;
    cout<<"input D: "<<endl;
    cin >> d;
    consumer *c = new consumer(lat, lon);
    print(c->getMeasures(s->getResult(), m, d));
    return 0;
}
