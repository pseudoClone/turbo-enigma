#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
        public:
                explicit Queue(size_t capacity = 10)
                        : capacity_(capacity), size_(0), front_(0), rear_(0) {
                                data_ = new T[capacity_];
                        }
                ~Queue() {
                        delete[] data_;
                }
                Queue(const Queue& other)
                        : capacity_(other.capacity_), size_(other.size_), front_(other.front_),
                        rear_(other.rear_) {
                                data_ = new T[capacity_];
                                for (size_t i = 0; i < size_; ++i) {
                                        data_[(front_ + i) % capacity_] = other.data_[(front_ + i) %
                                                capacity_];
                                }
                        }
                // Move constructor
                Queue(Queue&& other) noexcept
                        : capacity_(other.capacity_), size_(other.size_), front_(other.front_),
                        rear_(other.rear_), data_(other.data_) {
                                other.data_ = nullptr; // Moving means like copy but delete from the source haina? 
                        }
                // Copy assignment operator. GOD Help me!!!
                Queue& operator=(const Queue& other) {
                        if (this != &other) {
                                delete[] data_;
                                capacity_ = other.capacity_;
                                size_ = other.size_;
                                front_ = other.front_;
                                rear_ = other.rear_;
                                data_ = new T[capacity_];
                                for (size_t i = 0; i < size_; ++i) {
                                        data_[(front_ + i) % capacity_] = other.data_[(front_ + i) %
                                                capacity_];
                                }
                        }
                        return *this;
                }
                // Move assignment operator. ISTG they just mix up words to make new things ffs
                Queue& operator=(Queue&& other) noexcept {
                        if (this != &other) {
                                delete[] data_;  // Free the old memory
                                capacity_ = other.capacity_;
                                size_ = other.size_;
                                front_ = other.front_;
                                rear_ = other.rear_;
                                data_ = other.data_;
                                other.data_ = nullptr;
                        }
                        return *this;
                }
                bool empty() const {
                        return size_ == 0;
                }
                // Return size of Q
                size_t size() const {
                        return size_;
                }
                // Access front
                T& front() {
                        if (empty()) {
                                throw std::out_of_range("Queue is empty");
                        }
                        return data_[front_];
                }

                // Access the front (const version)
                const T& front() const {
                        if (empty()) {
                                throw std::out_of_range("Queue is empty");
                        }
                        return data_[front_];
                }

                // Access the back ;-p
                T& back() {
                        if (empty()) {
                                throw std::out_of_range("Queue is empty");
                        }
                        return data_[(rear_ - 1 + capacity_) % capacity_];
                }

                // Access the back (const version)
                const T& back() const {
                        if (empty()) {
                                throw std::out_of_range("Queue is empty");
                        }
                        return data_[(rear_ - 1 + capacity_) % capacity_];
                }

                // Enqueue (add to the rear)
                void enqueue(const T& value) {
                        if (size_ == capacity_) {
                                throw std::overflow_error("Queue is full");
                        }
                        data_[rear_] = value;
                        rear_ = (rear_ + 1) % capacity_;
                        ++size_;
                }

                // Enqueue (move version)
                void enqueue(T&& value) {
                        if (size_ == capacity_) {
                                throw std::overflow_error("Queue is full");
                        }
                        data_[rear_] = std::move(value);
                        rear_ = (rear_ + 1) % capacity_;
                        ++size_;
                }

                //From the front side deletion
                void dequeue() {
                        if (empty()) {
                                throw std::out_of_range("Queue is empty");
                        }
                        front_ = (front_ + 1) % capacity_;
                        --size_;
                }

                void clear() {
                        size_ = 0;
                        front_ = 0;
                        rear_ = 0;
                }

        private:
                T* data_;
                size_t capacity_;
                size_t size_;
                size_t front_;
                size_t rear_;
};

int main() {
        Queue<int> q(5);

        q.enqueue(12);
        q.enqueue(18);
        q.enqueue(1500);
        q.enqueue(1);
        q.enqueue(9);

        std::cout << "Front: " << q.front() <<std::endl;
        std::cout << "Back: " << q.back() <<std::endl;
        q.dequeue();
        std::cout << "After dequeue, Front: " << q.front() <<std::endl;
        q.enqueue(60);
        std::cout << "Back after enqueue: " << q.back() <<std::endl;

        std::cout << "Queue size: " << q.size() <<std::endl; 

        return 0;
}
