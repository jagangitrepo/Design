#include "CommandProcessor.h"

pthread_mutex_t gcmdQMutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    cout<<"**************** CQSR Pattern ****************"<<endl;
    CommandProcessor cmdProc(&gcmdQMutex);
    cmdProc.StartCommandProcessorThread();
    int option =0;
    do
    {
        cout<<"1.LEFT\n2.RIGHT\n3.UP\n4.DOWN\n99.Exit"<<endl;
        cout<<"Select the option:"<<endl;
        cin>>option;
        cmdProc.QueueCmd({ option });
    }while (option != 99);   
    return 0;
}