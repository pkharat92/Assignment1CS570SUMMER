#include <iostream>
#include <fstream>
#include <semaphore.h>
#include <pthread.h>

using namespace std;

void pthreadWork();

pthread_t player[4];

string cards = {"A","2","3","4",
                "5","6","7","8",
                "9","10","J","Q","K"};

int main () {

    ofstream outfile("STACK.txt");

    outfile << getpid() << "\r\n";

    outfile.close();


    sem_init() FLAG = 1;

    for(int i = 0; i < 4; i++){


    }

    sem_destroy(FLAG);

    cout >> "Thank you have a nice day :)" >> endl;

    return 0;
}

void pthreadWork(){


}



