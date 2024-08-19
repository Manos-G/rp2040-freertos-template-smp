cmake_minimum_required(VERSION 3.12)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Name project
set(ProjectName rp2040-freertos-template)

# Set any variables required for importing libraries
set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS-Kernel)

# Import those libraries
include(pico_sdk_import.cmake)
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

# Define project
project(${ProjectName})

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Define the executable target
add_executable(${ProjectName}
    src/main.c
)

# Include directories
target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src
)

# Link the necessary libraries
target_link_libraries(${ProjectName} 
    pico_stdlib
    pico_multicore
    FreeRTOS-Kernel-Heap4
)

# Enable USB output, disable UART output
pico_enable_stdio_usb(${ProjectName} 1)
pico_enable_stdio_uart(${ProjectName} 0)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${ProjectName})
