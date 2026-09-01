#include "payment.h"

int main() {
    CreditCard card;
    ProcessPayment payment(&card);
    payment.pay();
    return 0;
}
