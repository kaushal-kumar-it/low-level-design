#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual void processPayment() const = 0;
};

class CreditCard : public PaymentMethod {
public:
    void processPayment() const override {
        std::cout << "Processed the payment using a credit card" << std::endl;
    }
};

class UPI : public PaymentMethod {
public:
    void processPayment() const override {
        std::cout << "Processed the payment using UPI" << std::endl;
    }
};

class DebitCard : public PaymentMethod {
public:
    void processPayment() const override {
        std::cout << "Processed the payment using a debit card" << std::endl;
    }
};

class ProcessPayment {
public:
    explicit ProcessPayment(PaymentMethod* paymentMethod)
        : paymentMethod_(paymentMethod) {}

    void pay() const {
        paymentMethod_->processPayment();
    }

private:
    PaymentMethod* paymentMethod_;
};

#endif
