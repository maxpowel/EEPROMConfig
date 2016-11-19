//
// Created by alvaro on 26/07/15.
//
#include <Arduino.h>
#include <EEPROM.h>
#include <SensorMonitor.h>
#ifndef EEPROM_CONFIG_H
#define EEPROM_CONFIG_H

struct ConfigurationInfo {
  unsigned int version;
  unsigned short totalFields;
  unsigned long crc;
};

class EEPROMConfig {
public:
    EEPROMConfig();
    unsigned long configCrc(size_t size);
    bool init();
    void writeConfig(struct ConfigurationInfo conf);
    struct ConfigurationInfo conf;
    int load(bool (*loader)(char *name, byte *data, size_t dataSize));
    void writeSensorConfig(byte *data, size_t size);
    void writeSensorConfig(Stream *source, size_t size);
    //int getTotalDevices();
private:

};


#endif //EEPROM_CONFIG_H
