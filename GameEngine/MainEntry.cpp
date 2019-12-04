#include <iostream>
#include "CommandProcessor.h"

pthread_mutex_t gcmdQMutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    cout<<"**************** CQSR Pattern ****************"<<endl;
    CommandProcessor cmdProc(gcmdQMutex);
    pthread_t processorThread ;
    pthread_create(processorThread, NULL, cmdProc.CommandProcessorThreadProc, NULL);
    while (/* condition */)
    {
        /* code */
    }
    
    return 0;
}