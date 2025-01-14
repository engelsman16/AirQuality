#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"

// ==========================================================================
// DRIVER INCLUDES

#include "driver/i2c_master.h"

// ==========================================================================
// GLOBAL DEFINES 

static const char* GLOBAL_TAG __attribute((used)) = "GLOBAL_LOGGER";

// ===========================================================================


void app_main(void)
{
    ESP_LOGI(GLOBAL_TAG, "Initialised");

    // configure i2c master
    i2c_master_bus_config_t i2c_master_config = {
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .i2c_port = TEST_I2C_PORT,
    .scl_io_num = I2C_MASTER_SCL_IO,
    .sda_io_num = I2C_MASTER_SDA_IO,
    .glitch_ignore_cnt = 7,
    .flags.enable_internal_pullup = true,
    };

    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_master_config, &bus_handle));

    // configure slave device
    i2c_device_config_t device_config_bme640 = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = 0x58,
    .scl_speed_hz = 100000,
    };

    i2c_master_dev_handle_t device_handle_bme640;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &device_config_bme640, &device_handle_bme640));

    // read data from slave device
    ESP_ERROR_CHECK(i2c_master_receive(***));
    
}