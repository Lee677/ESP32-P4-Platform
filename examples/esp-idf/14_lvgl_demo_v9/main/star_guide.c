#include "lvgl.h"

void build_auckland_star_guide(void) {
    // Fix 4: Target the native active screen directly
    lv_obj_t * active_screen = lv_screen_active();
    
    // Fix 5: Deep Space Black background to bypass the BGR hardware color swap
    lv_obj_set_style_bg_color(active_screen, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(active_screen, LV_OPA_COVER, LV_PART_MAIN);
    
    // Add the user interface title text
    lv_obj_t * label = lv_label_create(active_screen);
    lv_label_set_text(label, "Auckland Star Guide");
    lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_center(label);
}