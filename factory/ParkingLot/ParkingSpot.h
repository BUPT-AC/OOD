//
//  ParkingSpot.h
//  Parkinglot
//
//  Created by XinquanZhou on 8/7/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#ifndef __Parkinglot__ParkingSpot__
#define __Parkinglot__ParkingSpot__

#include <stdio.h>
#include "Parkinglot.h"

class Level;

class ParkingSpot {
    Vehicle * vehicle = nullptr;
    VehicleSize spotSize;
    int row, spotNumber;
    Level * level ;
    
public:
    ParkingSpot(Level * lvl, int r, int n, VehicleSize s){
        level = lvl;
        r = row;
        spotNumber = n;
        spotSize = s;
    }
    
    bool isAvailable () const{
        return vehicle == nullptr;
    }
    
    void park(Vehicle * v){
        vehicle = v;
    }
    
    int getRow() const{
        return row;
    }
    int getNum() const{
        return spotNumber;
    }
    
    bool canFitVehicle(Vehicle * v){
        return v->getSize() <= spotSize;
    }
    void removeVehicle(){
        if (vehicle) {
            delete vehicle;
            vehicle = nullptr;
        }
    }
    
};
#endif /* defined(__Parkinglot__ParkingSpot__) */
