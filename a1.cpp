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

/**
 * This is the main function. It creates a file 'STACK.txt' and 
 * gets the process ID. The function then creates the semaphore 
 * and four threads, and calls the respective functions for each 
 * thread to output to a file. After all the threads are done, 
 * the semaphore is destroyed an a nice message is left.
 */
int main () {

    outfile.open("STACK.txt", fstream::out | fstream::trunc);

    outfile << getpid() << "\r\n\n";

    outfile.close();

    sem_init(&FLAG,0,1); //Initialize the FLAG

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
} // End main()

/**
 * This prints out the suit and each card in that suit to the 
 * 'STACK.txt' file. The thread prints a card at certain 
 * intervals. The semaphore is used for the thread to wait
 * until it needs to output to a file.
 */
void *diamond_Card(void *i){

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() <<" is running" << endl;

        outfile << "Diamond " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(125);
    }

    pthread_exit(NULL);
} // End diamond_Card()

/**
 * This prints out the suit and each card in that suit to the 
 * 'STACK.txt' file. The thread prints a card at certain 
 * intervals. The semaphore is used for the thread to wait
 * until it needs to output to a file.
 */
void *club_Card(void *i){

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() <<" is running" << endl;

        outfile << "Club " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(250);
    }
    pthread_exit(NULL);
} // End club_Card()

/**
 * This prints out the suit and each card in that suit to the 
 * 'STACK.txt' file. The thread prints a card at certain 
 * intervals. The semaphore is used for the thread to wait
 * until it needs to output to a file.
 */
void *heart_Card(void *i){

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() <<" is running" << endl;

        outfile << "Heart " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(500);
    }
        pthread_exit(NULL);
} // End heart_Card()

/**
 * This prints out the suit and each card in that suit to the 
 * 'STACK.txt' file. The thread prints a card at certain 
 * intervals. The semaphore is used for the thread to wait
 * until it needs to output to a file.
 */
void *spade_Card(void *i){

    for(int i = 0; i < 13; i++){

        sem_wait(&FLAG);

        outfile.open("STACK.txt", fstream::app);

        cout << "Thread " << pthread_self() << " is running" << endl;

        outfile << "Spade " << cards[i] << "\r\n";

        outfile.close();

        sem_post(&FLAG);

        usleep(750);
    }
        pthread_exit(NULL);
} // End spade_Card()
