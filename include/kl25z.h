
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

#define NVIC_ISER_BASE 0xE000E100  // Interrupt Set Enable Register
typedef struct {
    volatile uint32_t ISER[1];  // Enable interrupts
} NVIC_Type;
#define NVIC ((NVIC_Type*)NVIC_ISER_BASE)

// IRQ Numbers (KL25Z-specific)
#define PORTA_IRQn 30  // IRQ number for PORTA
typedef struct {
    volatile uint32_t PCR[32];   // Offset 0x00
    uint32_t _reserved[24];      // Padding (optional)
    volatile uint32_t ISFR;      // Offset 0xA0 (Interrupt Status Flag)
} PORT_Type;

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
/ PORT Interrupt Configuration (RM p.185)
#define PORT_PCR_IRQC(x)    ((x) << 16)  // Interrupt configuration field
#define IRQC_FALLING_EDGE   0x0A         // 10 = Falling edge trigger
#define BIT(n)          (1UL << (n))
#define PIN_MUX_GPIO    0x100  // Alternative 1 (GPIO) for PCR registers

#endif // KL25Z_REGISTERS_H
