#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <errno.h> // errno
#include <stdio.h> // perror
#include <stdarg.h> // check / raler
#include <stdnoreturn.h> // check / raler
#include <stdlib.h> // EXIT_FAILURE

#define DEBUG 88
#define EXIT_DEBUG 1

//AINSI escape codes de quelques couleurs:
#define RED "\033[1;31m" 
#define YELLOW "\033[1;33m"
#define lGREEN "\033[1;32m"
#define GREEN "\033[0;32m"
#define lBLUE "\033[1;34m"
#define BOLD "\033[1;38m"
#define NC "\033[0m"// no color

//macros pour DEBUG
#define HERE  YELLOW, __FILE__, NC, YELLOW, __FUNCTION__,NC, YELLOW, __LINE__, NC, RED, NC
#define WHERE "in file %s%s%s, function %s%s%s, at line %s%d%s, %sERREUR:  %s%s%s"

#define RALER(num, msg) do { raler(num,WHERE, HERE, BOLD, msg, NC); } while (0);
#define CHECK(op) do { if ((op) == -1) RALER(1,#op); } while (0);
#define FCHECK(op) do { if ((op) < 0) RALER(1,#op); } while (0); //ftell, fseek
/**
 * \fn void noeuds(const noeud* noeuds, const int x)
 * \brief fonction d'affichage d'erreur
 * \param syserr 1 si c'est une primite, autre sinon
 * \param msg les chaines de char à print
 * \return void
 **/
void raler (int syserr, const char *msg, ...);

#endif