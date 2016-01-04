#ifndef __FATAL_H
#define __FATAL_H

#include <stdio.h>
#include <stdlib.h>

#define Error(str)			FaltalError(Str)
#define FatalError(Str)		do{stderr,"%s\n",Str}while(0)


#endif