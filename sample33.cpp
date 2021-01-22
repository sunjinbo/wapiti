// 互斥锁 - 避免死锁

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <stdexcept>

std::mutex mtx; // 保护counter

int id = 0;
int counter = 0;
void increase_proxy(int time, int id) {
    for (int i = 0; i < time; i++) {
        std::lock_guard<std::mutex> lk(mtx);

        if (id == 1) {
            throw std::runtime_error("throw excption....");
        }

        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
    }
}

void increase() {
    try {
        increase_proxy(1000, id++);
    }
    catch (const std::exception& e){
        std::cout << "id:" << id << ", " << e.what() << std::endl;
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