#ifndef __CART_H
#define __CART_H

#include <Storage.h>

class Cart : public Storage {
public:
    Cart() : Storage() {}

    float totalMoney() {
        float ans = 0;
        for (auto it : container) {
            ans += it.getPrice() * it.getNum();
        }

        return ans;
    }

    bool checkAmmount(Product prod, int ammount) {
        if (ammount < 0) return false;

        list <Product>::iterator it;
        for (it = MainStorage.container.begin(); it != MainStorage.container.end(); ++it) {
            if (it->getName() == prod.getName()) return ammount <= prod.getNum();
        }

        return false;
    }

    bool changeAmmount(Product prod, int newAmmount) {
        checkAmmount(prod, newAmmount);
        if (newAmmount == 0) erase(prod);

        list <Product>::iterator it;
        for (it = container.begin(); it != container.end(); ++it) {
            if (*it == prod) {
                it->setNum(newAmmount);
                break;
            }
        }
    }
};

#endif
