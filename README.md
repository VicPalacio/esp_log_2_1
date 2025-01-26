# ESP32 y ESP_LOG

En este proyecto se hace una breve demostración de la librería LOG que se utiliza de la misma forma que printf pero la diferencia es que cuenta con clasificación de tipos de mensaje como informativos en color verde, advertencia en color amarillo y error en color rojo, la documentación de esta librería está disponible en el siguiente enlace:

https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/system/log.html#logging-library

Este codigo realiza tres tareas básicas:

1.  Un parpadeo sobre los pines led_A y led_B
2.  Muestra el conteo de una variable hasta cierto valor y la presenta por la terminal usando la libreria esp_log.h
3.  Explora algunas de las caracteristicas que ofrece la libreria esp_log.h para esto se crean las variables a y b, y se presentan usando la terminal, se muestran las variables en diferentes tipos como:

- Decimal
- Caracter
- Float
- String
  Y algunas secuencias de escape como:

| Secuencia de escape | Representa       |
| ------------------- | ---------------- |
| \r                  | Retorno de carro |
| \n                  | Nueva línea      |

## Código ejemplo demostrativo:

En el proyecto se mostrará una sección de código que permitirá hacer una breve demostración:

```
    ESP_LOGI("config","\n\n---PRUEBAS LIBRERIA ESP-LOG---\r");
    ESP_LOGW("config","La variable (a) como decimal: %d\r", a);
    ESP_LOGW("config","La Variable (a) como caracter: %c\r", a);
    ESP_LOGW("config","La Variable (a) tiene un tamano de %d byte\n",sizeof(a));
    ESP_LOGE("config","La Variable (b) como float: %f\r", b);
    ESP_LOGE("config","La Variable (b) tiene un tamano de %d bytes\r", sizeof(b));
    ESP_LOGE("config","(2.55) es otro float %f\n", 2.55);
    ESP_LOGI("config","La Variable a: %d\t y la Variable b: %f\r", a,b);
    ESP_LOGI("config","(6.02e23) como exponente %e\r",6.02e-3);
    ESP_LOGI("config","Victor como string \n");
```

## Fin
