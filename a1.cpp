/*
    Assignment 1 CS 570
    Guy Leonard

    Alfonso Herrera
    Pierre Kharat


*/

#include "a1.h"

using namespace std;

static void *pthreadWork(void *num);

pthread_t player[NUM_THREADS]; //Defining the number of threads

sem_t FLAG; //Flag for mutual exclusion purposes

const char* cards[13] = {"A","2","3","4",
                    "5","6","7","8",
                    "9","10","J","Q","K"};

int main () {

    ofstream outfile("STACK.txt");

    outfile << getpid() << "\r\n";

    outfile.close();


    sem_init(&FLAG,0,1);

    for(int i = 0; i < 4; i++){

        pthread_create(&player[i], NULL, pthreadWork,(void *)i); //For testing purposes just passing the variable "i" as an argument

    }

    sem_destroy(&FLAG);

    cout << "Thank you have a nice day :)" << endl;

    pthread_exit(NULL);

    return 0;
}

void *pthreadWork(void *num){ //Just trying to
    cout << endl << cards[(int) num] << endl;
}



