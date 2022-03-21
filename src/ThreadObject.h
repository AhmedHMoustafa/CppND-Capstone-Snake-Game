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

   // Destructor
   ~ThreadObject();

   // Creates and runs the thread in a vector
   virtual void runThread()=0;

   // Getters and Setters
   bool getRunning() const;
   void setRunning(bool b);
   void setSnake(Snake s);
   void setDesFrame(std::size_t s);

 protected:

   std::vector<std::thread> threads;
   static std::mutex _mtxSnake;  // Mutex to lock Snake resource shared b/w Game & Controller
   static std::mutex _mtxRunning;// Mutex to lock Running flag resource shared b/w Game & Controller

   //Resources shared b/w Game & Controller
   static std::size_t desired_frame_duration;
   static Snake snake;
   static bool running;


};

#endif