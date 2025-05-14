#ifndef TOUCH_H_
#define TOUCH_H_

#include <esp_err.h>
#include <esp_lcd_touch.h>

esp_err_t touch_init(esp_lcd_touch_handle_t *tp);

#endif