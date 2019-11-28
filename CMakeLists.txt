cmake_minimum_required(VERSION 3.15)
project(ELevatorSimulatorDesignPattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(ELevatorSimulatorDesignPattern main.cpp Passenger.cpp Passenger.h Staff.cpp Staff.h SupportStaff.cpp SupportStaff.h MedicalStaff.cpp MedicalStaff.h Security.cpp Security.h SecurityPersonnel.cpp SecurityPersonnel.h Visitors.cpp Visitors.h Patients.cpp Patients.h RandomGenerator.cpp RandomGenerator.h StringHelper.cpp StringHelper.h ElevatorDirection.cpp ElevatorDirection.h GenerateUniquePassenger.cpp GenerateUniquePassenger.h StatisticsKeeper.cpp StatisticsKeeper.h FileRead.cpp FileRead.h TrafficGenerator.cpp TrafficGenerator.h SystemControllerBridge.cpp SystemControllerBridge.h SystemControllerImpA.cpp SystemControllerImpA.h SystemControllerInterface.cpp SystemControllerInterface.h timingWheel.cpp timingWheel.h partitions.cpp partitions.h Elevators.cpp Elevators.h)