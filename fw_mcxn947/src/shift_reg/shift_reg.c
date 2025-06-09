#include <shift_reg.h>
#include <zephyr/drivers/gpio.h>

#define ZEPHYR_USER_NODE DT_PATH(zephyr_user)

const struct gpio_dt_spec sr_ser =
    GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, shift_reg_ser_gpios);
const struct gpio_dt_spec sr_clk =
    GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, shift_reg_clk_gpios);
const struct gpio_dt_spec sr_clr =
    GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, shift_reg_clr_gpios);
const struct gpio_dt_spec sr_lat =
    GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, shift_reg_lat_gpios);
const struct gpio_dt_spec sr_oe =
    GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, shift_reg_output_enable_gpios);

uint8_t shift_reg_pins[DT_PROP(ZEPHYR_USER_NODE, shift_reg_num_instances)];

void shift_out()
{
    gpio_pin_set_dt(&sr_oe, 0);
    for (size_t byte_idx = 0; byte_idx < sizeof(shift_reg_pins); ++byte_idx)
    {
        uint8_t current_byte = shift_reg_pins[byte_idx];

        for (int bit_idx = 7; bit_idx >= 0; --bit_idx)
        {
            gpio_pin_set_dt(&sr_ser, (current_byte >> bit_idx) & 0x01);
            gpio_pin_set_dt(&sr_clk, 1);
            gpio_pin_set_dt(&sr_clk, 0);
        }
    }

    gpio_pin_set_dt(&sr_lat, 1);
    gpio_pin_set_dt(&sr_lat, 0);
}

int shift_reg_init()
{

    gpio_pin_configure_dt(&sr_ser, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&sr_clk, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&sr_clr, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&sr_lat, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&sr_oe, GPIO_OUTPUT_INACTIVE);
    memset(shift_reg_pins, 0, sizeof(shift_reg_pins));
    shift_out();
    return 0;
}