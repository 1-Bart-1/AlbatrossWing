#ifndef ORIENT_H
#define ORIENT_H

#include <SPI.h>
#include <Wire.h>
#include <SparkFunMPU9250-DMP.h>
#include <helper_3dmath.h>


class Orient {
    public:
        float q0 = 1.0;
        float q1 = 0.0;
        float q2 = 0.0;
        float q3 = 0.0;
        MPU9250_DMP imu;

        Orient() {
            Wire.begin();
        }

        void begin() {
            if (imu.begin() != INV_SUCCESS) {
                while (1) {
                    Serial.println("Unable to communicate with MPU-9250");
                    Serial.println("Check connections, and try again.");
                    Serial.println();
                    delay(5000);
                }
            }
            imu.dmpBegin(DMP_FEATURE_6X_LP_QUAT | // Enable 6-axis quat
                        DMP_FEATURE_GYRO_CAL, // Use gyro calibration
                        10); // Set DMP FIFO rate to 10 Hz
            // DMP_FEATURE_LP_QUAT can also be used. It uses the 
            // accelerometer in low-power mode to estimate quat's.
            // DMP_FEATURE_LP_QUAT and 6X_LP_QUAT are mutually exclusive
        }

        void update(Quaternion* q) {
            // Check for new data in the FIFO
            if (imu.fifoAvailable()) {
                // Use dmpUpdateFifo to update the ax, gx, mx, etc. values
                if ( imu.dmpUpdateFifo() == INV_SUCCESS) {
                    // computeEulerAngles can be used -- after updating the
                    // quaternion values -- to estimate roll, pitch, and yaw
                    imu.computeEulerAngles();
                    // After calling dmpUpdateFifo() the ax, gx, mx, etc. values
                    // are all updated.
                    // Quaternion values are, by default, stored in Q30 long
                    // format. calcQuat turns them into a float between -1 and 1
                    q->w = imu.calcQuat(imu.qw);
                    q->x = imu.calcQuat(imu.qx);
                    q->y = imu.calcQuat(imu.qy);
                    q->z = imu.calcQuat(imu.qz);
                }
            }
        }
};

#endif

Orient orient;