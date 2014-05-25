// ThermistorProbe - Library for reading thermistor based temperature probes.
// Contributions and influence from @BDub and @avidan
// https://community.spark.io/t/thermistors-and-the-spark-core/1276

#include "ThermistorProbe/ThermistorProbe.h"

#define PROBE1 A7

ThermistorProbe probe(21570.0, 4095);

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print("Temperature (F): ");
    Serial.println(probe.getTempF(PROBE1, ThermistorProbe::ET72));
    delay(1000);
}