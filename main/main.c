/* Path: C:\EspressifIDE\workspace\esp_log_2_1\main
 *
 * Development kit: ESP32S3
 *
 * Author: Victor Adolfo Palacio Bastidas
 *
 * Description:
 * Este codigo realiza tres tareas básicas:
 * 1) Un parpadeo sobre los pines led_A y led_B
 * 2) Muestra el conteo de una variable hasta cierto valor y la presenta por la
 * 	  terminal usando la libreria esp_log.h
 * 3) Explora algunas de las caracteristicas que ofrece la libreria esp_log.h
 * 	  para esto se crean las variables a y b, y se presentan usando la termianl
 *
 * Date: Created on 19 de Enero de 2025, 11:12
 *
 */

#include <stdio.h>
#include "driver/gpio.h"       //Encontrado en: C:\ESP32_ESPRESSIF\v5.2.1\esp-idf\components\driver\gpio\include\driver
#include "freertos/FreeRTOS.h" //Encontrado en: C:\ESP32_ESPRESSIF\v5.2.1\esp-idf\components\freertos\FreeRTOS-Kernel\include\freertos
#include "freertos/task.h"     //Encontrado en: C:\ESP32_ESPRESSIF\v5.2.1\esp-idf\components\freertos\FreeRTOS-Kernel\include\freertos
#include "esp_log.h"           //Encontrado en: C:\ESP32_ESPRESSIF\v5.2.1\esp-idf\components\log\include\esp_log.h

#define LED_A 4        // Pin_06 = Pin compartido con la memoria Flash, no puede ser usado como un pin Input / Output ordinario
#define LED_B 5        // Pin_06 = Pin compartido con la memoria Flash, no puede ser usado como un pin Input / Output ordinario
#define PERIODO_MS 500 // Periodo de tiempo para el blink en ms.

/*
 * Variables globales para el blink de los Leds y para la cuenta del main
 * Variable *Tag para la libreria esp_log*/
uint8_t g_led_level_A_boolean = 1, g_led_level_B_boolean = 0, g_cuenta_uds = 0;
static const char *TAG = "Main";
static const char *TAGA = "config";

char a = 86;
float b = 3.1416;

esp_err_t init_led(void);
esp_err_t parpadearLedA(void);
esp_err_t parpadearLedB(void);

void app_main(void)
{
    init_led(); // Configura los pines a usar
    ESP_LOGI("config", "\n\n---PRUEBAS LIBRERIA ESP-LOG---\r");
    ESP_LOGW("config", "La variable (a) como decimal: %d\r", a);
    ESP_LOGW("config", "La Variable (a) como caracter: %c\r", a);
    ESP_LOGW("config", "La Variable (a) tiene un tamano de %d byte\n", sizeof(a));

    ESP_LOGE("config", "La Variable (b) como float: %f\r", b);
    ESP_LOGE("config", "La Variable (b) tiene un tamano de %d bytes\r", sizeof(b));
    ESP_LOGE("config", "(2.55) es otro float %f\n", 2.55);

    ESP_LOGI("config", "La Variable a: %d\t y la Variable b: %f\r", a, b);
    ESP_LOGI("config", "(6.02e23) como exponente %e\r", 6.02e-3);
    ESP_LOGI("config", "Victor como string \n");

    while (1)
    {
        vTaskDelay(PERIODO_MS / portTICK_PERIOD_MS);
        parpadearLedA();
        parpadearLedB();
        printf("Led level A:%u\n", g_led_level_B_boolean);
        printf("Led level B:%u\n", g_led_level_A_boolean);

        /*Cuenta hasta 50 y se resetea hasta alcanzar este valor*/
        g_cuenta_uds += 1;
        if (g_cuenta_uds > 50)
        {
            g_cuenta_uds = 0;
        }

        /*!
         * @brief Con el incremento de la variable g_cuenta_uds se controla el
         * flujo del código, según el valor de esta variable se realizan
         * diferentes acciones como tipos de impresion para probar la libria que
         * se está usando (esp_log)*/

        if (g_cuenta_uds < 10)
        {
            ESP_LOGI(TAG, "VALOR g_cuenta_uds: %u.", g_cuenta_uds);
        }

        if (g_cuenta_uds >= 10 && g_cuenta_uds < 20)
        {
            ESP_LOGW(TAG, "VALOR g_cuenta_uds: %u.", g_cuenta_uds);
        }

        if (g_cuenta_uds > 20)
        {
            ESP_LOGE(TAG, "VALOR g_cuenta_uds: %u.", g_cuenta_uds);
        }
    }
}

esp_err_t init_led(void)
{
    gpio_reset_pin(LED_A);
    gpio_set_direction(LED_A, GPIO_MODE_OUTPUT);

    gpio_reset_pin(LED_B);
    gpio_set_direction(LED_B, GPIO_MODE_OUTPUT);
    return ESP_OK;
}

esp_err_t parpadearLedB(void)
{
    g_led_level_B_boolean = !g_led_level_B_boolean;
    gpio_set_level(LED_B, g_led_level_B_boolean);
    return ESP_OK;
}

esp_err_t parpadearLedA(void)
{
    g_led_level_A_boolean = !g_led_level_A_boolean;
    gpio_set_level(LED_A, g_led_level_A_boolean);
    return ESP_OK;
}
