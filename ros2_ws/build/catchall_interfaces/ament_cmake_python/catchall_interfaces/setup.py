from setuptools import find_packages
from setuptools import setup

setup(
    name='catchall_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('catchall_interfaces', 'catchall_interfaces.*')),
)
