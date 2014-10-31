#ifndef _RANDOM_H_
    #define _RANDOM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*One function to get structure of random 4096 byte string and structure for that data.*/

FILE* random;//random file pointer


unsigned char GetCRandom();//get c random character

unsigned char GetFileRandom();//get file random character

void File();//run test for file

void CRand();//run test for c random function

#endif
