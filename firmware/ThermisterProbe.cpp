// ThermisterProbe - Library for reading thermister based temperature probes.
// Contributions and influence from @BDub and @avidan
// https://community.spark.io/t/thermistors-and-the-spark-core/1276

#include "ThermisterProbe.h"
#include "application.h"
#include "math.h"

// TermisterProbe constructor
// pur - Pullup resistor value in ohms
// adcRef - ADC reference value
ThermisterProbe::ThermisterProbe(double pur, int adc)
{
    _pur = pur;
    _adc = adc;
}

// Returns the temperature in Kelvin based off of the Steinhart-Hart equation.
// http://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation
double ThermisterProbe::getTempK(int pin, enum ProbeType probeType)
{
    // Read in analog value
    int aval = analogRead(pin);
    
    _probeType = probeType;
    
    // select probe specific constants
    switch (_probeType) {
        case ET72:
            // ET-7, ET-72, ET-73, ET-72/73 probe constants
            A = -2.20911E-06;
            B = 7.02421E-04;
            C = 1.99476E-05;
            break;
        case ET732: default:
            // ET-732 probe constants
            A = -2.20911E-06;
            B = 7.02421E-04;
            C = 1.99476E-05;
            break;
    }

    // calculate resistance; log() is natural log here
    double R = log((1 / ((_adc / (double) aval) - 1)) * (double)_pur);

    // calculate and return temp
    return (1 / (A + B * R + C * R * R * R));
}

// Returns temp in Celcius
double ThermisterProbe::getTempC(int pin, enum ProbeType probeType) {
    return getTempK(pin, probeType) - 273.15;
}

// Return temp in Fahrenheit
double ThermisterProbe::getTempF(int pin, enum ProbeType probeType) {
    return ((getTempC(pin, probeType) * 9.0) / 5.0 + 32.0);
}