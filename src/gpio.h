// https://github.com/cpq/bare-metal-programming-guide

#pragma once

#define GPIO_ADDR(bank) ((gpio_t*)(0x40020000 + 0x400 * (bank)))

#include "util.h"
#include <stdint.h>


typedef struct gpio_t {
    volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFRL, AFRH;
} gpio_t;

// Values as per datasheetL 0-3
typedef enum gpio_mode_enum {
    GPIO_MODE_IN, GPIO_MODE_OUT, GPIO_MODE_AF, GPIO_MODE_ANALOG
} gpio_mode_t;

typedef enum gpio_speed_enum {
    GPIO_SPEED_LOW, GPIO_SPEED_MEDIUM, GPIO_SPEED_HIGH, GPIO_SPEED_MAX
} gpio_speed_t;

typedef enum gpio_port_enum {
    GPIO_PORT_A, GPIO_PORT_B, GPIO_PORT_C, GPIO_PORT_D, GPIO_PORT_E, GPIO_PORT_F, GPIO_PORT_G, GPIO_PORT_H, GPIO_PORT_I, GPIO_PORT_J, GPIO_PORT_K
} gpio_port_t;

typedef enum gpio_out_mode_enum {
    GPIO_OUTMODE_PUSH_PULL, GPIO_OUTMODE_OPEN_DRAIN
} gpio_out_mode_t;

typedef enum gpio_pull_enum {
    GPIO_PULL_NONE, GPIO_PULL_UP, GPIO_PULL_DOWN
} gpio_pull_t;


static inline void gpio_set_mode(gpio_port_t port, uint8_t pin, gpio_mode_t mode) {
    SET_BITS(GPIO_ADDR(port)->MODER, 2, pin * 2, mode);
    //gpio_t *gpio = GPIO_ADDR(port);
    //gpio->MODER &= ~(0b11 << (pin * 2));
    //gpio->MODER |= (mode & 3) << (pin * 2);
}

static inline void gpio_set_pull(gpio_port_t port, uint8_t pin, gpio_pull_t pull) {
    SET_BITS(GPIO_ADDR(port)->PUPDR, 2, pin * 2, pull);
}

static inline void gpio_set_out_mode(gpio_port_t port, uint8_t pin, gpio_out_mode_t outmode) {
    SET_BIT(GPIO_ADDR(port)->OTYPER, pin, outmode);
}

static inline void gpio_set_speed(gpio_port_t port, uint8_t pin, gpio_mode_t mode) {
    SET_BITS(GPIO_ADDR(port)->OSPEEDR, 2, pin * 2, mode);
}

static inline uint8_t gpio_read(gpio_port_t port, uint8_t pin) {
    return GET_BIT(GPIO_ADDR(port)->IDR, pin);
}

static inline void gpio_out_level(gpio_port_t port, uint8_t pin, uint8_t level) {
    SET_BITS(GPIO_ADDR(port)->ODR, 1, pin, level > 0);
}

static inline void gpio_out_high(gpio_port_t port, uint8_t pin) {
    GPIO_ADDR(port)->BSRR = 1 << pin;
}

static inline void gpio_out_low(gpio_port_t port, uint8_t pin) {
    GPIO_ADDR(port)->BSRR = 1 << (pin + 16);
}

static inline void gpio_toggle(gpio_port_t port, uint8_t pin) {
    GPIO_ADDR(port)->ODR ^= 1 << pin;
}

static inline void gpio_set_alt_func(gpio_port_t port, uint8_t pin, uint8_t af) {
    gpio_t *gpio = GPIO_ADDR(port);
    volatile uint32_t *afr = pin < 8 ? &gpio->AFRL : &gpio->AFRH;
    uint8_t bp = pin < 8 ? pin : pin - 8;
    SET_BITS(*afr, 4, bp, af & 0b1111);
}