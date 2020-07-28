#ifndef CAR_H
#define CAR_H

using namespace std;

class Car {
public:
    std::string sBrand;

    std::string sModel;

    int nYear;
    
    Car():sBrand(""), sModel(""), nYear(0){}
    
    Car(std::string brand, std::string model, int year) :
        sBrand(brand),
        sModel(model),
        nYear(year) {
    }

    string GetBrand() const {
        return this->sBrand;
    }

    string GetModel() const {
        return this->sModel;
    }

    int GetYear() const {
        return this->nYear;
    }

};

#endif // !CAR_H
