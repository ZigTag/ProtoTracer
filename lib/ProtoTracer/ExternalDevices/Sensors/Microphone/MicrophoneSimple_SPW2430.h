#include <Arduino.h>
#include "..\..\..\Utils\Math\Mathematics.h"
#include "..\..\..\Utils\Filter\RunningAverageFilter.h"
#include "..\..\..\Utils\Filter\MinFilter.h"

class MicrophoneSimple{
private:
    uint8_t pin;
    RunningAverageFilter mv = RunningAverageFilter(0.075f, 40);
    MinFilter minF = MinFilter(100);
    RunningAverageFilter output = RunningAverageFilter(0.1f, 10);
    float previousReading = 0.0f;
    long previousMillis = 0;
    long startMillis = 0;

public:
    MicrophoneSimple(uint8_t pin){
        this->pin = pin;

        analogReadRes(12);
        analogReadAveraging(32);

        pinMode(pin, INPUT);

        startMillis = millis();
    }

    float Update(){
        float read = analogRead(pin);
        float change = read - previousReading;
        float dT = ((float)millis() - (float)previousMillis) / 1000.0f;
        float changeRate = change / dT;
        float amplitude = mv.Filter(fabs(changeRate));
        float minimum = minF.Filter(amplitude);
        float normalized = Mathematics::Constrain(amplitude - minimum - 250, 0.0f, 4000.0f);
        float truncate = output.Filter(normalized / 100.0f);
        
        previousReading = read;
        previousMillis = millis();

        return Mathematics::Constrain(truncate, 0.0f, 1.0f);
    }
};
