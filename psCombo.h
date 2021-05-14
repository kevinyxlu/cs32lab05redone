#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "psData.h"
#include "regionData.h"
#include <memory>
#include <cassert>

using namespace std;

class psCombo : public regionData  {
public:
    //write psCombo constructor
    psCombo(string inS) : regionData (inS, inS) {
        state = inS;
    }
    
    //complete these
    int getNumMentalI() const {return numMentalIllness; }
    int getFleeingCount() const {return fleeingCount;}
    int getCasesOver65() const {return casesOver65;}
    int getCasesUnder18() const {return casesUnder18;}
    raceDemogData getRacialData() const {return raceData;}
    int getnumMales() const {return numMales;}
    int getnumFemales()const {return numFemales;}
    int getNumberOfCases() const {return population;}
    string getState() const { return regionName; }

    void addPSData(shared_ptr<psData> ps);

    virtual void toString(ostream& os) const{
    }

    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);

protected:
    string state;
    int numMentalIllness = 0;
    int fleeingCount = 0;
    int casesOver65 = 0;
    int casesUnder18 = 0;
    int numMales = 0;
    int numFemales = 0;
    int numCases = 0;

    raceDemogData raceData;
};

#endif