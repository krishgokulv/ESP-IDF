#include <stdio.h>
#include "rom/gpio.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN GPIO_NUM_2

void app_main(void)
{
  gpio_pad_select_gpio(LED_PIN);
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
  int ON = 0;
while(true)
{
   ON = !ON;
   gpio_set_level(LED_PIN, ON);
   vTaskDelay(1000/ portTICK_PERIOD_MS);
}
}

