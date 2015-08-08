//
//  ParkingLevel.h
//  Parkinglot
//
//  Created by XinquanZhou on 8/7/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#ifndef __Parkinglot__ParkingLevel__
#define __Parkinglot__ParkingLevel__
#include "ParkingSpot.h"
#include<vector>
class Vehicle;

class Level {
    int floor, availableSpots = 0;
    std::vector<ParkingSpot*> spots;
    static const int SPOTS_PER_ROW = 10;
    
public:
    Level(int flr, int numberSpots):floor(flr),availableSpots(numberSpots){}
    int getAvailableSpots() const{
        return availableSpots;
    }
    
    bool parkVehicle(Vehicle * v);
    bool parkAtSpot(int num, Vehicle * v);
    void spotsFreed(){
        availableSpots ++;
    }
};

class Parkinglot {
    std::vector<Level> levels;
    static const int NUM_LEVELS = 5;
    
public:
    Parkinglot(){}
    bool parkVehicle(Vehicle * v);
};


#endif /* defined(__Parkinglot__ParkingLevel__) */
