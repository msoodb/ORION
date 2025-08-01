
#include "stm32f1xx.h"
#include "FreeRTOS.h"
#include "orion.h"

void ORION_Init(void) {
  // Enable USART1 clock
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

  // Configure PA9 as AF push-pull (TX), PA10 as input floating (RX)
  GPIOA->CRH &= ~(GPIO_CRH_CNF9 | GPIO_CRH_MODE9);
  GPIOA->CRH |= (0b10 << GPIO_CRH_CNF9_Pos) |
                (0b11 << GPIO_CRH_MODE9_Pos); // TX: AF PP, 50MHz

  GPIOA->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_MODE10);
  GPIOA->CRH |= (0b01 << GPIO_CRH_CNF10_Pos); // RX: input floating

  // Configure USART1: 9600 baud @ 72MHz
  USART1->BRR = 72000000 / 9600;
  USART1->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void ORION_Send(const char *data) {
  while (*data) {
    while (!(USART1->SR & USART_SR_TXE))
      ;
    USART1->DR = *data++;
  }
}

void ORION_Receive(char *buffer, int max_len) {
  int i = 0;
  while (i < max_len - 1) {
    while (!(USART1->SR & USART_SR_RXNE))
      ;
    char c = USART1->DR;
    if (c == '\n' || c == '\r')
      break;
    buffer[i++] = c;
  }
  buffer[i] = '\0';
}
