#include <iostream>
#include <fstream>
#include <semaphore.h>
#include <pthread.h>
#include <string>

#define NUM_THREADS 4

void *diamond_Card(void *f);
void *club_Card(void *f);
void *heart_Card(void *f);
void *spade_Card(void *f);

//void *pthreadWork();
