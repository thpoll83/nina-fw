#include "CameraFunctions.h"

#include "esp32-hal-psram.h"
#include "esp_camera.h"
#include "img_converters.h"

#include "Arduino.h"

#include <SPIS.h>
#include "../pinning.h"

int initCamera(const uint8_t command[], uint8_t response[])
{
  response[2] = 1; // number of parameters
  response[3] = 1; // parameter 1 length

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  //init with high specs to pre-allocate larger buffers
  if(psramInit()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    response[4] = 0;
    return 6;
  }

  sensor_t * s = esp_camera_sensor_get();

  //drop down frame size for higher initial frame rate
  s->set_framesize(s, FRAMESIZE_QVGA);

  response[4] = 1;

  return 6;
}

int getCameraFB(const uint8_t command[], uint8_t response[])
{
    response[2] = 1; // number of parameters

    camera_fb_t * fb = NULL;

    fb = esp_camera_fb_get();
    if (!fb) {
        response[3] = 1; // parameter 1 length
        response[4] = 0;
        return 6;
    }

    if(fb->format == PIXFORMAT_JPEG && fb->len <= SPI_BUFFER_LEN){
        response[3] = fb->len; // parameter 1 length
        memcpy(&response[4], fb->buf, fb->len);
    } else {
        /*if(frame2jpg_(fb, 80, &&response[4], &response[3]) != ESP_OK)
        {
            esp_camera_fb_return(fb);
            response[3] = 1; // parameter 1 length
            response[4] = 0;
            return 6;
        }*/
        response[3] = 1; // parameter 1 length
        response[4] = 0;
        return 6;
    }
    esp_camera_fb_return(fb);
    return 6;
    
}
