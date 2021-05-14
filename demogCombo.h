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

    double getpopOver65() const { return popOver65; }
    double getpopUnder18() const { return popUnder18; }
    double getpopUnder5() const { return popUnder5; }
    double getBAup() const { return popBachelorEduPlus; }
    double getHSup() const { return popHighSchoolEduPlus; }
    double getPoverty() const { return popInPoverty; }
    int getCountyCount() const { return countyCount; }

    double getpopOver65Percent() const { return double( (((double)popOver65 / (double)population ) * 100) ); }
    double getpopUnder18Percent() const { return ( (((double)popUnder18 / (double)population ) * 100) ); }
    double getpopUnder5Percent() const { return ( (((double)popUnder5 / (double)population ) * 100) ); }
    double getBAupPercent() const { return ( (((double)popBachelorEduPlus / (double)population ) * 100) ); }
    double getHSupPercent() const { return ( (((double)popHighSchoolEduPlus / (double)population ) * 100) ); }
    double getPovertyPercent() const { return (((double)countInPoverty * (double)10000.00) / population) ; }

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
