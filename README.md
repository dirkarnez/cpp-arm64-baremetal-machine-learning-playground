cpp-arm64-baremetal-playground
==============================

From https://github.com/dirkarnez/qemu-cortex-a7-baremetal

### TODOs
- [x] delete CMake?
  - CMake is totally not embedded-friendly
- [ ] remove direct referencing to startup.o inside `link_script.ld`, which CMake cannot do directly
  - https://github.com/mincrmatt12/MSynth/blob/60c761be8adcbf22b4b2969b076bf5ad3cd17c99/framework/build.cmake#L114
- [ ] Create UBoot template
  - https://github.com/whzinformatik/baremetal-arm/tree/b9574aacf8c07305f239d9e0a01d07b86f2cc5ce/src/05_cmake
- [ ] Build as cli for testing

### Tutorials
- https://github.com/five-embeddev/riscv-scratchpad/blob/master/baremetal-startup-c/src/timer.c
- https://github.com/whzinformatik/baremetal-arm/blob/master/doc/05_cmake.md?plain=1
- [**adafruit/tinyuf2: UF2 bootloader based on TinyUSB for embedded devices such as ESP32S2, STM32F4 and iMX RT10xx**](https://github.com/adafruit/tinyuf2/tree/master)
- [gnif/STM32F103-BareMetal: Bare Metal STM32F103 CMake project without any external dependencies.](https://github.com/gnif/STM32F103-BareMetal)
- https://github.com/coder137/STM32-Repo/tree/master/Baremetal
- https://github.com/CharlesDias/stm32_gtest_c_code
- [**cortexm/baremetal: ARM Cortex-M bare-metal example code in C++ and CMake build**](https://github.com/cortexm/baremetal)
- [BlackBoxes/systems/baremetal at master · NoBlackBoxes/BlackBoxes](https://github.com/NoBlackBoxes/BlackBoxes/tree/master/systems/baremetal)

### Toolchains
- **https://github.com/Xilinx/embeddedsw-experimental-dt-support/tree/master/cmake/toolchainfiles**
- https://github.com/Tencent/ncnn/blob/master/toolchains/riscv64-unknown-elf.toolchain.cmake
