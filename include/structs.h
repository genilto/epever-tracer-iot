#include <stdlib.h>

#ifndef STRUCTS_H
#define STRUCTS_H

//rated data - input register (16 bit word readonly)
struct rated_data
{
  float pvVoltage;
  float pvCurrent;
  int16_t pvPower;
  float batteryVoltage;
  float batteryCurrent;
  int16_t batteryPower;
  uint8_t chargingMode; //0000H Connect/disconnect, 0001H PWM, 0002H MPPT
  float loadCurrent;
} ratedData;

//realtime data - input register (16 bit word readonly)
struct realtime_data
{
  float pvVoltage;
  float pvCurrent;
  int16_t pvPower;
  float batteryVoltage;
  float batteryChargingCurrent;
  int16_t batteryChargingPower;
  float loadVoltage;
  float loadCurrent;
  int16_t loadPower;
  float batteryTemp;
  float equipmentTemp;
  float heatsinkTemp;
  uint8_t batterySoC;
  float batteryRemoteTemp;
  uint16_t batteryRatedPower; //1200,2400 for 12/12v
} realtimeData;

//realtime status - input register (16 bit word readonly)
struct realtime_status
{
  uint16_t batteryStatus;
  uint16_t chargeEquipmentStatus;
  uint16_t dischargeEquipmentStatus;
} realtimeStatus;

//statistical parameters - input register (16 bit word readonly)
struct statistical_parameters
{
  float todayMaxPvVoltage;
  float todayMinPvVoltage;
  float todayMaxBattVoltage;
  float todayMinBattVoltage;
  float todayConsumedEnergy;
  float monthConsumedEnergy;
  float yearConsumedEnergy;
  float totalConsumedEnergy;
  float todayGeneratedEnergy;
  float monthGeneratedEnergy;
  float yearGeneratedEnergy;
  float totalGeneratedEnergy;
  float CO2reduction;
  float batteryCurrent; //net, charging minus discharge
  float batteryTemp;
  float ambientTemp;
} statisticalParameters;

//setting_parameters - holding register (16 bit word read-write)
struct setting_parameters
{
  float batteryType;
  float ratedCapacity;
  int temperatureCompensation;
  float highVoltageDisconnect;
  float chargeLimitVoltage;
  float overVoltageReconnect;
  float equalisationVoltage;
  float boostVoltage;
  float floatVoltage;
  float boostReconnectVoltage;
  float lowVoltageReconnect;
  float underVoltageRecover;
  float lowVoltageDisconnect;
  float realTimeClock;
  int equalisationChargingCycle;
  float batteryTemperatureWarningUpperLimit;
  float batteryTemperatureWarningLowerLimit;
  float controllerInnerTemperatureUpperLimit;
  float controllerInnerTemperatureUpperLimitRecovery;
  float powerComponentTemperatureUpperLimit;
  float powerComponentTemperatureUpperLimitRecover;
  float lineImpedance;
  float nightTimeThresholdVoltage;
  float lightSignalStartupDelayTime;
  float dayTimeThresholdVoltage;
  float lightSignalTurnOffDelayTime;
  float loadControllingMode;
  float workingTimeLength1;
  float workingTimeLength2;
  int turnOnTiming1_H;
  int turnOnTiming1_M;
  int turnOnTiming1_S;
  int turnOffTiming1_H;
  int turnOffTiming1_M;
  int turnOffTiming1_S;
  int turnOnTiming2_H;
  int turnOnTiming2_M;
  int turnOnTiming2_S;
  int turnOffTiming2_H;
  int turnOffTiming2_M;
  int turnOffTiming2_S;
  float lengthOfNight;
  int batteryRatedVoltageCode;       //0=auto, 1=12V, 2=24V
  bool loadTimingControl;            //0=1 timer,1=2 timer
  bool defaultLoadOnOffInManualMode; //0=OFF, 1=ON
  int equaliseDuration;              //minute
  int boostDuration;                 //minute
  int dischargingPercentage;         //$
  int chargingPercentage;            //%
  bool batteryManagementMode;        //0=voltComp, 1=SoC
} settingParameters;

//coil / switch values - coils (single bit read-write)
struct switch_value
{
  bool manualControl;
  bool loadTest;
  bool forceLoad;
} switchValues;

//discrete_input - discretes input (single bit readonly)
struct discrete_input
{
  bool overTemp;
  bool dayNight;
} discreteInput;

#endif