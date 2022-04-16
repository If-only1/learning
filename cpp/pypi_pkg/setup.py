from setuptools import setup, find_packages

setup(
    name="strprint-test",
    version="1.0.0",
    packages=find_packages(),
    include_package_data=True,
    description='str print',
    author='lxy',
    package_data={
        'strprint': ['*.so']
    },
)
