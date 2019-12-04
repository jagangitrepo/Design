#include <iostream>
#include "CommandProcessor.h"

pthread_mutex_t gcmdQMutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    cout<<"**************** CQSR Pattern ****************"<<endl;
    CommandProcessor cmdProc(gcmdQMutex);
    pthread_t processorThread ;
    pthread_create(processorThread, NULL, cmdProc.CommandProcessorThreadProc, NULL);
    int option = 0;
    do
    {
        cout<<"1.LEFT\n2.RIGHT\n3.UP\n4.DOWN"<<endl`;
        cout<<" Select option:"<<endl;
        cin >> option;
        cmdProc.QueueProcessCmd({option});
    }while(option != 99);
    return 0;
}