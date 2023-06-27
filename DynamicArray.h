template<typename T>
class DynamicArray {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    DynamicArray();
    explicit DynamicArray(size_t capacity);
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();
    size_t getSize();
    T& operator[](size_t index);
    const T& operator[](size_t index);
    void push_back(const T& value);
    void pop_back();
};
