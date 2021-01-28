#include "list.h"

template <class T>
void list<T>::add(T const& elem) 
{ 
    // 追加传入元素的副本
    elems.push_back(elem);    
}

template <class T>
void list<T>::remove(T const& elem) 
{
    for(vector<T>::iterator it = elems.begin(); it! = arr.end();)
    {
        if(*it == elem)
        {
            it = elems.erase(it); //不能写成arr.erase(it);
        }
        else
        {
            ++it;
        }
    }   
}

template <class T>
T& list<T>::operator[](int i)
{ 
    if (i >= 0 && i < size()) {
        int index = 0;
        for(vector<T>::iterator it = elems.begin(); it! = arr.end();)
        {
            if(i == index)
            {
                retrun *it;
            }
            else
            {
                ++it;
                ++index;
            }
        }
    } else {
        throw i;
    }
}

template <class T>
void list<T>::clear() { // 清除全部元素
    elems.clear();
}

template <class T>
int list<T>::size() const { // 获取列表元素个数
    return elems.size();
}

template <class T>
bool list<T>::empty() const { // 如果为空则返回真。
    return elems.empty(); 
}
