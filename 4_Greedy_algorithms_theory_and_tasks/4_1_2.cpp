#include <iostream>
#include <ios>
#include <algorithm>
#include <cinttypes>
#include <cassert>
#include <vector>

using namespace std;

struct Item final {
    int weight;
    int value;
    };

double get_max_knapsack_value(int capacity, vector <Item> items) {
    sort(items.begin(), items.end(), [](const Item &lhs, const Item &rhs) {
        return static_cast<int64_t>(lhs.weight) * rhs.value <
        static_cast<int64_t>(rhs.weight) * lhs.value;
        });

    double value = 0.0;
    
    for(auto &item:items) {
        if (capacity > item.weight) {
        
            capacity -= item.weight;
            value += item.value;
        } else {
            value += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}

int main(void) {
    
    int number_of_items;
    int knapsack_capacity;
    
    cin >> number_of_items >> knapsack_capacity;
    
    vector <Item> items(number_of_items);
    
    for(int i = 0; i < number_of_items; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, move(items));

    cout << max_knapsack_value;
    
    return 0;
}
