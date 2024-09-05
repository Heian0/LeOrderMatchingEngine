#include "orderbook.hpp"
#include <tuple>
#include <mutex>

void Orderbook::addOrder(int id, int price, int quantity) {
    orders.push_back(std::make_tuple(id, price, quantity, 0));
}

bool Orderbook::removeOrderByID(int id) {
    for (size_t i = 0; i < orders.size(); i++) {
        if (std::get<0>(orders[id]) == id) {
            orders.erase(orders.begin() + (long)i);
            return true;
        }
    }

    return false;
}

void Orderbook::removeOrderByIndex(int idx) {
    orders.erase(orders.begin() + long(idx));
}

void Orderbook::decerementQuantityByIndex(int idx, int count) {
    std::get<2>(orders[idx]) -= count;
}

void Orderbook::decrementQuantityById(int id int count) {
    for (size_t i = 0; i < orders.size(); i++) {
        if (std::get<0>(orders[id]) == id) {
           std::get<2>(orders[id]) -= count;
        }
    }
}

void Orderbook::incrementExecutionCount(size_t idx) {
  std::get<3>(book[idx]) += 1;
}

void Orderbook::matchOrder(OrderType cmd, , int price, int quantity, int activeID, int timestamp) {

}