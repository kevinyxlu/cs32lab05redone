#include <iomanip>
#include "psCombo.h"

void psCombo::addPSData(shared_ptr<psData> ps)
{
    population = population + 1;
    numMentalIllness = numMentalIllness + ps->getSignsMentalIllness();
    fleeingCount = fleeingCount + ps->getFlee();

    // increment age data
    if(ps->getAge() >= 65)
    {
        casesOver65 = casesOver65 + 1;
    }
    else if(ps->getAge() <= 18)
    {
        casesUnder18 = casesUnder18 + 1;
    }

    // increment gender data
    if(ps->getGender() == 'M')
    {
        numMales = numMales + 1;
    }
    else if(ps->getGender() == 'F')
    {
        numFemales = numFemales + 1;
    }

    //increment racial data
    if(ps->getRace() == 'W') // white
    {
        raceData.addWhiteNHCount(1);
        raceData.addWhiteCount(1);
    }
    else if(ps->getRace() == 'A') // asian
    {
        raceData.addAsianCount(1);
    }
    else if(ps->getRace() == 'B') // black
    {
        raceData.addBlackCount(1);
    }
    else if(ps->getRace() == 'H') // latinx
    {
        raceData.addLatinxCount(1);
    }
    else if(ps->getRace() == 'O') // other
    {
        raceData.addOtherCount(1);
    }
    else if(ps->getRace() == 'N') // native american
    {
        raceData.addFirstNationCount(1);
    }
    raceData.addCommunityCount(1);
}

/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    //out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    //fill in
    return out;
}