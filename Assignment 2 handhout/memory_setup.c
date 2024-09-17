/**
 * @file   mm.c
 * @Author 02335 team
 * @date   September, 2024
 * @brief  Memory management skeleton.
 * 
* This file contains low level initialization of memory. You should
 * not need to edit this file as part of the assignment.
 *
 */

#include "mm.h"

#define ALLOCATE_SIZE    32*1024*1024                 // 32 MB
#define SKEW_SIZE        10

static int8_t skew[SKEW_SIZE];                        // Misalignment
static int8_t memory[ALLOCATE_SIZE];

const uintptr_t memory_start =  (uintptr_t) memory;
const uintptr_t memory_end   =  (uintptr_t) memory + ALLOCATE_SIZE;
