cmake_minimum_required(VERSION 3.20)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXECUTABLE_SUFFIX .elf)
set(CMAKE_CROSSCOMPILING TRUE)


# $(PREFIX)ld --section-start=.text=0 -o $(TARGET).elf $(TARGET).o
# $(PREFIX)objdump -D $(TARGET).elf > $(TARGET).lst
# $(PREFIX)objcopy $(TARGET).elf -O binary $(TARGET).bin

# export AS="$USERPROFILE/Downloads/xpack-aarch64-none-elf-gcc-13.2.1-1.1-win32-x64/xpack-aarch64-none-elf-gcc-13.2.1-1.1/bin/aarch64-none-elf-as.exe"
# export CC="$USERPROFILE/Downloads/xpack-aarch64-none-elf-gcc-13.2.1-1.1-win32-x64/xpack-aarch64-none-elf-gcc-13.2.1-1.1/bin/aarch64-none-elf-gcc.exe"
# export LD="$USERPROFILE/Downloads/xpack-aarch64-none-elf-gcc-13.2.1-1.1-win32-x64/xpack-aarch64-none-elf-gcc-13.2.1-1.1/bin/aarch64-none-elf-ld.exe"

project("cpp-arm64-baremetal-playground" C ASM)



enable_language(ASM)

# find_package(portaudio 19 EXACT REQUIRED) # PATHS "P:\\Downloads\\cpp-libraries\\portaudio\\build\\cmake\\portaudio")

# if(portaudio_FOUND)
#     message(STATUS "YES")
# else()
#     message(STATUS "NO")
# endif()

# set_target_properties(${target} PROPERTIES LINK_DEPENDS ${_cur_link_deps})

# select linker script
set(LINKER_SCRIPT "ld/link_script.ld")

# define CPU OPTIONS
# set(CPU_OPTIONS "-mcpu=cortex-a72")

add_executable(${PROJECT_NAME}
    "src/startup.s"
    "src/main.c"
)

# target_link_libraries(${PROJECT_NAME} $<TARGET_OBJECTS:startup>)
# message("!!!!!!!!!!! $<TARGET_OBJECTS:startup>")

# function(stm32_add_linker_script TARGET VISIBILITY SCRIPT)
#     get_filename_component(SCRIPT "${SCRIPT}" ABSOLUTE)

#     target_link_options(${TARGET} ${VISIBILITY} 
#         -T "${SCRIPT}"
#         -nostartfiles
#         -nostdlib
#     )

#     get_target_property(TARGET_TYPE ${TARGET} TYPE)
#     if(TARGET_TYPE STREQUAL "INTERFACE_LIBRARY")
#         set(INTERFACE_PREFIX "INTERFACE_")
#     endif()

#     get_target_property(LINK_DEPENDS ${TARGET} ${INTERFACE_PREFIX}LINK_DEPENDS)
#     if(LINK_DEPENDS)
#         list(APPEND LINK_DEPENDS "${SCRIPT}")
#     else()
#         set(LINK_DEPENDS "${SCRIPT}")
#     endif()

#     set_target_properties(${TARGET} PROPERTIES ${INTERFACE_PREFIX}LINK_DEPENDS "${LINK_DEPENDS}")
# endfunction()

target_link_options(${PROJECT_NAME} PRIVATE
	-T${CMAKE_SOURCE_DIR}/ld/link_script.ld
	# -mcpu=cortex-m3
	# -mthumb
	# --specs=nano.specs
	# -lc 
    # -lm
    # -lnosys
	# -Wl,--gc-sections
    -nostartfiles
    -nostdlib
)

# stm32_add_linker_script(${PROJECT_NAME} PUBLIC "ld/link_script.ld")


# target_link_options(${PROJECT_NAME}
#   INTERFACE
#   -T "C:/Users/19081126D/Downloads/cpp-arm64-baremetal-playground/ld/link_script.ld")

# add_compile_options(
#     ${CPU_OPTIONS}
#     $<$<COMPILE_LANGUAGE:C>:-std=c11>
#     $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
#     $<$<COMPILE_LANGUAGE:CXX>:-fms-extensions>
#     $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
#     $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
#     $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
#     $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
#     -fstrict-volatile-bitfields
#     -ffunction-sections
#     -fno-threadsafe-statics

#     -Werror
#     -Wall
#     -Wextra
#     -Wcast-align
#     -Wconversion
#     -Wsign-conversion
#     -Wold-style-cast
#     -Wshadow
#     -Wlogical-op
#     -Wsuggest-override
#     -Wsuggest-final-types
#     -Wsuggest-final-methods
#     -pedantic
# )

# $(LD) -T link_script.ld startup.o hello_world.o -o hello_world.elf
# target_link_libraries(${PROJECT_NAME} PRIVATE
#     ${CPU_OPTIONS}
#     -T${LINKER_SCRIPT}
#     -nostartfiles
#     -nostdlib
# )

# target_link_options(${PROJECT_NAME} PRIVATE "-o 1243.elf")
# set_property(TARGET ${PROJECT_NAME} PROPERTY TARGET_FILE_ELF "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.elf")

# set_target_properties(${PROJECT_NAME} PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
# set (CMAKE_STATIC_LINKER_FLAGS "-T ${LINKER_SCRIPT}")

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "bare-metal.elf")
message("LINKER_SCRIPT ${LINKER_SCRIPT}")

# set (CMAKE_EXE_LINKER_FLAGS "-T ${LINKER_SCRIPT}")

# target_link_options(${PROJECT_NAME} PRIVATE "-T 65765 -static")

# target_link_libraries(${PROJECT_NAME} PRIVATE
#     ${CPU_OPTIONS}
#     -T${LINKER_SCRIPT}
#     -nostartfiles
#     -nostdlib
# )


# # Convert output to hex and binary
# add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.hex
# )

# # Convert to bin file -> add conditional check?
# add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
# )


# target_link_options(${PROJECT_NAME} PRIVATE "-static")


message("CMAKE_TOOLCHAIN_FILE ${CMAKE_TOOLCHAIN_FILE}")
message("CMAKE_CXX_LINK_EXECUTABLE  ${CMAKE_CXX_LINK_EXECUTABLE}")
message("CMAKE_MAKE_PROGRAM ${CMAKE_MAKE_PROGRAM}")
message("CMAKE_C_COMPILER ${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER ${CMAKE_CXX_COMPILER}")
message("CMAKE_AR ${CMAKE_AR}")
message("CMAKE_LINKER_TYPE ${CMAKE_LINKER_TYPE}")
message("CMAKE_C_COMPILER_LINKER ${CMAKE_C_COMPILER_LINKER}") # READ ONLY
message("CMAKE_CXX_COMPILER_LINKER ${CMAKE_CXX_COMPILER_LINKER}") # READ ONLY
message("CMAKE_SYSTEM_PROCESSOR ${CMAKE_SYSTEM_PROCESSOR}")