// 条件锁

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::mutex g_mutex;
std::condition_variable cv;
std::string g_data;
bool ready = false;  // 条件
bool processed = false;  // 条件

void Worker() {
  std::unique_lock<std::mutex> lock(g_mutex);

  // 等待主线程发送数据。
  cv.wait(lock, [] { return ready; });

  // 等待后，继续拥有锁。
  std::cout << "Working thread is processing data..." << std::endl;
  // 睡眠一秒以模拟数据处理。
  std::this_thread::sleep_for(std::chrono::seconds(1));
  g_data += " is already done!";

  // 把数据发回主线程。
  processed = true;
  std::cout << "Working thread says work is done!" << std::endl;

  // 通知前，手动解锁以防正在等待的线程被唤醒后又立即被阻塞。
  lock.unlock();

  cv.notify_one();
}

int main(int argc, char** argv)
{
    std::thread worker(Worker);

    // 把数据发送给工作线程。
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        std::cout << "Main thread is prepare data..." << std::endl;
        // 睡眠一秒以模拟数据准备。
        std::this_thread::sleep_for(std::chrono::seconds(1));
        g_data = "Sample data";
        ready = true;
        std::cout << "Main thread says data is ready!" << std::endl;
    }
    cv.notify_one();

    // 等待工作线程处理数据。
    {
        std::unique_lock<std::mutex> lock(g_mutex);
        cv.wait(lock, [] { return processed; });
    }
    cout << "Welcome to Main thread, the final data is " << g_data << endl;

    worker.join();

    return 0;
}