// ThermisterProbe - Library for reading thermister based temperature probes.
// Contributions and influence from @BDub and @avidan
// https://community.spark.io/t/thermistors-and-the-spark-core/1276

#ifndef ThermisterProbe_h
#define ThermisterProbe_h

#include "application.h"

class ThermisterProbe
{
    public:
        enum ProbeType{ET72, ET732};
        ThermisterProbe(double pur, int adc);
        double getTempK(int pin, enum ProbeType probeType);
        double getTempC(int pin, enum ProbeType probeType);
        double getTempF(int pin, enum ProbeType probeType);
    private:
        double _pur, A, B, C;
        int _adc;
        enum ProbeType _probeType;
};

#endif