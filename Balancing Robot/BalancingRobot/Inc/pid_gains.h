#ifndef __PID_GAINS_H
#define __PID_GAINS_H

#define Kp 20.0f
#define Ki 5.0f
#define Kd 0.01f

#define theta_Kp 10.0f
#define theta_Ki 1.0f
#define theta_Kd 0.0f

#define N  100.0f

float getKp(void);
float getKi(void);
float getKd(void);
float getKp_theta(void);
float getKi_theta(void);
float getKd_theta(void);
float getN(void);

#endif
