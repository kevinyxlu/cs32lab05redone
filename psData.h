#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include <iomanip>
#include <memory>
#include <vector>
#include "raceDemogData.h"
#include "regionData.h"

using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData : public regionData {
  public:
    //add appropriate function paramaters to constructor once you add data
    psData(string inName, string inState, int inAge, string inGender, string inRace, string inCounty, bool inSignsMentalIllness, string inFlee) : regionData{inState, inState, 1} {
      name = inName;
      age = inAge;
      gender = inGender[0];
      race = inRace[0];
      county = inCounty;
      signsMentalIllness = inSignsMentalIllness;

      if((inFlee == "Not fleeing") || inFlee == "")
      {
          flee = false;
      }
      else {
        flee = true;
      }
    }


    string getState() const { return regionName; }
    //add getters
    string getName() const { return name; }
    int getAge() const {return age; }
    char getGender() const { return gender; }
    char getRace() const { return race; }
    string getCounty() const { return county; }
    bool getSignsMentalIllness() const { return signsMentalIllness; }
    bool getFlee() const { return flee; }

    friend std::ostream& operator<<(std::ostream &out, const psData &PD);

    virtual void toString(ostream& os) const{
    }

private:
    string name;
    int age;
    char gender;
    char race;
    string county;
    bool signsMentalIllness = false;
    bool flee = true;
    raceDemogData raceData;

};

#endif
