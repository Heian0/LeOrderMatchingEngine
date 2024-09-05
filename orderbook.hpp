#include <vector>
#include <tuple>
#include <mutex>

struct Orderbook {
public:
    // id, price, quantity, number of executions
    vector<tuple<int, int, int, int>> orders;
    mutable std::mutex mut;

    void addOrder(int id, int price, int quantity);
    bool removeOrderByID(int id);
    void removeOrderByIndex(int idx);
    void decrementQuantityByIndex(size_t idx, int count);
    void decrementQuantityById(int id, int count);
    void incrementExecutionCount(size_t idx);
    int matchOrder(OrderType cmd, int price, int quantity, int activeID, int timestamp);
};