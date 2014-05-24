// ThermisterProbe - Library for reading thermister based temperature probes.
// Contributions and influence from @BDub and @avidan
// https://community.spark.io/t/thermistors-and-the-spark-core/1276

#include "ThermisterProbe.h"

#define PROBE1 A7

ThermisterProbe probe(21570.0, 4095);

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print("Temperature (F): ");
    Serial.println(probe.getTempF(PROBE1, ThermisterProbe::ET72));
    delay(1000);
}