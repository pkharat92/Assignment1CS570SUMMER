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

const char* cards[13] = {"A","2","3","4",
                    "5","6","7","8",
                    "9","10","J","Q","K"};

//void *pthreadWork();
