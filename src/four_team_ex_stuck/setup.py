import os
from glob import glob
from setuptools import setup

package_name = 'four_team_ex_stuck'

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
        'ex_controller_test = four_team_ex_stuck.ex_controller_src:main',
        'ex_communication_test = four_team_ex_stuck.ex_communication_src:main',
        'ex_controller_000 = four_team_ex_stuck.ex_controller_010_src:main',
        'ex_communication_000 = four_team_ex_stuck.ex_communication_010_src:main',
        'ex_controller_001 = four_team_ex_stuck.ex_controller_011_src:main',
        'ex_communication_001 = four_team_ex_stuck.ex_communication_011_src:main',
        'ex_controller_003 = four_team_ex_stuck.ex_controller_013_src:main',
        'ex_communication_003 = four_team_ex_stuck.ex_communication_013_src:main',
        'ex_controller_004 = four_team_ex_stuck.ex_controller_014_src:main',
        'ex_communication_004 = four_team_ex_stuck.ex_communication_014_src:main',
        'ex_controller_005 = four_team_ex_stuck.ex_controller_015_src:main',
        'ex_communication_005 = four_team_ex_stuck.ex_communication_015_src:main',
        #'ex_controller_000 = four_team_ex_stuck.du_controller_010_src:main',
        #'ex_communication_000 = four_team_ex_stuck.du_communication_010_src:main',
        ],
    },
)
