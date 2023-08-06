#include <stdio.h>

#include "rom/gpio.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN GPIO_NUM_2 

void led_blink(void* pvParameters) {
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction (LED_PIN,GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED_PIN,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN,1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
	xTaskCreate(led_blink,"LED_BLINK",1024,&led_blink,5,NULL);
}
