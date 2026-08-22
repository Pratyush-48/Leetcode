#include <atomic>
#include <functional>
#include <thread>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    atomic<int> m_turn;
    
public:
    ZeroEvenOdd(int n) : m_turn{1} {
        this->n = n;
    }
    
    void spinLock(int turn){
        while(m_turn.load() != turn) {
        }
    }
    
    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        // Zero n times print hona chahiye
        for (int i = 1; i <= n; i++) {
            spinLock(1);
            printNumber(0);
            
            // Agar next number odd aane wala hai (i odd hai)
            if (i % 2 == 1) {
                m_turn.store(3);
            } 
            // Agar next number even aane wala hai (i even hai)
            else {
                m_turn.store(2);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        // Even numbers 2 se start hote hain aur +2 se badhte hain
        for (int i = 2; i <= n; i += 2) {
            spinLock(2);
            printNumber(i);
            
            // Apna turn khatam, wapas zero ko bulao
            m_turn.store(1);
        }
    }

    void odd(function<void(int)> printNumber) {
        // Odd numbers 1 se start hote hain aur +2 se badhte hain
        for (int i = 1; i <= n; i += 2) {
            spinLock(3);
            printNumber(i);
            
            // Apna turn khatam, wapas zero ko bulao
            m_turn.store(1);
        }
    }
};