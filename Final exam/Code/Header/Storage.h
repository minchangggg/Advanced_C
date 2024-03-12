#ifndef __STORAGE_H
#define __STORAGE_H

#include <Product.h>

class Storage {
public:
    list <Product> container;

    Storage() {}

    void add(Product prod) {
        container.push_back(prod);
    }

    void erase(Product prod) {
        list <Product>::iterator it;
        for (it = container.begin(); it != container.end(); ++it) {
            if (*it == prod) break;
        }

        container.erase(it);
    }

    bool decrease(Product prod, int ammount) {
        list <Product>::iterator it;
        for (it = container.begin(); it != container.end(); ++it) {
            if (*it == prod) {
                it->setAmmount(it->getAmmount() - ammount);
                break;
            }
        }
    }

    bool increase(Product prod, int ammount) {
        list <Product>::iterator it;
        for (it = container.begin(); it != container.end(); ++it) {
            if (*it == prod) {
                it->setAmmount(it->getAmmount() + ammount);
                break;
            }
        }
    }
} MainStorage;

#endif