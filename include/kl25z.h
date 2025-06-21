
// Reference: KL25P80M48SF0RM (NXP KL25Z Reference Manual)

#ifndef KL25Z_REGISTERS_H
#define KL25Z_REGISTERS_H

#include <stdint.h>

// =============================================
// Memory Addresses (from KL25Z RM p.55)
// =============================================
#define WDOG_BASE    0x40052000  // Watchdog Timer
#define PORTA_BASE   0x40049000  // PORT A Control
#define PORTB_BASE   0x4004A000  // PORT B Control
#define PORTC_BASE   0x4004B000  // PORT C Control
#define GPIOA_BASE   0x400FF000  // GPIO A Data
#define GPIOB_BASE   0x400FF040  // GPIO B Data
#define GPIOC_BASE   0x400FF080  // GPIO C Data

// =============================================
// Register Structures
// =============================================



// PORT Control (RM p.183)
typedef struct {
    volatile uint32_t PCR[32];  // Pin Control Registers
} PORT_Type;

// GPIO Control (RM p.894)
typedef struct {
    volatile uint32_t PDOR;  // Data Output
    volatile uint32_t PSOR;  // Set Output
    volatile uint32_t PCOR;  // Clear Output
    volatile uint32_t PTOR;  // Toggle Output
    volatile uint32_t PDIR;  // Data Input
    volatile uint32_t PDDR;  // Data Direction
} GPIO_Type;

// =============================================
// Peripheral Instances
// =============================================
#define PORTA   ((PORT_Type*)PORTA_BASE)
#define PORTB   ((PORT_Type*)PORTB_BASE)
#define PORTC   ((PORT_Type*)PORTC_BASE)
#define GPIOA   ((GPIO_Type*)GPIOA_BASE)
#define GPIOB   ((GPIO_Type*)GPIOB_BASE)
#define GPIOC   ((GPIO_Type*)GPIOC_BASE)

// =============================================
// Bit Manipulation Macros
// =============================================
#define BIT(n)          (1UL << (n))
#define PIN_MUX_GPIO    0x100  // Alternative 1 (GPIO) for PCR registers

#endif // KL25Z_REGISTERS_H
