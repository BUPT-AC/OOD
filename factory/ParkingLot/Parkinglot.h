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
class Ticket;
enum VehicleSize { Moto, Compact, Large};

class Vehicle {
protected:
    int Id;
    ParkingSpot* parkingSpot = nullptr;
    VehicleSize size;
    Ticket * ticket;
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
    virtual bool canFitInSpot(ParkingSpot * spot) ;
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

class Ticket
{
public:
    Vehicle * v;
    Parkinglot * p;
    int startTime, endTime;
public:
    Ticket(arguments);
    ~Ticket();
};



#endif /* defined(__Parkinglot__Parkinglot__) */
