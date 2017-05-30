# MutexesExperiment
An interesting experiment for those learning about mutexes in C++

This was just a little experiment I did for testing out C++ mutexes, just to see if the behaviour is similar to other languages I've learned.  

The test just adds 1 to a counter 10000 times.  It does this once whilst locking the method that does the increment with a mutex, once without.

I believe this error is occurring due to CPU pipelining.  Although all threads share the same copies of the global counter variables, it doesn't stop one thread reading the counter before another thread has finished incrementing the counter.  This results in counts getting missed, if the incrementing method is not locked with a mutex.

The mutex essentially blocks other threads from getting passed the lockguard, once the first thread goes past the lockguard.  The lockguard then owns the mutex until the lockguard goes out of scope, in this case, when the function returns.  This gives the opportunity for the next waiting thread's lockguard to own the mutex.

