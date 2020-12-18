#ifndef THE_ZOO_ANIMAL_H_
#define THE_ZOO_ANIMAL_H_

#include<string>

using namespace std;

class Animal
{
public:

	//Constructor
	Animal();
	//Override Constructor
	Animal(int t_trackingNum, string t_name, string t_type, string t_subType, int t_eggs, int t_nurse);
	//Destructor
	~Animal() {};

	//Getters
	int GetTrackingNum();
	string GetAnimalName();
	string GetAnimalType();
	string GetAnimalSubType();
	int GetNumEggs();
	int GetNursingStatus();

	//Setters
	void SetTrackingNum(int t_trackingNum);
	void SetAnimalName(string t_animalName);
	void SetAnimalType(string t_animalType);
	void SetAnimalSubType(string t_animalSubType);
	void SetNumEggs(int t_numEggs);
	void SetNursingStatus(int t_nursingStatus);

private:

	int trackingNum = 0;
	string animalName = "";
	string animalType = "";
	string animalSubType = "";
	int numEggs = 0;
	int nursingStatus = 0;
};
#endif THE_ZOO_ANIMAL_H_

