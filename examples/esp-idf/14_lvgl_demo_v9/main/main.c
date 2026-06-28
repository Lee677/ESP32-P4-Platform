#pragma GCC diagnostic ignored "-Wstringop-truncation"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "bsp/esp-bsp.h"
#include "lvgl.h"

// Forward declaration of the UI function
void build_auckland_star_guide(void);

void app_main(void)
{
    bsp_display_cfg_t cfg = {
        .lv_adapter_cfg = ESP_LV_ADAPTER_DEFAULT_CONFIG(),
        .rotation = ESP_LV_ADAPTER_ROTATE_0,
        .tear_avoid_mode = ESP_LV_ADAPTER_TEAR_AVOID_MODE_TRIPLE_PARTIAL,
        .touch_flags = {
            .swap_xy = 0,
            .mirror_x = 0,
            .mirror_y = 0
        }
    };

    bsp_display_start_with_config(&cfg);
    bsp_display_backlight_on();

    bsp_display_lock(portMAX_DELAY);
    build_auckland_star_guide();
    bsp_display_unlock();

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}