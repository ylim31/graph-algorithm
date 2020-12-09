
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    size_t left = currentIdx * 2;
    return left;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    size_t right = (currentIdx * 2) + 1;
    return right;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    size_t parent = currentIdx/2;
    return parent;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    if (leftChild(currentIdx) >= _elems.size()) {
        return false;
    }
    return true;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    
    if (rightChild(currentIdx) >= _elems.size()) {
        return leftChild(currentIdx);
    } else if (higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)])) {
        return leftChild(currentIdx);
    } else {
        return rightChild(currentIdx);
    }
   
   
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    if ((hasAChild(currentIdx))) {
        size_t child_index = maxPriorityChild(currentIdx);
        if (!higherPriority(_elems[currentIdx],_elems[child_index])) {
            std::swap(_elems[currentIdx], _elems[child_index]);
            heapifyDown(child_index);
        }
        
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    _elems.push_back(T());
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems) 
{  
   T type;
   _elems.push_back(elems.size());
   for (unsigned i = 0; i < elems.size(); i++) {
       _elems.push_back(elems[i]);
      
   }
   
    for (unsigned i = elems.size(); i > 0; i--) {
        heapifyDown(i);
    }
   


}

template <class T, class Compare>
T heap<T, Compare>::pop()
{   if (_elems.size() == 1) {
    return T();
}
    T min = _elems[root()];
    _elems[root()] = _elems[_elems.size() - 1];
    _elems.pop_back();

    heapifyDown(root());
    return min;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    return _elems[root()];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    _elems.push_back(elem);
    heapifyUp(_elems.size() - 1);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{   

    if (elem < _elems[idx]) {
        _elems[idx] = elem;
        heapifyUp(idx);
    } else if (elem > _elems[idx]) {
        _elems[idx] = elem;
        heapifyDown(idx);
    }
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
   return _elems.empty();
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
