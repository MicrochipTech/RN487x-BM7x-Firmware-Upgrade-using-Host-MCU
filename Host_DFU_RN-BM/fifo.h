/* 
   lock-free FIFO, used to receive data in ISR context,
   and process it in Main context
   for optimization size MUST be power of 2, ie 2, 4, 8, 16, 32, ...
*/
#include <stdint.h>
#include <stdbool.h>
typedef struct fifo_handle_tag
{
    volatile uint32_t wr_idx; // counter for FIFO input, inc in ISR only
    volatile uint32_t rd_idx; // counter for FIFO output, inc in MAIN only
    uint32_t size;            // FIFO buffer size
    uint32_t mask;            // Mask to extract buffer index from counters
    uint8_t *buffer;          // FIFO buffer
} fifo_t;
uint8_t fifo_init(fifo_t *const fifo, uint8_t *const buffer, const uint32_t size);
uint8_t fifo_empty(fifo_t *const fifo);
uint8_t fifo_full(fifo_t *const fifo);
uint8_t fifo_get(fifo_t *const fifo, uint8_t *const byte);
uint8_t fifo_put(fifo_t *const fifo, const uint8_t byte);
