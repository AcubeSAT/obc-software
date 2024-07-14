/*
 * authors: @Xhulio Luli
 *          @Dimitrios Sourlantzis
 *          @Christina Koutsou
 *          @Grigoris Pavlakis 
 */
/*
 *min basic functions for atsamv71 using Usart in ring buffer mode
 */

#include "inc/min.h"
#include "definitions.h"

//CALLBACK function; Indcates when frame transmission is finished; useful for buffering bytes into a single serial call.
void min_tx_start(uint8_t port){}
void min_tx_finished(uint8_t port){}

// CALLBACK. Must return current buffer space in the given port. Used to check that a frame can be queued.
uint16_t min_tx_space(uint8_t port)
{
  return (uint16_t)USART1_WriteBufferSizeGet();
}

// CALLBACK. Send a byte on the given line.
void min_tx_byte(uint8_t port, uint8_t byte)
{
  USART1_Write(&byte, 1U);
}

// Typically a tick timer interrupt will increment a 32-bit variable every 1ms (e.g. SysTick on Cortex M ARM devices).
uint32_t min_time_ms(void)
{
  return (uint32_t)SYSTICK_TimerCounterGet();
}

