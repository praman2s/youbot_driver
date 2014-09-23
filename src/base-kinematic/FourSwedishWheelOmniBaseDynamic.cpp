/****************************************************************
 *
 * Copyright (c) 2014
 * All rights reserved.
 *
 * Hochschule Bonn-Rhein-Sieg
 * University of Applied Sciences
 * Computer Science Department
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Author:
 * Praveen Ramanujam
 * Supervised by:
 * Prof. Paul G.Ploeger
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
  
    this->lastWheelPositionInitialized = false;
    
 
}

FourSwedishWheelOmniBaseDynamic::~FourSwedishWheelOmniBaseDynamic() {
 
}
///Calculates from the cartesian velocity the individual wheel velocities 
///@param longitudinalVelocity is the forward or backward velocity
///@param transversalVelocity is the sideway velocity
///@param angularVelocity is the rotational velocity around the center of the YouBot
///@param wheelVelocities are the individual wheel velocities
void FourSwedishWheelOmniBaseDynamic::cartesianWrenchToWheelTorques(const quantity<si::force>& fx, const quantity<si::force>& fy, const quantity<torque>& tz, std::vector<quantity<torque> >& wheelTorques) {
  
    std::cout << "Dynamics yet to be implemented" << std::endl;
    return;

 
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

void FourSwedishWheelOmniBaseDynamic::WheelTorquestoCartesianAcceleration(quantity<si::acceleration>& ax, quantity<si::acceleration>& ay, quantity<si::angular_acceleration> &wz, const std::vector< quantity<si::torque> >& senseddata){
	
	std::vector< quantity<si::force> > f;
	f.resize(4);
	for (unsigned int i = 0; i < 4 ; i ++){
		//f[i] = senseddata[i]/config.wheelRadius;
		f[i] = senseddata[0].value()*newton*meter/config.wheelRadius;
		
	}
	
       
	return;
}

void FourSwedishWheelOmniBaseDynamic::BaseAccelerationtoWheelTorques( const quantity<si::acceleration>& ax,  const quantity<si::acceleration>& ay,  const quantity<si::angular_acceleration> &wz, std::vector< quantity<si::torque> >& data){

	std::vector< quantity<si::force> > f;
	f.resize(4);
	if (config.wheelRadius.value() == 0 || config.rotationRatio == 0 || config.slideRatio == 0) {
      		throw std::out_of_range("The wheelRadius, RotationRatio or the SlideRatio are not allowed to be zero");
    	}
	f[0] = 1*newton;
	f[1] = 1*newton;
	f[2] = 1*newton;
	f[3] = 1*newton;
	for (unsigned int i = 0; i < 4 ; i ++){
		//f[i] = senseddata[i]/config.wheelRadius;
		data[i] = (f[i].value()/config.wheelRadius.value())*newton_meter;
		
	}
	return;
}

void FourSwedishWheelOmniBaseDynamic::ComputeBaseForce(quantity<si::force> &fx, quantity<si::force> &fy, const std::vector< quantity<si::torque> >& data ){

	fx = ((-(data[0].value() - this->config.wheelRadius.value()*sgn(data[0])*this->config.friction) -
              (data[1].value() - this->config.wheelRadius.value()*sgn(data[1])*this->config.friction) + 
	      (data[2].value() - this->config.wheelRadius.value()*sgn(data[2])*this->config.friction) + 
	      (data[3].value() -  this->config.wheelRadius.value()*sgn(data[3])*this->config.friction))/this->config.wheelRadius.value() )* newton;


	fy = ((-(data[0].value() - this->config.wheelRadius.value()*sgn(data[0])*this->config.friction) +
              (data[1].value() - this->config.wheelRadius.value()*sgn(data[1])*this->config.friction) + 
	      (data[2].value() - this->config.wheelRadius.value()*sgn(data[2])*this->config.friction) - 
	      (data[3].value() -  this->config.wheelRadius.value()*sgn(data[3])*this->config.friction))/this->config.wheelRadius.value() )* newton;
	return;
}
void FourSwedishWheelOmniBaseDynamic::setConfiguration(const FourSwedishWheelOmniBaseDynamicConfiguration& configuration) {

    this->config = configuration;
 
}

void FourSwedishWheelOmniBaseDynamic::getConfiguration(FourSwedishWheelOmniBaseDynamicConfiguration& configuration) const {
 
    configuration = this->config;
  
}


} // namespace youbot
