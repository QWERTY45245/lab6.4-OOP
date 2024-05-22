#include <iostream>
#include <vector>

template <typename T>
class Vector {
private:
    std::vector<T> elements;

public:
    Vector() {}

    explicit Vector(size_t size, const T& initial = T()) : elements(size, initial) {}

    Vector<T> operator+(const Vector<T>& other) const {
        if (size() != other.size()) {
            throw std::invalid_argument("Vectors must have the same size for addition.");
        }
        Vector<T> result(size());
        for (size_t i = 0; i < size(); ++i) {
            result[i] = elements[i] + other[i];
        }
        return result;
    }

    T dotProduct(const Vector<T>& other) const {
        if (size() != other.size()) {
            throw std::invalid_argument("Vectors must have the same size for dot product.");
        }
        T result = 0;
        for (size_t i = 0; i < size(); ++i) {
            result += elements[i] * other[i];
        }
        return result;
    }

    T& operator[](size_t index) {
        return elements[index];
    }

    const T& operator[](size_t index) const {
        return elements[index];
    }

    size_t size() const {
        return elements.size();
    }

    void print() const {
        std::cout << "Vector elements: ";
        for (const auto& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector<int> v1(3, 1); 
    Vector<int> v2(3, 2); 

    v1.print();
    v2.print();

    Vector<int> sum = v1 + v2;
    std::cout << "Sum of vectors: ";
    for (size_t i = 0; i < sum.size(); ++i) {
        std::cout << sum[i] << " ";
    }
    std::cout << std::endl;

    int dot = v1.dotProduct(v2);
    std::cout << "Dot product of vectors: " << dot << std::endl;

    return 0;
}
