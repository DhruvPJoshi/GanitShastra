# Ganit Shastra

GanitShastra is a tiny mathematics framework, created with a purpose of learning mathematics and its implementation in a programming language of choice.

## Requirements
[GCC 5.4](https://gcc.gnu.org)

[CMake 3.5](https://cmake.org)

[CppUTest 3.8](https://cpputest.github.io) (_Optional_, to build tests)

## Build Instructions
### Linux
**Important:** Make sure that you have CMake, GCC and CppUTest (optional) installed before building.
1) Clone this repository and change into it
```bash
git clone https://github.com/DhruvPJoshi/GanitShastra.git
cd GanitShastra
```
2) Create a build directory and change into it
```bash
mkdir build && cd build
```
3) Build the library

```bash
cmake -DCMAKE_BUILD_TYPE=Release .. && make
```
* Optionally, you can turn on the ```COMPILE_TESTS``` flag to build the tests. In such case, make sure that you have [_CppUTest_](#requirements) setup and configured properly on your system. i.e.
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DCOMPILE_TESTS=ON .. && make
```

This will create a static library (at the moment) ```libGanitShastra.a``` in the build directory.

**Note:** Do not perform ```sudo make install``` as it is not tested yet. It's best to just copy the statlic lib in your project's directory or any other directory of your choice and use it from there. Usage instructions will be provided soon. Checkout the [roadmap](#roadmap).

## Roadmap
- [ ] Unit tests
- [ ] Documentation
- [ ] Usage examples
- [ ] More implementations
- [ ] Customize build configuration

## License
[MIT License](/LICENSE)