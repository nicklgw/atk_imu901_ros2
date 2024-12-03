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

orangepi@orangepi5plus:~$ ros2 topic echo /imu_data # 订阅IMU数据 测试


sudo install -Dm644 imu901m.service  /usr/lib/systemd/system/imu901m.service
systemctl enable imu901m.service
systemctl start imu901m.service
systemctl stop imu901m.service
systemctl disable imu901m.service

systemctl status imu901m.service
journalctl -n 100 -u imu901m.service

sudo apt install python3-bloom python3-rosdep fakeroot debhelper dh-python
$ bloom-generate rosdebian
$ fakeroot debian/rules binary
