#include "WasteDetector.h"

WasteDetector::WasteDetector(const uint8_t& pingPin_, const uint8_t& echoPin_, const uint8_t& inductiveSensorPin_)
{
  pingPin = pingPin_;
  echoPin = echoPin_;
  inductiveSensorPin = inductiveSensorPin_;
  threshold = 999; // default value
  offset = 200; // default value
}

uint16_t WasteDetector::ultrasonicPing()
{
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   return pulseIn(echoPin, HIGH);
}

void WasteDetector::detect()
{
   metalDetected = digitalRead(inductiveSensorPin);
   if (metalDetected == true) { 
    wasteCat = 1;
    duration = 0;
   } else {
    duration = ultrasonicPing();
      if (duration > threshold && duration <= threshold + offset) {
        wasteCat = 2; //plastic
      } else if (duration > threshold - offset && duration <= threshold) {
        wasteCat = 3; //paper
      } else {
        wasteCat = 0; //nothing/unknown
      }
   }
}

uint8_t WasteDetector::getWasteCat()
{
    return wasteCat;
}

String WasteDetector::getWasteCatName()
{
    if (wasteCat == 0) {
      return "unknown";
    } else if (wasteCat == 1) {
      return "metal";
    } else if (wasteCat == 2) {
      return "plastic";
    } else {
      return "paper";
    }
}

uint16_t WasteDetector::getPingDuration()
{
    return duration;
}

uint16_t WasteDetector::getDurationThreshold()
{
    return threshold;
}

void WasteDetector::setDurationThreshold(const uint16_t& t)
{
    threshold = t;
}

uint16_t WasteDetector::getDurationOffset()
{
    return offset;
}

void WasteDetector::setDurationOffset(const uint16_t& o)
{
    offset = o;
}