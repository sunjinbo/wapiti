// 回溯算法 - 全排列问题

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class List: public vector<T> { 
public:
    void addAll(const List<T>& list);
    bool contians(const T& t);
    void add(const T& t);
    void remove(const T& t);
};

template <class T>
void List<T>::addAll(const List<T>& list)
{
    for (int i = 0; i < list.size(); ++i)
    {
        this->push_back(list.at(i));
    }
}

template <class T>
bool List<T>::contians(const T& t)
{
    for (int i = 0; i < this->size(); ++i)
    {
        if (t == this->at(i))
        {
            return true;
        }
    }

    return false;
}

template <class T>
void List<T>::add(const T& t)
{
    this->push_back(t);
}

template <class T>
void List<T>::remove(const T& t)
{
    List<T> temp;
    for (int i = 0; i < this->size(); ++i)
    {
        if (t != this->at(i))
        {
            temp.push_back(t);
        }
    }

    this->clear();
    this->addAll(temp);
}

List< List<int> > result;
void backtrack(int num[], int size, List<int> trace);

int main()
{
    int number[] = {2, 5, 8, 11};
    List<int> track;

    backtrack(number, 4, track);

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result.at(i).size(); ++j)
        {
            cout << result.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}

void backtrack(int num[], int size, List<int> track)
{
    if (size == track.size())
    {
        List<int> t;
        t.addAll(track);
        result.add(t);
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        if (track.contians(num[i]))
        {
            continue;
        }

        track.push_back(num[i]);
        backtrack(num, size, track);
        track.pop_back();
    }
}
