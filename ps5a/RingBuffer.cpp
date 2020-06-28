#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
    if (capacity < 1){
        throw std::invalid_argument("RB constructor: capacity must be greater than zero");
    }

    las = 0;
    fir = 0;
    s = 0;
    cap = capacity;
    buf.resize(capacity);

    return;
}

int RingBuffer::size() {
    return s;
}

bool RingBuffer::isEmpty() {
    if(s != 0){
        return false;
    }
    else{
        return true;
    }
}

bool RingBuffer::isFull() {
    if(s == cap){
        return true;
    }
    else{
        return false;
    }
}

void RingBuffer::enqueue(int16_t x) {
    if (isFull()){
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
    }
    if (las >= cap){
        las = 0;
    }
    buf.at(las) = x; //keep going
    las++;
    s++;
}

int16_t RingBuffer::dequeue() {
    if (isEmpty()){
        throw std::runtime_error("dequeue: can't dequeue an empty ring");
    }
    int16_t first = buf.at(fir);
    buf.at(fir) = 0;
    fir++;
    s--;

    if (fir >= cap){
        fir = 0;
    }

    return first;
}

int16_t RingBuffer::peek() {
    if (isEmpty()){
        throw std::runtime_error("peek: can't peek an empty ring");
    }
    return buf.at(fir);
}

void RingBuffer::output()
{
    std::cout << "   First: " << fir << "\n";
    std::cout << "    Last: " << las << "\n";
    std::cout << "Capacity: " << cap << "\n";
    std::cout << "    Size: " << s << "\n";
    std::cout << "Vector size: " << buf.size() << "\n";
    std::cout << "Vector capacity: " << buf.capacity() << "\n";
    std::cout << "Buffer (no blanks): \n";

    int x = 0;
    int y = fir;

    while (x < s)
    {
        // Make the loop go back to 0 to continue printing.
        if (y >= cap)
        {
            y = 0;
        }

        std::cout << buf[y] << " ";
        y++;
        x++;
    }

    std::cout << "\nDump the entire buffer (including blanks): \n";

    for (int x = 0; x < cap; x++)
    {
        std::cout << buf[x] << " ";
    }

    std::cout << "\n\n";
}
