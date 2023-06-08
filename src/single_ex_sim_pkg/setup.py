from setuptools import setup

package_name = 'single_ex_sim_pkg'

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
    maintainer='swarm-team',
    maintainer_email='swarm-team@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'ex_controller_000 = single_ex_sim_pkg.ex_controller_010_src:main',
        'ex_communication_000 = single_ex_sim_pkg.ex_communication_010_src:main',
        'ex_controller_001 = single_ex_sim_pkg.ex_controller_011_src:main',
        'ex_communication_001 = single_ex_sim_pkg.ex_communication_011_src:main',
        #'ex_controller_000 = single_ex_sim_pkg.du_controller_010_src:main',
        #'ex_communication_000 = single_ex_sim_pkg.du_communication_010_src:main',
        ],
    },
)
