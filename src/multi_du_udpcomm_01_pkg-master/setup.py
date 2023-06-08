import os
from glob import glob
from setuptools import setup

package_name = 'multi_du_udpcomm_01_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='chikushi',
    maintainer_email='shotachikushi@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'du_controller_013 = multi_du_udpcomm_01_pkg.du_controller_013_src:main',
        'du_communication_013 = multi_du_udpcomm_01_pkg.du_communication_013_src:main',
        'du_controller_014 = multi_du_udpcomm_01_pkg.du_controller_014_src:main',
        'du_communication_014 = multi_du_udpcomm_01_pkg.du_communication_014_src:main',
        'du_controller_015 = multi_du_udpcomm_01_pkg.du_controller_015_src:main',
        'du_communication_015 = multi_du_udpcomm_01_pkg.du_communication_015_src:main',
        ],
    },
)
