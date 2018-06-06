/*
    Assignment 1 CS 570
    Guy Leonard

    Alfonso Herrera
    Pierre Kharat


*/

#include "a1.h"

using namespace std;

//static void *pthreadWork(void *num);



pthread_t player[NUM_THREADS]; //Defining the number of threads

sem_t FLAG; //Flag for mutual exclusion purposes

int main () {

    ofstream outfile("STACK.txt");

    outfile << getpid() << "\r\n";

    outfile.close();

    sem_init(&FLAG,0,1); //Initialize the FLAGb


    for(int i = 0; i < 4; i++){

        switch(i){

        case 0: // Diamond runs its job
            pthread_create(&player[0], NULL, &diamond_Card, (void *)FLAG); //

        case 1: // Clubs runs its job
            pthread_create(&player[1], NULL, &club_Card, (void *)FLAG); //

        case 2: // Hearts runs its job
            pthread_create(&player[2], NULL, &heart_Card, (void *)FLAG); //

        case 3: // Spades runs its job
            pthread_create(&player[3], NULL, &spade_Card, (void *)FLAG); //
        }
    }

    sem_destroy(&FLAG);

    cout << "Thank you have a nice day :)" << endl;

    pthread_exit(NULL);

    return 0;
}

//void *pthreadWork(void *num){ //Just trying to
//    cout << endl << cards[(int) num] << endl;
//}

void *diamond_Card(void *f){

    cout << cards[0] << " Diamond"<< endl;
    pthread_exit(NULL);
}

void *club_Card(void *f){

    cout << cards[2] << " Club"<< endl;
    pthread_exit(NULL);
}

void *heart_Card(void *f){

    cout << cards[9] << " Heart"<< endl;
    pthread_exit(NULL);
}

void *spade_Card(void *f){

    cout << cards[12] << " Spade"<< endl;
    pthread_exit(NULL);
}
