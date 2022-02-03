#ifndef __TRESORS_H__
#define __TRESORS_H__
#include <stdlib.h>
#include <stdio.h>
#include "debug.h"

float* tr_nouv(int dist, int where, float value);
float* tr_add(float* tr, int dist, int where, float value);
void tr_destroy(float* tr);
void tr_printf(float* tr, int dist);

#endif