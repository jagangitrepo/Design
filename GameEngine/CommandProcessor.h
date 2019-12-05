/*
    CommandProcessor : This class is used to process the IO request from different sources.
 */

#ifndef CMD_PROCESSOR_H
#define CMD_PROCESSOR_H

#include <iostream>
#include <unistd.h>
#include <queue>
#include "pthread.h"
using namespace std;

// Supported Direction
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

#define MAXSIZE 100

typedef struct
{
    int direction;
} command;

class CommandProcessor
{
private:
    vector<command> cmdQ;
    int rdIndx, wrtIndx;
    bool isExit;
    pthread_mutex_t *cmdQMutex_;
     pthread_t processorThread ;

public:
    CommandProcessor(pthread_mutex_t *cmdQMutex);
    bool QueueCmd(command cmdObj);
    void* CommandProcessorThreadProc(void* data);
    void StartCommandProcessorThread();
};

#endif