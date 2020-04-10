#include <WasteDetector.h>

const byte pingPin = 2;
const byte echoPin = 3;
const byte inductiveSensorPin = 4;

WasteDetector sensor(pingPin,echoPin,inductiveSensorPin);

void setup()
{
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(inductiveSensorPin, INPUT);
  sensor.setDurationThreshold(800); // default is 999
  Serial.begin(9600);
}


void loop()
{
  Serial.println("Using ultrasonic ping duration threshold: " + String(sensor.getDurationThreshold()) + \
                  " with offset: " + String(sensor.getDurationOffset()));
  sensor.detect();
  Serial.println("Ping duration: " + String(sensor.getPingDuration()));
  Serial.println("Detected waste category: " + String(sensor.getWasteCat()));
  Serial.println("Detected waste name: " + sensor.getWasteCatName());
  delay(1000);
}
