#include <iostream>
#include <vector>
#include <memory>
#include <functional>

// Observer interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(float price) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject
class Stock : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    float price;
    
public:
    Stock() : price(0.0f) {}
    
    void setPrice(float newPrice) {
        price = newPrice;
        notify();
    }

    void attach(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (const auto& observer : observers) {
            observer->update(price);
        }
    }
};

// Concrete Observer
class StockObserver : public Observer {
private:
    std::string name;
    float price;
    
public:
    StockObserver(const std::string& observerName) : name(observerName), price(0.0f) {}
    
    void update(float newPrice) override {
        price = newPrice;
        std::cout << "Observer " << name << " updated with new price: " << price << std::endl;
    }
};

// Helper function to create a new observer
std::shared_ptr<Observer> createObserver(const std::string& name) {
    return std::make_shared<StockObserver>(name);
}

int main() {
    Stock googleStock;
    
    auto observer1 = createObserver("Observer 1");
    auto observer2 = createObserver("Observer 2");
    
    googleStock.attach(observer1);
    googleStock.attach(observer2);
    
    googleStock.setPrice(134.5f);
    googleStock.setPrice(137.8f);
    
    googleStock.detach(observer1);
    
    googleStock.setPrice(140.2f);
    
    return 0;
}
