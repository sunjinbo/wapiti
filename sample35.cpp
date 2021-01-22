// 自旋锁

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <stdexcept>
#include <atomic>

class spin_mutex {
    std::atomic<bool> flag;
public:
    spin_mutex() = default;
    spin_mutex(const spin_mutex&) = delete;
    spin_mutex& operator= (const spin_mutex&) = delete;
    void lock() {
        bool expected = false;
        while (!flag.compare_exchange_strong(expected, true))
            expected = false;
    }
    void unlock() {
        flag.store(false);
    }
};

spin_mutex lock; // 保护counter

int counter = 0;
void increase() {
    int time = 1000;
    for (int i = 0; i < time; i++) {
        lock.lock();
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
        lock.unlock();
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