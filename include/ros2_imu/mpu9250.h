/**
 * @file mpu9250.h
 * @author Leo Huang (846863428@qq.com)
 * @brief
 * @version 0.1
 * @date 2023-02-08
 * @copyright Copyright (c) {2023} 个人版权所有,仅供学习
 */
#ifndef __MPU9250_H__
#define __MPU9250_H__

#include "driver_mpu9250_dmp.h"
#include "imu_interface.h"
#include "iic.h"
#include "gpio_key.h"
#include <cstdint>
#include <mutex>
#include <thread>

class Mpu9250 : public ImuInterface
{
public:
    Mpu9250(std::string type, std::string dev, uint32_t rate);
    ~Mpu9250();

    bool Init();

    Imu GetImuData();

private:
    uint8_t (*g_gpio_irq_)(void) = nullptr;
    std::thread imu_thread_;
    std::mutex data_lock_;
    std::shared_ptr<GpioKey> mpu_int_;
    std::shared_ptr<IicBus> i2c_bus_;
    Imu imu_data_;

    void Mpu9250Loop();

    int GpioInterruptInit();

    void GpioInterruptDeinit();

    static void ReceiveCallback(uint8_t type);
    static void DmpTapCallback(uint8_t count, uint8_t direction);
    static void DmpOrientCallback(uint8_t orientation);
};

#endif
