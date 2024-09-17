/**
 * @file   mm.h
 * @Author 02335 team
 * @date   September, 2024
 * @brief  Memory management header file.
 *
 */

#include <stddef.h>
#include <stdint.h>


/**
 * @name    simple_malloc
 * @brief   Allocate at least size contiguous bytes of memory and return a pointer to the first byte.
 * @retval  Pointer to the start of the allocated memory or NULL if not possible.
 */
void * simple_malloc(size_t size);


/**
 * @name    simple_free
 * @brief   Frees previously allocated memory and make it available for subsequent calls to simple_malloc.
 */
void simple_free(void * ptr);


/**
 * @name    The lowest address of the memory you will manage
 * @brief   This points to the lowest address of memory you will manage
 */
extern const uintptr_t memory_start;


/**
 * @name    The limit of the memory you will manage
 * @brief   This points to the first address of memory you will NOT manage
 */
extern const uintptr_t memory_end;


