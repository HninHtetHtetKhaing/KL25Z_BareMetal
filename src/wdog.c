// wdog.c
#include "wdog.h"
#include "kl25z.h"  // Your custom register definitions

void wdog_init(WDOG_CONF wdog_conf) {
    // 1. Unlock watchdog (uses WDOG from kl25z_registers.h)
    WDOG->UNLOCK = 0xC520;
    WDOG->UNLOCK = 0xD928;
    
    // 2. Convert WDOG_CONF enum to register value
    uint32_t reg_value;
    switch (wdog_conf) {
        case WDOG_CONF_DIS: 
            reg_value = 0x01;  // Bit 0 = Disable
            break;
        case WDOG_CONF_LPOCLK_32_CYCLES:
            reg_value = 0x02;  // LPO clock, 32 cycles
            break;
        // ... (other cases)
        default:
            reg_value = 0x01;  // Default: disable
    }
    
    // 3. Configure watchdog
    WDOG->STCTRLH = reg_value;
}

void wdog_refresh(void) {
    WDOG->REFRESH = 0xA602;  // Refresh sequence
    WDOG->REFRESH = 0xB480;
}
