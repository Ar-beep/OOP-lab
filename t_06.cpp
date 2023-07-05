#include <iostream>
using namespace std;

class Satellite
{
private:
    const int natural{0};
    int artificial{0};

public:
    Satellite(int n, int a) : natural(n), artificial(a) {}
    void count() const { cout << artificial << " Artificial Satellite(s)\n"
                              << natural << " Natural Satellite(s)\n"; }
 void add(int a) {  artificial += a;}
};

int main()
{
    const Satellite sat1(1, 53);
    
    Satellite sat2(20, 0);

    sat1.count();
    sat2.add(2);
    sat2.count();

    return 0;
}
