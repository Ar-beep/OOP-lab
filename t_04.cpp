#include <iostream>

class Parking_price
{
    int num_vehicle, hour, rate;

public:
    Parking_price(int no_vehicle, int hr, int r) : num_vehicle(no_vehicle), hour(hr), rate(r){};
     Parking_price(Parking_price &p) : num_vehicle(p.num_vehicle), hour(p.hour), rate(p.rate){};
    float total_charge() {
        if(num_vehicle > 9)
        return (num_vehicle* hour * rate * 0.9);
    return num_vehicle* hour * rate;
    };
};
int main(){
    Parking_price c1(12,5,300);
    Parking_price c2 = c1;
    std::cout << "Price "<< c1.total_charge()<< std::endl <<
    "Price "<< c2.total_charge()<< std::endl;
    return 0;
}