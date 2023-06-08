from setuptools import setup

package_name = 'one_team_ex_base_master'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='admin-swarm',
    maintainer_email='admin-swarm@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'ex_controller_test = one_team_ex_base_master.ex_controller_src:main',
        'ex_communication_test = one_team_ex_base_master.ex_communication_src:main',
        'ex_controller_000 = one_team_ex_base_master.ex_controller_010_src:main',
        'ex_communication_000 = one_team_ex_base_master.ex_communication_010_src:main',
        'ex_controller_001 = one_team_ex_base_master.ex_controller_011_src:main',
        'ex_communication_001 = one_team_ex_base_master.ex_communication_011_src:main',
        'ex_controller_003 = one_team_ex_base_master.ex_controller_013_src:main',
        'ex_communication_003 = one_team_ex_base_master.ex_communication_013_src:main',
        #'ex_controller_000 = one_team_ex_base_master.du_controller_010_src:main',
        #'ex_communication_000 = one_team_ex_base_master.du_communication_010_src:main',
        ],
    },
)
