from distutils.core import setup, Extension

setup(name='cfib', version='1.0', ext_modules=[Extension('c_module', ['c_module.c'])])
