# MutexesExperiment
An interesting experiment for those learning about mutexes in C++

This was just a little experiment I did for testing out C++ mutexes, just to see if the behaviour is similar to other languages I've learned.  

The test just adds 1 to a counter 10000 times.  It does this once while locking the method that does the increment with a mutex and once without.

Although all threads share the same copy of the global counter variable, to increment the counter requires the counter value and 1 to be summed by the CPU at some stage.  Then the value in the address of counter is updated.  If a thread reads the counter address between these two stages it will get the old counter value.  This results in counts getting missed, if the incrementing method is not locked with a mutex.

The mutex essentially blocks other threads from getting past the lockguard, once the first thread goes past the lockguard.  The lockguard then owns the mutex until the lockguard goes out of scope, in this case, when the function returns.  This gives the opportunity for the next waiting thread's lockguard to own the mutex.

