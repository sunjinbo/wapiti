// 锁

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <stdexcept>

std::mutex mtx; // 保护counter

int counter = 0;
void increase() {
    int time = 1000;
    for (int i = 0; i < time; i++) {
        mtx.lock();
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
        mtx.unlock();
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