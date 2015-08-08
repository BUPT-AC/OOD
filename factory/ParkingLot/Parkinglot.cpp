//
//  Parkinglot.cpp
//  Parkinglot
//
//  Created by XinquanZhou on 8/7/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#include "Parkinglot.h"
#include "ParkingSpot.h"

bool Vehicle::canFitInSpot(ParkingSpot *spot){
    return spot -> canFitVehicle(this);
}

