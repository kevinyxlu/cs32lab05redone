#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"
#include "regionData.h"

/*
  class to represent combined demographic data 
*/
class demogCombo : public demogData {
  public:
        //write demogCombo constructor
    demogCombo(string state) : demogData{state, state, 0, 0, 0, 0, 0, 0, 0, raceDemogData()}{}

    void addCounty(shared_ptr<demogData> county);

    virtual int getpopOver65() const { return popOver65; }
    virtual int getpopUnder18() const { return popUnder18; }
    virtual int getpopUnder5() const { return popUnder5; }
    virtual int getBAup() const { return popBachelorEduPlus; }
    virtual int getHSup() const { return popHighSchoolEduPlus; }
    virtual int getPoverty() const { return popInPoverty; }
    int getCountyCount() const { return countyCount; }

    virtual double getpopOver65Percent() const { return round( ((popOver65 * 100) / totalPopulation2014) ); }
    virtual double getpopUnder18Percent() const { return round( ((popUnder18 * 100) / totalPopulation2014) ); }
    virtual double getpopUnder5Percent() const { return round( ((popUnder5 * 100) / totalPopulation2014) ); }
    virtual double getBAupPercent() const { return round( ((popBachelorEduPlus * 100) / totalPopulation2014) ); }
    virtual double getHSupPercent() const { return round( ((popHighSchoolEduPlus * 100) / totalPopulation2014) ); }
    virtual double getPovertyPercent() const { return round( ((popInPoverty * 100) / totalPopulation2014) ); }

    friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

    virtual void toString(ostream& os) const{
        cout << this;
    }

protected:
    int countyCount = 0;
    int countOver65 = 0;
    int countUnder18 = 0;
    int countUnder5 = 0;
    int countBachelorEduPlus = 0;
    int countHighSchoolEduPlus = 0;
    int countInPoverty = 0;
};
#endif
