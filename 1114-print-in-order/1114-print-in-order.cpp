#include<atomic>
class Foo {
public:
    void spinLock(int turn){
        while(m_turn.load()!=turn);
    }
    atomic<int>m_turn;
    Foo() : m_turn{1} {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_turn.store(2);
    }

    void second(function<void()> printSecond) {
        spinLock(2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_turn.store(3);
    }

    void third(function<void()> printThird) {
        spinLock(3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};