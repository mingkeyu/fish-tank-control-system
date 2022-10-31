set(TARGET_NAME tcp_client_demo)

add_executable(${TARGET_NAME}
        ${TARGET_NAME}.c
        app_main.c
        socket_startup.c
        iot_demo.c
        rotary_encoder.c
        st7789_lcd.c
        )
pico_generate_pio_header(tcp_client_demo ${CMAKE_CURRENT_LIST_DIR}/st7789_lcd.pio)
target_include_directories(${TARGET_NAME} PUBLIC
        ${PORT_DIR}
        )

target_link_libraries(${TARGET_NAME} PRIVATE
        pico_stdlib
        cmsis_core
        CMSIS_FREERTOS_FILES
        hardware_spi
        hardware_pio
        hardware_interp
        hardware_dma
        FREERTOS_FILES
        TIMER_FILES
        WIZFI360_FILES
        IOT_SOCKET_FILES
        )

pico_enable_stdio_usb(${TARGET_NAME} 1)
pico_enable_stdio_uart(${TARGET_NAME} 0)

pico_add_extra_outputs(${TARGET_NAME})
