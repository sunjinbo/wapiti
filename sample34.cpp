// 原子锁

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <stdexcept>
#include <atomic>

std::atomic_int counter(0);

void increase() {
    int time = 1000;
    for (int i = 0; i < time; i++) {
        counter++;
    }
}

int main(int argc, char** argv) {
    std::thread t1(increase);
    std::thread t2(increase);
    t1.join();
    t2.join();
    std::cout << "counter:" << counter << std::endl;
    return 0;
}
