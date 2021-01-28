#ifndef LIST_FILE
#define LIST_FILE

#include <vector>

using namespace std;

template <class T>
class list { 
  private: 
    vector<T> elems;     // 元素 
 
  public: 
    void add(T const&);  // 添加元素
    void remove(T const&); // 删除元素
    T& operator[](int i); // 重载运算符，根据下标返回指定元素
    void clear(); // 清除全部元素
    int size() const; // 获取列表元素个数
    bool empty() const; // 如果为空则返回真
};

#endif // LIST_FILE
