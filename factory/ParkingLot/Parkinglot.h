//
//  Parkinglot.h
//  Parkinglot
//
//  Created by XinquanZhou on 8/7/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#ifndef __Parkinglot__Parkinglot__
#define __Parkinglot__Parkinglot__

// the vehecle classes

#include <stdio.h>
class ParkingSpot;

enum VehicleSize { Moto, Compact, Large};

class Vehicle {
protected:
    ParkingSpot* parkingSpot = nullptr;
    VehicleSize size;
    
public:
    VehicleSize getSize() {return size;}
    void parkInSpot(ParkingSpot* s){
        parkingSpot = s;
    }
    void clearSpot(){
        if (parkingSpot) {
            delete parkingSpot;
            parkingSpot = nullptr;
        }
    }
    bool canFitInSpot(ParkingSpot * spot) ;
};

class Bus : public Vehicle {
public:
    Bus(){
        size = VehicleSize::Large;
    }
    bool canFitInSpot(ParkingSpot * spot);

};

class Car : public Vehicle{
public:
    Car(){
        size = VehicleSize::Compact;
    }
    bool canFitInSpot(ParkingSpot * spot);
};

class Moto : public Vehicle {
    
public:
    Moto(){
        size = VehicleSize::Moto;
    }
    bool canFitInSpot(ParkingSpot * spot);
};



#endif /* defined(__Parkinglot__Parkinglot__) */
