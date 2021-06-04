#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Lift_Up(vector<int> numbers, int index) {
    if (index > 0) {
        if (((index == 1) || (index == 2)) && (numbers.size() > 2)) {
            if (max(numbers[1], numbers[2]) > numbers[0]) {
                if (numbers[1] > numbers[2]) {
                    swap(numbers[1], numbers[0]);
                }
                else {
                    swap(numbers[2], numbers[0]);
                }
            }
            return numbers;
        }
        int parent_index = (index - 1) / 2;
        if (numbers[index] > numbers[parent_index]) {
            swap(numbers[index], numbers[parent_index]);
            Lift_Up(numbers, parent_index);
        }
    }
    return numbers;
}

vector<int> Get_Down(vector<int> numbers, int index) {
    int child_index = index * 2 + 1;
    if (child_index < numbers.size()) {
        if (child_index + 1 != numbers.size()) {
            if (numbers[child_index] < numbers[child_index + 1]) {
                child_index++;
            }
        }
        if (numbers[index] < numbers[child_index]) {
            swap(numbers[index], numbers[child_index]);
            Get_Down(numbers, child_index);
        }
    }
    return numbers;
}

int main() {
    int number_of_requests;
    cin >> number_of_requests;
    vector<int> numbers;
    for (size_t request_number = 0; request_number < number_of_requests; request_number++) {
        int value;
        string command;
        cin >> command;
        if (command == "ExtractMax") {
            swap(numbers[0], numbers[numbers.size() - 1]);
            cout << numbers.back() << endl;
            numbers.pop_back();
            numbers = Get_Down(numbers, 0);
        }
        else {
            cin >> value;
            numbers.push_back(value);
            numbers = Lift_Up(numbers, numbers.size() - 1);
        }
    }
}
