
#include <iostream>
#include <string>

class Department {
public:
    int id;
    std::string name;

    Department(int id, std::string name); 
    ~Department(); 
};

Department::Department(int id, std::string name) : id{id}, name{name} {
    
    std::cout << "Object of " << id << " initialized" << std::endl;
}



Department::~Department() {
    delete this;
    std::cout << "Object " << id << " goes out of the scope" << std::endl;
}

int main() {
    Department* D1 = new Department(1, "Kirana Store"); 
    Department* D2 = new Department(2, "IKEA"); 

    delete D2; 
    delete D1; 
    return 0;
}
                