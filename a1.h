#include <iostream>
#include <fstream>
#include <semaphore.h>
#include <pthread.h>
#include <string>

#define NUM_THREADS 4


void *pthreadWork();
