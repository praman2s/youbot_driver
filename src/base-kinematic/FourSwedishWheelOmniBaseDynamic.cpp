/****************************************************************
 *
 * Copyright (c) 2011
 * All rights reserved.
 *
 * Hochschule Bonn-Rhein-Sieg
 * University of Applied Sciences
 * Computer Science Department
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Author:
 * Jan Paulus, Nico Hochgeschwender, Michael Reckhaus, Azamat Shakhimardanov
 * Supervised by:
 * Gerhard K. Kraetzschmar
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * This sofware is published under a dual-license: GNU Lesser General Public 
 * License LGPL 2.1 and BSD license. The dual-license implies that users of this
 * code may choose which terms they prefer.
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Hochschule Bonn-Rhein-Sieg nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version or the BSD license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License LGPL and the BSD license for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL and BSD license along with this program.
 *
 ****************************************************************/
#include "base-kinematic/FourSwedishWheelOmniBaseDynamic.hpp"
namespace youbot {

FourSwedishWheelOmniBaseDynamic::FourSwedishWheelOmniBaseDynamic() {
  // Bouml preserved body begin 000513F1
    this->lastWheelPositionInitialized = false;
  // Bouml preserved body end 000513F1
}

FourSwedishWheelOmniBaseDynamic::~FourSwedishWheelOmniBaseDynamic() {
  // Bouml preserved body begin 00051471
  // Bouml preserved body end 00051471
}

///Calculates from the cartesian velocity the individual wheel velocities 
///@param longitudinalVelocity is the forward or backward velocity
///@param transversalVelocity is the sideway velocity
///@param angularVelocity is the rotational velocity around the center of the YouBot
///@param wheelVelocities are the individual wheel velocities
void FourSwedishWheelOmniBaseDynamic::cartesianWrenchToWheelTorques(const quantity<si::force>& fx, const quantity<si::force>& fy, const quantity<torque>& tz, std::vector<quantity<torque> >& wheelTorques) {
  
    std::cout << "Dynamics yet to be implemented" << std::endl;
    return;

  // Bouml preserved body end 0004C071
}

///Calculates from the wheel velocities the cartesian velocity
///@param wheelVelocities are the velocities of the individual wheels
///@param longitudinalVelocity is the forward or backward velocity
///@param transversalVelocity is the sideway velocity
///@param angularVelocity is the rotational velocity around the center of the YouBot
void FourSwedishWheelOmniBaseDynamic::wheelTorquesToCartesianWrench(const std::vector<quantity<torque> >& wheelTorques, quantity<si::force>& fx, quantity<si::force>& fy, quantity<torque>&  tz) {
  

    return;
  // Bouml preserved body end 0004C0F1
}



void FourSwedishWheelOmniBaseDynamic::setConfiguration(const FourSwedishWheelOmniBaseDynamicConfiguration& configuration) {
  // Bouml preserved body begin 0004C171
    this->config = configuration;
  // Bouml preserved body end 0004C171
}

void FourSwedishWheelOmniBaseDynamic::getConfiguration(FourSwedishWheelOmniBaseDynamicConfiguration& configuration) const {
  // Bouml preserved body begin 0004C1F1
    configuration = this->config;
  // Bouml preserved body end 0004C1F1
}


} // namespace youbot
