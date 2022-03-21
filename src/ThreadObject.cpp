#include "ThreadObject.h"

std::mutex ThreadObject::_mtxSnake;
std::mutex ThreadObject::_mtxRunning;
Snake ThreadObject::snake;
std::size_t ThreadObject::desired_frame_duration;
bool ThreadObject::running;

ThreadObject::~ThreadObject(){
        std::for_each(threads.begin(), threads.end(), [](std::thread &t) { t.join();});
    }

bool ThreadObject::getRunning() const{

    // Use lock guard to access the shared flag "running" and unlock when out of scope
    std::lock_guard<std::mutex> lock(_mtxRunning); 
    return running;
}

void ThreadObject::setRunning(bool b){

    // Lock before writing data
    std::unique_lock<std::mutex> lckRunning(_mtxRunning);
    running = b;
    lckRunning.unlock();
}

void ThreadObject::setSnake(Snake s){
    snake = s;
}

void ThreadObject::setDesFrame(std::size_t d){
    desired_frame_duration = d;
}