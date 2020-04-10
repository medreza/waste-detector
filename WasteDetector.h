#ifndef _WasteDetector_h__github_com_medreza__
#define _WasteDetector_h__github_com_medreza__
#endif

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class WasteDetector
{
  private:
    uint8_t pingPin, echoPin, inductiveSensorPin, wasteCat;

    bool metalDetected;

    uint16_t duration, threshold, offset;
    uint16_t ultrasonicPing();

  public:
    WasteDetector(const uint8_t& pingPin_, const uint8_t& echoPin_, const uint8_t& inductiveSensorPin_);
    void detect();
    void setDurationOffset(const uint16_t& o);
    void setDurationThreshold(const uint16_t& t);

    String getWasteCatName();

    uint8_t getWasteCat();
    uint16_t getPingDuration();
    uint16_t getDurationOffset();
    uint16_t getDurationThreshold();
 };