#ifndef BASELEAF_H
#define BASELEAF_H

#include <utility>
#include <thread>
#include <atomic>

class BaseLeaf
{
public:
    BaseLeaf() : isRunning(false) {}

    void start() {
        if (!isRunning) {
            isRunning = true;
            workingThread = std::thread(&BaseLeaf::run, this);
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            if (workingThread.joinable()) {
                workingThread.join();
            }
        }
    }

    virtual ~BaseLeaf() {
        stop();
    }

protected:
    std::thread workingThread;
    std::atomic<bool> isRunning;

    virtual void run() = 0;
};


#endif //BASELEAF_H
