#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "regionData.h"
#include "raceDemogData.h"

using namespace std;

/*
  class to represent county demographic data
  from CORGIS - LAB01 starter - replace with your FULL version!
*/
class demogData : public regionData {
  public:
    demogData(string inN, string inS, double in65, double in18,
        double in5, int totPop14, double inBach, double inHigh, double inPov, raceDemogData race) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), totalPopulation2014(totPop14), popBachelorEduPlus(inBach), popHighSchoolEduPlus(inHigh), popInPoverty(inPov),
            regionData{inN, inS, totPop14} 
            {
              raceData = race;
              
              // initialize the counts
              int countOver65 = getpopOver65Count();
              int countUnder18 = getpopUnder18Count();
              int countUnder5 = getpopUnder5Count();
              int countBachelorEduPlus = getBAupCount();
              int countHighSchoolEduPlus = getHSupCount();
              int countInPoverty = getPovertyCount();
            }

    string getName() const { return name; }
    string getState() const { return state; }
    virtual int getpopOver65() const { return popOver65; }
    virtual int getpopUnder18() const { return popUnder18; }
    virtual int getpopUnder5() const { return popUnder5; }
    virtual int getBAup() const { return popBachelorEduPlus; }
    virtual int getHSup() const { return popHighSchoolEduPlus; }
    virtual int getPoverty() const { return popInPoverty; }
    raceDemogData getRace() const { return raceData; }

    virtual double getpopOver65Count() const { return round( ((popOver65 / 100) * totalPopulation2014) ); }
    virtual double getpopUnder18Count() const { return round( ((popUnder18 / 100) * totalPopulation2014) ); }
    virtual double getpopUnder5Count() const { return round( ((popUnder5 / 100) * totalPopulation2014) ); }
    virtual double getBAupCount() const { return round( ((popBachelorEduPlus / 100) * totalPopulation2014) ); }
    virtual double getHSupCount() const { return round( ((popHighSchoolEduPlus / 100) * totalPopulation2014) ); }
    virtual double getPovertyCount() const { return round( ((popInPoverty / 100) * totalPopulation2014) ); }

    void addOver65(int num) {countOver65 = countOver65 + num;}
    void addUnder18(int num) {countUnder18 = countUnder18 + num;}
    void addUnder5(int num) {countUnder5 = countUnder5 + num;}
    void addBach(int num) {countBachelorEduPlus = countBachelorEduPlus + num;}
    void addHS(int num) {countHighSchoolEduPlus = countHighSchoolEduPlus + num;}
    void addPov(int num) {countInPoverty = countInPoverty + num;}

    friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

    virtual void toString(ostream& os) const{
    }   

protected:
    const string name;
    const string state;
    const double popOver65;
    const double popUnder18;
    const double popUnder5;
    const int totalPopulation2014;
    const double popBachelorEduPlus;
    const double popHighSchoolEduPlus;
    const double popInPoverty;

    int countOver65;
    int countUnder18;
    int countUnder5;
    int countBachelorEduPlus;
    int countHighSchoolEduPlus;
    int countInPoverty;

    raceDemogData raceData;
};
#endif
