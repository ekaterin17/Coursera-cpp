#include <future>
#include <mutex>

using namespace std;

template <typename T>
class Synchronized {
public:
    explicit Synchronized(T initial = T())
    : value(move(initial)){}
    
    void operator = (Synchronized&& other) {
        value = other.GetAccess().ref_to_value;
    }
    
    struct Access {
        T& ref_to_value;
        lock_guard<mutex> guard;
    };

    Access GetAccess() {
        return {value, lock_guard(m)};
    }

private:
    T value;
    mutex m;
};
