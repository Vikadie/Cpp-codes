#include <iostream>
#include <cmath>

using namespace std;

// 1.Euclidean distance
class VectorClass {
public:
    VectorClass(double x1, double y1) : x(x1), y(y1) 
    { }
    void setVector(double x1, double y1) {
        this->x = x1;
        this->y = y1;
    }
    void getVector() {  // playing a bit with getVector() function
        cout << "(" << this->x << "," << y << ")" << endl;
    }
    double addVector(VectorClass &vec) {
        
        return sqrt(pow(x - vec.x, 2) + pow(y - vec.y, 2));
    }
private:
    double x;
    double y;
};

int main()
{
    double x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    VectorClass vec1(x1, y1);
    
    VectorClass vec2(x2, y2);
    
    double answer = vec1.addVector(vec2);

    cout.precision(3);
    cout << fixed << answer;
    
    return 0;
}