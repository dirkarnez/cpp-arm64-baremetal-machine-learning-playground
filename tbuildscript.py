from pathlib import Path
from tbuild import TBuild

tbuild = TBuild(Path.home() / "Downloads" / "arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf" / "arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf" / "bin", "aarch64-none-elf-")
# tbuild = TBuild(Path("D:") / "Softwares" / "winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1" / "mingw64" / "bin", "")

tbuild.build_an_object(
  tbuild.get_gcc(),
  "main.c", 
  "main.o"
)

tbuild.assemble_an_object(
  tbuild.get_assembler(),
  "startup.s", 
  "startup.o"
)

tbuild.link_an_executable_from_object_files(
  tbuild.get_linker(),
  "link_script.ld",
  ["startup.o", "main.o"],
  "main.elf",
  "-nostdlib"
)

tbuild.build()

print()


# https://github.com/dirkarnez/qemu-cortex-a7-baremetal/blob/main/Makefile
# hello_world.elf: link_script.ld startup.o hello_world.o
# 	# Link the two object files to an elf file
# 	$(LD) -T link_script.ld startup.o hello_world.o -o  ello_world.elf

# startup.o: startup.s
# 	$(AS) -o startup.o startup.s

# hello_world.o: hello_world.c
# 	$(CC) -c -o hello_world.o hello_world.c

# clean:
# 	rm -f hello_world.o startup.o hello_world.elf

