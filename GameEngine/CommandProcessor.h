/*
    CommandProcessor : This class is used to process the IO request from different sources.
 */

#ifndef CMD_PROCESSOR_H
#define CMD_PROCESSOR_H

#include <queue>
#include <pthread>
using namespace std;

// Supported Direction
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

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

public:
    CommandProcessor(pthread_mutex_t *cmdQMutex);
    bool QueueCmd(command cmdObj);
    void CommandProcessorThreadProc();
};

#endif