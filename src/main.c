#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"


void led_task()
{
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_us(5);
        // vTaskDelay(100);
        gpio_put(LED_PIN, 0);
        // vTaskDelay(100);
        sleep_us(5);
    }
}

void led_task2()
{
    const uint LED_PIN = 24;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_us(5);
        // vTaskDelay(100);
        gpio_put(LED_PIN, 0);
        // vTaskDelay(100);
        sleep_us(5);
    }
}

int main()
{
    stdio_init_all();

    TaskHandle_t led_task_handle;
    TaskHandle_t led_task2_handle;

    xTaskCreate(led_task, "LED_Task", configMINIMAL_STACK_SIZE, NULL, 1, &led_task_handle);
    vTaskCoreAffinitySet(led_task_handle, 1 << 0);

    xTaskCreate(led_task2, "LED_Task2", configMINIMAL_STACK_SIZE, NULL, 1, &led_task2_handle);
    vTaskCoreAffinitySet(led_task2_handle, 1 << 1);

    vTaskStartScheduler();

    while(1){};
}