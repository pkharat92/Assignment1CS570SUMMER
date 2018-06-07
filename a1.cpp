/*
    Assignment 1 CS 570
    Guy Leonard

    Pierre Kharat
    Alfonso Herrera



*/

#include "a1.h"

using namespace std;

pthread_t player[NUM_THREADS]; //Defining the number of threads

sem_t FLAG; //Flag for mutual exclusion purposes

fstream outfile;

int main () {

    outfile.open("STACK.txt", fstream::out | fstream::trunc);

    outfile << getpid() << "\r\n\n";

    outfile.close();

    sem_init(&FLAG,0,1); //Initialize the FLAGb

    pthread_create(&player[0], NULL, &diamond_Card, NULL); //
    pthread_create(&player[1], NULL, &club_Card, NULL); //
    pthread_create(&player[2], NULL, &heart_Card, NULL); //
    pthread_create(&player[3], NULL, &spade_Card, NULL); //

    pthread_join(player[0],NULL);
    pthread_join(player[1],NULL);
    pthread_join(player[2],NULL);
    pthread_join(player[3],NULL);

    sem_destroy(&FLAG);

    cout << "Thank you have a nice day :)" << endl;

    return 0;
}

void *diamond_Card(void *i){

    unsigned int microseconds = 125;

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() <<" is running" << endl;

        outfile << "Diamond " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(microseconds);
    }

    pthread_exit(NULL);
}

void *club_Card(void *i){

    unsigned int microseconds = 250;

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() <<" is running" << endl;

        outfile << "Club " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(microseconds);
    }
    pthread_exit(NULL);
}

void *heart_Card(void *i){

    unsigned int microseconds = 500;

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() <<" is running" << endl;

        outfile << "Heart " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(microseconds);
    }
        pthread_exit(NULL);
}

void *spade_Card(void *i){

    unsigned int microseconds = 750;

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() << " is running" << endl;

        outfile << "Spade " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(microseconds);
    }
        pthread_exit(NULL);
}
