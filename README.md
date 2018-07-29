# Ganit Shastra

GanitShastra is a tiny mathematics framework, created with a purpose of learning mathematics and its implementation in a programming language of choice.

## Requirements
[GCC 5.4](https://gcc.gnu.org)

[CMake 3.5](https://cmake.org)

## Build Instructions
### Linux
**Important:** Make sure that you have CMake and GCC installed before building.
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
This will create a static library (at the moment) ```libGanitShastra.a``` in the build directory.

**Note:** Do not do ```sudo make install``` as it is not tested yet. It's best to just copy the statlic lib in your project's directory or any other directory of your choice and use it from there.

## Roadmap
- [ ] Unit tests
- [ ] Documentation
- [ ] Usage examples
- [ ] More implementations
- [ ] Customize build configuration

## License
[MIT License](/LICENSE)