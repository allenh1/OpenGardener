#ifndef PLANT_H
#define PLANT_H

/** This class contains all things common to plants.
 * The objective here is to keep track of all things that a user may want to look
 * up at a given time.
 *
 * Future things:
 * It would be cool to have a layout of a garden. The objects could keep track of their position.
 * It would also be cool to have tips on spacing and estimated time for each plant from an online
 * database.
 *
 ***/

#include "plantdate.h"

class Plant
{
public:
    Plant();

    const bool & isMature();
    const QString & getName();
    const QString & getScientificName();


private:
    bool m_hydroponic; //different kind of reminders

    QString m_genus;
    QString m_species;
    QString m_commonName;

    /** Necessary Dates to keep track of **/
    PlantDate * p_dayPlanted;
    PlantDate * p_nextWatering;
    PlantDate * p_daysTillMaturity;
    PlantDate * p_nextWaterChange; //For hydroponic Systems
};

#endif // PLANT_H
