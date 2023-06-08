import os
from glob import glob
from setuptools import setup

package_name = 'four_team_du_stuck'

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
    maintainer='swarm-team',
    maintainer_email='swarm-team@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'du_controller_010 = four_team_du_stuck.du_controller_010_src:main',
        'du_communication_010 = four_team_du_stuck.du_communication_010_src:main',
        'du_controller_011 = four_team_du_stuck.du_controller_011_src:main',
        'du_communication_011 = four_team_du_stuck.du_communication_011_src:main',
        'du_controller_012 = four_team_du_stuck.du_controller_012_src:main',
        'du_communication_012 = four_team_du_stuck.du_communication_012_src:main',
        'du_controller_013 = four_team_du_stuck.du_controller_013_src:main',
        'du_communication_013 = four_team_du_stuck.du_communication_013_src:main',
        'du_controller_014 = four_team_du_stuck.du_controller_014_src:main',
        'du_communication_014 = four_team_du_stuck.du_communication_014_src:main',
        'du_controller_015 = four_team_du_stuck.du_controller_015_src:main',
        'du_communication_015 = four_team_du_stuck.du_communication_015_src:main',
        'du_controller_016 = four_team_du_stuck.du_controller_016_src:main',
        'du_communication_016 = four_team_du_stuck.du_communication_016_src:main',
        'du_controller_017 = four_team_du_stuck.du_controller_017_src:main',
        'du_communication_017 = four_team_du_stuck.du_communication_017_src:main',
        'du_controller_018 = four_team_du_stuck.du_controller_018_src:main',
        'du_communication_018 = four_team_du_stuck.du_communication_018_src:main',
        'du_controller_019 = four_team_du_stuck.du_controller_019_src:main',
        'du_communication_019 = four_team_du_stuck.du_communication_019_src:main',
        'du_controller_020 = four_team_du_stuck.du_controller_020_src:main',
        'du_communication_020 = four_team_du_stuck.du_communication_020_src:main',
        'du_controller_021 = four_team_du_stuck.du_controller_021_src:main',
        'du_communication_021 = four_team_du_stuck.du_communication_021_src:main',
        'du_controller_022 = four_team_du_stuck.du_controller_022_src:main',
        'du_communication_022 = four_team_du_stuck.du_communication_022_src:main',
        'du_controller_023 = four_team_du_stuck.du_controller_023_src:main',
        'du_communication_023 = four_team_du_stuck.du_communication_023_src:main',
        'du_controller_080 = four_team_du_stuck.du_controller_080_src:main',
        'du_communication_080 = four_team_du_stuck.du_communication_080_src:main',
        ],
    },
)
