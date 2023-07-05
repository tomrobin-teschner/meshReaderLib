# Introduction

This repository showcases how to implement mesh reading for Computational Fluid Dynamics (CFD) applications using C++. It currently supports the following file formats:

## Unstructured:
- StarCD

Additional formats to be implemented

# Usage

To compile and use the mesh reading library, use CMake with the usual commands, i.e.

```bash
cd /change/to/project/root/dir
mkdir build/
cd build
cmake -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_INSTALL_PREFIX:PATH=/usr/local ..
cmake --build . --config Release --target all -j 4
```

To install the library into the path specified by ```-DCMAKE_INSTALL_PREFIX```, use the following command

```bash
cmake --build . --target install
```

You can test that the library is compiled correctly and working by executing the tests

```bash
cd /change/to/project/root/dir/build/tests
ctest
```

# Documentation

To build the associated documentation with doxygen, first ensure that doxygen and graphviz are installed. Use you favourite package manager to install them, on Ubuntu this would result in

```bash
sudo apt install -y doxygen graphviz
```

Then, execute the following command(s)

```bash
cd /change/to/project/root/dir
doxygen docs/Doxyfile
```

The generated documentation will be build in the ```docs/html``` folder. Open the ```index.html``` file to see the code documentation.

# License

This library is distributed under the permissive MIT License, see the ```LICENSE``` file for additional information.