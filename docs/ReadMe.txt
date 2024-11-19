正点原子IMU接在香橙派串口(uart8-m1),接线如下,对应系统的设备名(/dev/ttyS8)
uart8-m1	UART8_RX_M1/UART8_TX_M1		TTL电平接正点原子IMU
VCC --- 5V
RX  --- UART8_TX_M1
TX  --- UART8_RX_M1
GND --- GND


操作步骤
orangepi@orangepi5plus:~/imu_ws$ colcon build # 编译
orangepi@orangepi5plus:~/imu_ws$ source install/setup.bash # 设置环境变量
orangepi@orangepi5plus:~/imu_ws$ ros2 launch ros2_imu imu901m.launch.py # 启动程序
