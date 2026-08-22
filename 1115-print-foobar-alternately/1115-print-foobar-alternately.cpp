class FooBar {
private:
    int n;
public:
    atomic<int>m_turn;
    FooBar(int n) : m_turn{1}{
        this->n = n;
    }
    void spinLock(int turn){
        while(m_turn.load()!=turn);
    }
    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            spinLock(1);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m_turn.store(2);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            spinLock(2);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m_turn.store(1);
        }
    }
};