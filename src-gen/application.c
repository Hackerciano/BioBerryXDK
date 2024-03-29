/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-10-26 00:54:54
 */


#include <BCDS_Basics.h>
#include <BCDS_Retcode.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>
#include <BCDS_Environmental.h>
#include <BCDS_LightSensor.h>
#include <XdkSensorHandle.h>
#include <stdbool.h>
#include <stdint.h>
#include "ConnectivityHttpRestClientHttpBackEnd.h"
#include "SensorEnvironment.h"
#include "SensorLight.h"
#include "MitaExceptions.h"
#include "application.h"

#ifndef BCDS_MODULE_ID
#define BCDS_MODULE_ID 0xCAFE
#endif

int32_t counterMotion = 0;

Retcode_T initGlobalVariables_application() {
	Retcode_T exception = RETCODE_OK;
	
	if(exception != NO_EXCEPTION) return exception;
	
	return exception;
}

Retcode_T HandleEvery30Second1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	uint32_t sensorLightModalityPreparation_1;
	exception = LightSensor_readLuxData(xdkLightSensor_MAX44009_Handle, &sensorLightModalityPreparation_1);
	if(exception != NO_EXCEPTION) return exception;
	
	uint32_t lightValue;
	lightValue = sensorLightModalityPreparation_1;
	Environmental_Data_T sensorEnvironmentModalityPreparation_2;
	exception = Environmental_readData(xdkEnvironmental_BME280_Handle, &sensorEnvironmentModalityPreparation_2);
	if(exception != NO_EXCEPTION) return exception;
	
	int32_t tempValue;
	tempValue = sensorEnvironmentModalityPreparation_2.temperature;
	uint32_t humidityValue;
	humidityValue = sensorEnvironmentModalityPreparation_2.humidity;
	uint32_t pressureValue;
	pressureValue = sensorEnvironmentModalityPreparation_2.pressure;
	char result997246363_buf[99] = {0};
	char *result997246363 = result997246363_buf;
	
	char mainHandleEvery30Second12Result997246363_6_buf[99] = {0};
	snprintf(mainHandleEvery30Second12Result997246363_6_buf, sizeof(mainHandleEvery30Second12Result997246363_6_buf), "{\"field1\": %" PRIu32 ", \"field2\": %" PRId32 ", \"field3\": %" PRIu32 ", \"field4\": %" PRIu32 " }", lightValue, tempValue, humidityValue, pressureValue);
	memcpy(result997246363, mainHandleEvery30Second12Result997246363_6_buf, sizeof(mainHandleEvery30Second12Result997246363_6_buf));
	
	char* _newConnectivityHttpRestClientHttpBackEnd_Post_1 = result997246363;
	exception = ConnectivityHttpRestClientHttpBackEnd_Post_Write(&_newConnectivityHttpRestClientHttpBackEnd_Post_1);
	if(exception != NO_EXCEPTION) return exception;


	return NO_EXCEPTION;
}


