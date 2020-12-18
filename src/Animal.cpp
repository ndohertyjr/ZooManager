#include "Animal.h"
#include<string>
#include<iomanip>

using namespace std;


Animal::Animal() {}

Animal::Animal(int t_trackingNum, string t_name, string t_type, string t_subType, int t_eggs, int t_nurse)
{
	this->trackingNum = t_trackingNum;
	this->animalName = t_name;
	this->animalType = t_type;
	this->animalSubType = t_subType;
	this->numEggs = t_eggs;
	this->nursingStatus = t_nurse;
}

//Getters
int Animal::GetTrackingNum() {
	return trackingNum;
}
std::string Animal::GetAnimalName() {
	return animalName;
}
std::string Animal::GetAnimalType() {
	return animalType;
}
std::string Animal::GetAnimalSubType() {
	return animalSubType;
}
int Animal::GetNumEggs() {
	return numEggs;
}
int Animal::GetNursingStatus() {
	return nursingStatus;
}

//Setters
void Animal::SetTrackingNum(int t_trackingNum) {
	this->trackingNum = t_trackingNum;
}
void Animal::SetAnimalName(string t_animalName) {
	this->animalName = t_animalName;
}
void Animal::SetAnimalType(string t_animalType) {
	this->animalType = t_animalType;
}
void Animal::SetAnimalSubType(string t_animalSubType) {
	this->animalSubType = t_animalSubType;
}
void Animal::SetNumEggs(int t_numEggs) {
	this->numEggs = t_numEggs;
}
void Animal::SetNursingStatus(int t_nursingStatus) {
	this->nursingStatus = t_nursingStatus;
}
