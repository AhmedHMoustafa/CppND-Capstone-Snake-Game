#ifndef THREADOBJECT_H
#define THREADOBJECT_H

#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include "snake.h"


// Abstract class for objects that will launch threads.
class ThreadObject {

 public:

    ~ThreadObject();
    // ~ThreadObject(){
    //     std::for_each(threads.begin(), threads.end(), [](std::thread &t) { t.join();});
    // }

    virtual void runThread()=0;

    bool getRunning() const;
    void setRunning(bool b);

    void setSnake(Snake s);
    void setDesFrame(std::size_t s);

 protected:
    std::vector<std::thread> threads;
    static std::mutex _mtxSnake;
    // static std::mutex _mtxFood;
    // static std::mutex _mtxRedFood;
    // static std::mutex _mtxRenderRed;
    static std::mutex _mtxRunning;

    static std::size_t desired_frame_duration;
    static Snake snake;
    static bool running;


 private:
    




};

#endif