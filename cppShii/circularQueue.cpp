#include <cstddef>
#include <iostream>

template<typename T>
class Queue{
        public:
                Queue(size_t capacity = 10): capacity_(capacity), size_(0), front_(0), rear_(0){}
                
                ~Queue(){
                        delete[] data_;
                }

                Queue(const Queue& other):capacity_(other.capacity_), size_(other.size_), front_(other.front_), rear_(other.rear_){
                        data_ = new T[capacity_];
                        for(size_t i = 0; i < size_; i++){
                                data_[(front_ + i) % capacity_] = other.data_[(front_ + i) % capacity_];
                        }
                }// Copy constructor
                
                Queue(const Queue&& other):
                        capacity_(other.capacity_), size_(other.size_),
                        front_(other.front_), rear_(other.rear_), data_(other.data_){
                                other.data_ = nullptr; // Moving deletes the source
                }

                //Copy assignment operator, God help me
                Queue& operator=(const Queue& other){
                        if(this != &other){
                                delete[] data_;
                                capacity_ = other.capacity_;
                                size_ = other.capacity_;
                                front_ = other.front_;
                                rear_ = other.rear_;
                                data_ = new T[capacity_];

                                for(size_t i = 0; i < size_; ++i){
                                        data_[(front_ + i) % capacity_] = other.data_[(front_ + i) % capacity_];
                                }
                        }
                        return *this;
                }


        private:
                T* data_;
                size_t size_;
                size_t capacity_;
                size_t front_;
                size_t rear_;

};
