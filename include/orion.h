#ifndef ORION_H
#define ORION_H

void ORION_Init(void);
void ORION_Send(const char *data);
void ORION_Receive(char *buffer, int max_len);

#endif // ORION_H
