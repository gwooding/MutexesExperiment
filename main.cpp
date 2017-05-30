#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>
#include <thread>
#include <vector>
using namespace std;

int counter1;
int counter2;
std::mutex some_mutex;

void add_to_counter()
{
 counter1 += 1;
}

void add_to_counter_safely()
{
    std::lock_guard<std::mutex> guard(some_mutex);
    counter2 += 1;
}

void count_with_threads(int number_of_threads, void (*f)()){

    std::vector<std::thread> threads(number_of_threads);
    for(unsigned long i=0;i<(number_of_threads);++i)
    {
        threads[i]=std::thread(f);
    }
    std::for_each(threads.begin(),threads.end(), std::mem_fn(&std::thread::join));

}


int main() {

    int number_of_threads = 10000;

    count_with_threads(number_of_threads, add_to_counter);

    count_with_threads(number_of_threads, add_to_counter_safely);

    cout<<"with no thread safety "<<counter1<<endl;
    cout<<"with mutexes "<<counter2<<endl;

    return 0;
}