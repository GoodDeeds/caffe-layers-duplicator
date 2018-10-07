# Caffe-Layers-Duplicator

A simple program to automatically make copies of network layers in the Caffe prototxt format with some restrictions. This can be used to create multiple parallel copies of the network.

## Setup and Usage
### Prerequisites
GNU make is used as the build mechanism. A C++ compiler (such as g++) with C++11 support is required to build the program. To use compilers other than g++, please edit the [Makefile](Makefile) appropriately.

### Building the program
To compile, use
```bash
$ make
```

To clean up built files, use
```bash
$ make clean
```

### Running the program
Use
```bash
$ ./caffe_layers_duplicator
```
and follow the instructions.

## License
This program is provided under the [MIT License](LICENSE).