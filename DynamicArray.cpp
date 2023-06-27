
DynamicArray() : data(nullptr), size(0), capacity(0) {}
explicit DynamicArray(size_t capacity) : data(new T[capacity]), size(0), capacity(capacity) {}
DynamicArray(const DynamicArray& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}
DynamicArray& operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data;
        data = new T[other.capacity];
        size = other.size;
        capacity = other.capacity;
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}
~DynamicArray() {
    delete[] data;
}

size_t getSize() const {
    return size;
}

T& operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const T& operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void push_back(const T& value) {
    if (size == capacity) {
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = value;
}

void pop_back() {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }
    size--;
}

