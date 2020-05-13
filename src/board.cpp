#include "core_simulation.h"
#include "mydevices.h"


int main(){
  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs
  AnalogSensorTemperature temperature(DELAY,TEMP);
// RAJOUT capteur luminosite
  AnalogSensorLuminosity luminosity(DELAY,luminosite_environnement,3.5);
  DigitalActuatorLED led1(DELAY);
  I2CActuatorScreen screen;
  
  // branchement des capteurs actionneurs
  esp8266.pin(1,temperature);
  esp8266.pin(0,led1);
  esp8266.i2c(1,screen);
    //Ajout capteur luminosite
  esp8266.pin(2,luminosity);
  
  // allumage de la carte
  esp8266.run();
  return 0;
}


