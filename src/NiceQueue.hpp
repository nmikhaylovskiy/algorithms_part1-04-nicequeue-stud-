#include <algorithm>


// TODO: implenent all methods :)


template<class T>
NiceQueue<T>::NiceQueue(size_t capacity):_inStack(capacity), _outStack(capacity)
{
    _capacity = capacity;
}

template<class T>
NiceQueue<T>::~NiceQueue()
{

}

template<class T>
size_t NiceQueue<T>::size() const
{
    return _outStack.size() + _inStack.size();
}

template<class T>
void NiceQueue<T>::enq(const T &newElement)
{
        if (_inStack.size() >= _capacity)
            throw std::out_of_range("ERROR ENQ");
        _inStack.push(newElement);
}

template<class T>
T NiceQueue<T>::deq()
{
    if (_outStack.size() != 0)
    {
        return _outStack.pop();
    }
    if (size() == 0)
        throw std::out_of_range("STILL(deq)");
    else
    {
        while (_inStack.size() != 0)
            _outStack.push(_inStack.pop());
        return _outStack.pop();
    }

}

template<class T>
T NiceQueue<T>::getMinimum()
{
    if (_outStack.size() == 0 && _inStack.size() == 0)
        throw std::out_of_range("STILL (gmNQ)");
    if (_inStack.size() != 0 && _outStack.size() == 0)
        return _inStack.getMinimum();
    if (_inStack.size() == 0 && _outStack.size() != 0)
        return _outStack.getMinimum();
    else
    {
        if (_inStack.getMinimum() < _outStack.getMinimum())
            return _inStack.getMinimum();
        else
            return _outStack.getMinimum();
    }
}
