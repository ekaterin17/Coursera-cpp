namespace RAII {
    template<class T>
    class Booking {
    public:
        Booking(T* provider, int counter)
        : provider_(provider)
        , counter_(counter) {}
        
        Booking(const Booking&) = delete;
        Booking(Booking&& other) noexcept : provider_(other.provider_), counter_(other.counter_)  {
            other.provider_ = nullptr;
        }
        
        Booking& operator = (const Booking&) = delete;
        Booking& operator = (Booking&& other) {
            if (provider_ != nullptr) {
                provider_->CancelOrComplete(*this);
            }
            provider_ = other.provider_;
            counter_ = other.counter_;
            other.provider_ = nullptr;
            return *this;
        }
        
        ~Booking() {
            if (provider_ != nullptr) {
                provider_->CancelOrComplete(*this);
            }
        }
        
    private:
        T* provider_;
        int counter_;
    };
}
