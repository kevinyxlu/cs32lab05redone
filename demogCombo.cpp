#include "demogCombo.h"
#include "demogData.h"
#include <memory>
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here
void demogCombo::addCounty(shared_ptr<demogData> data)
{
    countyCount = countyCount + 1;
    countOver65 = countOver65 + data->getpopOver65Count();
    countUnder18 = countUnder18 + data->getpopUnder18Count();
    countUnder5 = countUnder5 + data->getpopUnder5Count();
    countBachelorEduPlus = countBachelorEduPlus + data->getBAupCount();
    countHighSchoolEduPlus = countHighSchoolEduPlus + data->getHSupCount();
    countInPoverty = countInPoverty + data->getPovertyCount();
    population = population + data->getPop();
    raceData += data->getRace();


    int countyCount = 0;
    int countOver65 = 0;
    int countUnder18 = 0;
    int countUnder5 = 0;
    int countBachelorEduPlus = 0;
    int countHighSchoolEduPlus = 0;
    int countInPoverty = 0;
}

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& SD) {
    out << std::setprecision(2) << std::fixed;
    out << "\nState info: " << SD.getState() << endl; // State Info: UT
    out << "Number of Counties: " << SD.getCountyCount() << endl; // Number of Counties: 29   
    out << "Population Info:\n"; // Population Info:
    out << "(over 65): " << SD.getpopOver65Percent() << "% and total: " << SD.getpopOver65() << endl; // (over 65): 10.03% and total: 295146
    out << "(under 18): " << SD.getpopUnder18Percent() << "% and total: " << SD.getpopUnder18() << endl; // (under 18): 30.71% and total: 903830
    out << "(under 5): " << SD.getpopUnder5Percent() << "% and total: " << SD.getpopUnder5() << endl; // (under 5): 8.58% and total: 252378
    out << "Education info:\n"; // Education info: 
    out << "(Bachelor or more): " << SD.getBAupPercent() << "% and total: " << SD.getBAup() << endl; // (Bachelor or more): 30.54% and total: 898886
    out << "(high school or more): " << SD.getHSupPercent() << "% and total: " << SD.getHSup() << endl; // (high school or more): 91.01% and total: 2678412
    out << "persons below poverty: " << SD.getPovertyPercent() << "% and total: " << SD.getPoverty() << endl;// persons below poverty: 12.67% and total: 372832

    out << "community racial demographics: Racial Demographics Info: ";
    out << SD.getRace() << endl;
    
    return out;
}
