from setuptools import find_packages, setup

package_name = 'sensor_preprocessing'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/sensor_preprocessing']),
        ('share/sensor_preprocessing', ['package.xml']),
        ('share/sensor_preprocessing/launch', ['launch/turtlebot3_slam_launch.py', 'launch/ekf_launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='varun',
    maintainer_email='varun@todo.todo',
    description='Sensor preprocessing and SLAM integration package',
    license='Apache License 2.0',  # Adjust this to your actual license
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'lidar_preprocessing = sensor_preprocessing.lidar_preprocessing:main',
            'imu_preprocessing = sensor_preprocessing.imu_preprocessing:main',
            'odom_preprocessing = sensor_preprocessing.odometry_preprocessing:main',
            'camera_preprocessing = sensor_preprocessing.camera_preprocessing:main',
        ],
    },
)
