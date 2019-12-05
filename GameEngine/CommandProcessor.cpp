#include "CommandProcessor.h"

typedef void* (*THREADFUNCPTR) (void*);

CommandProcessor::CommandProcessor(pthread_mutex_t *cmdQMutex) : cmdQ(MAXSIZE), rdIndx(0), wrtIndx(0), isExit(false)
{
    cmdQMutex_ = cmdQMutex;
}

bool CommandProcessor::QueueCmd(command cmdObj)
{
    pthread_mutex_lock(cmdQMutex_);
    cmdQ[++wrtIndx % MAXSIZE] = cmdObj;
    pthread_mutex_unlock(cmdQMutex_);
}

void CommandProcessor::StartCommandProcessorThread()
{
    pthread_create(&processorThread, NULL, (THREADFUNCPTR)&CommandProcessorThreadProc, NULL);
    //pthread_join(processorThread, NULL);
}
void* CommandProcessor::CommandProcessorThreadProc(void * data)
{
    cout << "CommandProcessorThreadProc: Thread is started ThreadID: "<< endl;
    while (!isExit)
    {
        if (!cmdQ.empty())
        {
            cout << "CommandProcessorThreadProc: got some data  !... " << endl;
            command cmdObj;

            pthread_mutex_lock(cmdQMutex_);
            cmdObj = cmdQ[rdIndx++ % MAXSIZE];
            pthread_mutex_unlock(cmdQMutex_);

            switch (cmdObj.direction)
            {
            case LEFT:
                cout << "LEFT" << endl;
                break;
            case RIGHT:
                cout << "RIGHT" << endl;
                break;
            case UP:
                cout << "UP" << endl;
                break;
            case DOWN:
                cout << "DOWN" << endl;
                break;
            }
        }
        else
        {
            cout << "CommandProcessorThreadProc: No input recevice going to sleep. " << endl;
            sleep(100);
        }
    }
    cout << "CommandProcessorThreadProc: Thread is exiting !... " << endl;
}