#ifndef RGB_H
#define RGB_H

#include <stdint.h>
#include <stdio.h>

#define BUFFER_SIZE 512

void log_variable(const char *name, int value);
void LOG_POST();

#define LOG_VAR(v) log_variable(#v, v)

#endif /* RGB_h */