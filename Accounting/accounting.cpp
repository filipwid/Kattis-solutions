#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Person {
    int money;

public:
    Person() {
        money = 0;
        }

    void set(int to_set) {
        money = to_set;
    }

    void print() {
        std::cout << money << "\n";
    }
};

int main() {
    int num_of_people, num_of_events;
    std::cin >> num_of_people >> num_of_events;
    std::vector<Person> people_vec(num_of_people);
    std::string token;

    long reset_time = -1;
    int arg1, arg2, default_val;
    int times[num_of_people] = {-1};

    for(int i=0; i < num_of_events; i++) {
        std::cin >> token;
        if(token == "SET") {
            std::cin >> arg1 >> arg2;
            people_vec[arg1 - 1].set(arg2);
            times[arg1-1] = i;
        }

        else if(token == "PRINT") {
            std::cin >> arg1;
            if(times[arg1-1] > reset_time)
                people_vec[arg1 - 1].print();
            else
                std::cout << default_val << "\n";
        }

        else if(token == "RESTART") {
            reset_time = i;
            std::cin >> default_val;
        }
    }

    return 0;
}