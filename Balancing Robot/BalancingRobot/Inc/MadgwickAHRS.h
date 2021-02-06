//=====================================================================================================
// MadgwickAHRS.h
//=====================================================================================================
//
// Implementation of Madgwick's IMU and AHRS algorithms.
// See: http://www.x-io.co.uk/node/8#open_source_ahrs_and_imu_algorithms
//
// Date			Author          Notes
// 29/09/2011	SOH Madgwick    Initial release
// 02/10/2011	SOH Madgwick	Optimised for reduced CPU load
//
//=====================================================================================================
#ifndef MadgwickAHRS_h
#define MadgwickAHRS_h

//---------------------------------------------------------------------------------------------------
// Definitions

#define sampleFreq	80.6f		// sample frequency in Hz
#define betaDef		0.1f		// 2 * proportional gain

//----------------------------------------------------------------------------------------------------
// Variable declaration

//---------------------------------------------------------------------------------------------------
// Variable definitions

static float beta = betaDef;								// 2 * proportional gain (Kp)
static float q0 = 1.0f, q1 = 0.0f, q2 = 0.0f, q3 = 0.0f;	// quaternion of sensor frame relative to auxiliary frame

//---------------------------------------------------------------------------------------------------
// Function declarations

void MadgwickAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
void MadgwickAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az);

extern float getQ_0(void);
extern float getQ_1(void);
extern float getQ_2(void);
extern float getQ_3(void);
extern float getPitch(void);

#endif
//=====================================================================================================
// End of file
//=====================================================================================================
