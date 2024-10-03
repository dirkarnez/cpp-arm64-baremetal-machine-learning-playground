cpp-arm64-baremetal-machine-learning-playground
===============================================
### TODOs
- [ ] neural networks
  - [dirkarnez/cpp-neural-network-playground](https://github.com/dirkarnez/cpp-neural-network-playground)
  - [Kofybrek/Neural-network: A very simple neural network.](https://github.com/Kofybrek/Neural-network)
- [x] Basic printf
- [ ] **Basic read_line**
- [ ] Mali GPU
- [ ] Vivante GPU
- [ ] Multicore
- [ ] SIMD
- [ ] GPIO
  - https://github.com/beckus/stm32_p103_demos/tree/master/demos
- [x] Semihosting USART communication
  - [**QEMU serial console**](https://www.uni-koeln.de/~pbogusze/posts/QEMU_serial_console.html)
  - [RT-Thread-qemu serial udp 无法通信RT-Thread问答社区 - RT-Thread](https://club.rt-thread.org/ask/question/ba9e73756a98ca4a.html)
- [ ] QEMU semihosting
  - [circle/lib/qemu.cpp at 749fe99301846217439a40ac7bda547a986db0f7 · rsta2/circle](https://github.com/rsta2/circle/blob/749fe99301846217439a40ac7bda547a986db0f7/lib/qemu.cpp#L34)
- [ ] update TBuild according to [`raw-build.cmd`](./raw-build.cmd)
- [ ] debugging via QEMU facilities

### QEMU baremetal projects
- [dwelch67/qemu_arm_samples: bare metal ARM examples to be run with qemu-system-arm](https://github.com/dwelch67/qemu_arm_samples)

### QEMU
- [qemu重定向串口serial - zephyr~ - 博客园](https://www.cnblogs.com/lvzh/p/17999381)

### Notes
- Dirty C macros
  - [Expose 'array_length()' macro in <sys/param.h>](https://gcc.gnu.org/pipermail/libstdc++/2020-September/051046.html)
  - [How do I determine the size of my array in C? - Stack Overflow](https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c)
- Floating points does not work
  - try `-mcpu=cortex-a72 -mlittle-endian -marm -mfpu=neon-fp-armv8 -mfloat-abi=hard`
  - It seems QEMU does not support hard float
  - may need armhf compiler
    - https://github.com/sjdh02/trOS/blob/7c64f086a5317c060c4e1b0e9de42ef8d3c2285a/build.zig#L15
    - https://github.com/jasonblog/note/blob/master/toolchain/173.md
    - https://blog.csdn.net/LEON1741/article/details/81537529
    - https://github.com/search?q=qemu-system-aarch64+float&type=code
- Interactivity
  - ![](./docs/teraterm.jpg)
  - Uses `\r\n` for newline in serial
