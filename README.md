cpp-arm64-baremetal-machine-learning-playground
===============================================
### TODOs
- [ ] neural networks
  - [dirkarnez/cpp-neural-network-playground](https://github.com/dirkarnez/cpp-neural-network-playground)
  - [Kofybrek/Neural-network: A very simple neural network.](https://github.com/Kofybrek/Neural-network)
- [x] Basic printf
- [ ] Mali GPU
- [ ] Vivante GPU
- [ ] Multicore
- [ ] GPIO
- [ ] QEMU semihosting
  - [circle/lib/qemu.cpp at 749fe99301846217439a40ac7bda547a986db0f7 · rsta2/circle](https://github.com/rsta2/circle/blob/749fe99301846217439a40ac7bda547a986db0f7/lib/qemu.cpp#L34)
- [ ] update TBuild according to [`raw-build.cmd`](./raw-build.cmd)

### Notes
- Dirty C macros
  - [Expose 'array_length()' macro in <sys/param.h>](https://gcc.gnu.org/pipermail/libstdc++/2020-September/051046.html)
  - [How do I determine the size of my array in C? - Stack Overflow](https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c)
- Floating points does not work
  - try `-mcpu=cortex-a72 -mlittle-endian -marm -mfpu=neon-fp-armv8 -mfloat-abi=hard`
  - It seems QEMU does not support hard float
