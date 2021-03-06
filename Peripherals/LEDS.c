#include <string.h>
#include "systick.h"
#include "ws2812b.h"
#include "directives.h"
#include "stm32f0xx_ll_bus.h"

static uint8_t ledArray[3]; // RGB LED colour place

void LEDS_init(void)
{
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    ws2812b_initPort();
    delay(10);
    memset(ledArray, 0, sizeof (ledArray)); // initial Color set (==Black)
    ws2812b_sendArray(ledArray, 4);
    delay(10);
}

void LEDS_setColor(uint8_t *color)
{

    memcpy(&ledArray[0], color, 3);
}

void LEDS_show(void)
{
    
    ws2812b_sendArray(ledArray, 4);
}
