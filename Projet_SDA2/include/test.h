#ifndef __TEST_H__
#define __TEST_H__

#include "debug.h"
#include <stdbool.h>

    #ifdef DEBUG
    #include "laby.h"
    #endif

/**
 * \fn int test_debug(void);
 * \brief un jeu de test que je me suis crée avant de programmer jusqu'à la 4
 * \return EXIT_SUCESS si reussite
 **/
int test_debug(void);
#endif