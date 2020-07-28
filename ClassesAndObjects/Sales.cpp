#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// 3.Sales
class salesClass {
private: // all the containers we will use
    map <string, double> salesMap;
    string town;
    string product;
    float price;
    float quantity;
public:
    salesClass() { // default initializer
        price = 0;
        quantity = 0;
    }
    salesClass(unsigned x) { //when initialized with number of entries the setSales function is requested
        setSales(x);
    }

    void setSales (unsigned x){ //setSales function fill the container with valid data that we are interested in
        string str;
        for (unsigned i = 0; i < x; i++) {  // for number of lines
            getline(cin, str);              // we request the numer of lines
            istringstream in(str);
            in >> town >> product >> price >> quantity; // and we expect to get the required parameters
            float turnover = price * quantity; // from last two parameters we calculate teh turnover
            salesMap[town] += turnover;     // and we fill the map with the new TO for the key "town"
        }
    }

    void showSales(){
        for (auto i = salesMap.begin(); i != salesMap.end(); i++) {
            cout.precision(2); // set precision for output quantities , i.e second
            cout << i->first << " -> " << fixed << i->second << endl; //printing the automatically ordered by key (i.e. first) map
        }
    }
};


int main()
{
    unsigned dailyEntriesNb;

    cin >> dailyEntriesNb;
    cin.ignore();
    salesClass salesMan1(dailyEntriesNb);
    salesMan1.showSales();

    return 0;
}
