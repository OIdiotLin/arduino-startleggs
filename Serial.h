#include <Arduino.h>
#pragma once
#ifndef SERIAL_H
#define SERIAL_H
void sendMsg(char *msg);
void sendMsg(int n);
int readInt();
#endif // !SERIAL_H
