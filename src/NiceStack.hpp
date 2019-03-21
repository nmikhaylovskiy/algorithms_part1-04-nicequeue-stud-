
// TODO: implement all methods :)



template<class T>
NiceStack<T>::NiceStack(size_t capacity)
{
    _capacity = capacity;
    _iHead = 0;
    _storage = std::vector<TypeElementStack>(capacity);
}

template<class T>
NiceStack<T>::~NiceStack()
{

}

template<class T>
size_t NiceStack<T>::size() const
{
    return _iHead;
}

template<class T>
void NiceStack<T>::push(const T &newelement)
{
    if (_iHead == _capacity)
        throw std::out_of_range("FULL (PUSH)");
    if (_iHead != 0)
        if (newelement < getMinimum())
            _storage[_iHead] = TypeElementStack(newelement, newelement);
        else
            _storage[_iHead] = TypeElementStack(newelement, getMinimum());
    else
        _storage[_iHead] = TypeElementStack(newelement, newelement);

    _iHead++;
}

template<class T>
T NiceStack<T>::pop()
{
    if (_iHead == 0)
        throw std::out_of_range("STILL(POP)");
    _iHead--;
    return _storage[_iHead].first;

}

template<class T>
const T &NiceStack<T>::top() const
{
    if (_iHead == 0)
        throw std::out_of_range("STILL(TOP)");
    return _storage[_iHead - 1].first;
}

template<class T>
const T &NiceStack<T>::getMinimum() const
{
    if (size() == 0)
        throw std::out_of_range("STILL(gmNS)");
    return _storage[_iHead - 1].second;
}