# Design 

## 1. Multi Client & Server Arch

  ### Components:
    1. Thread pool.
          We can configure the no of worker threads to process the task from the Message Queue.
    2. Receiver.
          It represent the data flow from the up to down.
          It will continously listen and receive and dump the data to Message Queue.
    3. Dispatcher.
          It represent the data flow from the down to up.
          It will continously listen and receive and dump the data to Message Queue.
    4. Message Queue.
          It the internal cache, that will store the incoming and outcoming data to be processed.
    
![Multi Client   Server Arch](https://user-images.githubusercontent.com/7909399/55214102-ad80ba00-521b-11e9-9b6e-16a92e4cc49e.png)
