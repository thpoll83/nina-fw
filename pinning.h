
#define SPI_BUFFER_LEN SPI_MAX_DMA_LEN

#define HSPI_DMACHANNEL 1
#define HSPI_MISO       12
#define HSPI_MOSI       13
#define HSPI_SCLK       14
#define HSPI_SS         15 /* CS */
#define HSPI_READY      16 /* aka busy */
#define HSPI_WP         -1 /* write protect - 4bit QUADWP ? */

#define UART1_TX        1
#define UART1_RX        3
#define UART1_RTS       -1
#define UART1_CTS       -15
#define UART1_BAUD      115200

#define UART2_RX	16

/* camera pins */

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

