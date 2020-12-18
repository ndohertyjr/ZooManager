#include <iostream>
#include <iomanip>
#include <jni.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include "Animal.h"

using namespace std;

//Create global variables
bool exitProgram = false;
int menuSelection;
vector<Animal*> animalList;
int trackingNum;
string animalName;
string animalType;
string animalSubType;
int numEggs;
int nursingStatus;
char userChoice;


void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
	JavaVM* jvm;                      // Pointer to the JVM (Java Virtual Machine)
	JNIEnv* env;                      // Pointer to native interface
															 //================== prepare loading of Java VM ============================
	JavaVMInitArgs vm_args;                        // Initialization arguments
	JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
	options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
	vm_args.version = JNI_VERSION_1_6;             // minimum Java version
	vm_args.nOptions = 1;                          // number of options
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
																		 //=============== load and initialize Java VM and JNI interface =============
	jint rc = JNI_CreateJavaVM(&jvm, (void**)& env, &vm_args);  // YES !!
	delete options;    // we then no longer need the initialisation options.
	if (rc != JNI_OK) {
		// TO DO: error processing...
		cin.get();
		exit(EXIT_FAILURE);
	}
	//=============== Display JVM version =======================================
	cout << "JVM load succeeded: Version ";
	jint ver = env->GetVersion();
	cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

	jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
	if (cls2 == nullptr) {
		cerr << "ERROR: class not found !";
	}
	else {                                  // if class found, continue
		cout << "Class ZooFileWriter found" << endl;
		jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
		if (mid == nullptr)
			cerr << "ERROR: method void createZooFile() not found !" << endl;
		else {
			env->CallStaticVoidMethod(cls2, mid);                      // call method
			cout << endl;
		}
	}


	jvm->DestroyJavaVM();
	cin.get();
}


void AddAnimal()
{
	/*
		   TODO: Write proper code to add an animal to your vector (or array)
	*/

	//Variable to end loop once added successfully
	bool animalAdded = false;
	//Animal creation loop
	while (animalAdded != true) {
		//Tracking number entry
		cout << "Please enter the tracking number (6 digits): " << endl;
		cin >> trackingNum;
		//Loop to confirm tracking number is valid
		bool isValid = false;
		if (trackingNum < 999999 && cin.good()){
			isValid = true;
		}
		while (isValid != true) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Tracking number must contain a maximum of 6 digits.  Try again." << endl;
			cin >> trackingNum;
			if (trackingNum < 999999 && cin.good()){
				isValid = true;
			}
		}
		//Animal Name entry
		cout << "Please enter the animal name (15 characters): " << endl;
		cin >> animalName;
		//Loop to confirm animal name is valid
		while (animalName.length() > 15) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Animal name cannot exceed 15 characters.  Try again." << endl;
			cin >> animalName;
		}
		//Animal Type entry
		cout << "Please enter the animal type (15 characters): " << endl;
		cin >> animalType;
		//Loop to confirm animal type is valid
		while (animalType.length() > 15) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Animal type cannot exceed 15 characters.  Try again." << endl;
			cin >> animalType;
		}
		//Animal Subtype entry
		cout << "Please enter the animal type (15 characters): " << endl;
		cin >> animalSubType;
		//Loop to confirm animal type is valid
		while (animalSubType.length() > 15) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Animal Sub-type cannot exceed 15 characters.  Try again." << endl;
			cin >> animalSubType;
		}
		//Num eggs entry
		cout << "Please enter the number of eggs laid: " << endl;
		cin >> numEggs;
		//Loop to confirm number of eggs is valid
		while (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Number of eggs can only contain integers.  Try again." << endl;
			cin >> numEggs;
		}
		//Nursing status entry
		cout << "Please enter nursing status (0 if not nursing, 1 if nursing): " << endl;
		cin >> nursingStatus;
		//Loop to confirm number of eggs is valid
		bool nursingCorrect = false;
		if (nursingStatus == 0) {
			nursingCorrect = true;
		}
		else if (nursingStatus == 1) {
			nursingCorrect = true;
		}
		while (nursingCorrect == false) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter 0 if not nursing, 1 if nursing." << endl;
			cin >> nursingStatus;
			if (nursingStatus == 0) {
				nursingCorrect = true;
			}
			if (nursingStatus == 1) {
				nursingCorrect = true;
			}

		}

		//Create object for new animal
		Animal* newAnimal = new Animal(trackingNum, animalName, animalType, animalSubType, numEggs, nursingStatus);
		animalList.push_back(newAnimal);
		cout << animalName << " added successfully!" << endl;

		cout << "Add another animal? Y to add another animal, any other key to return to the menu" << endl;
		cin >> userChoice;

		//Add additional animals
		if (userChoice == 'y' || userChoice == 'Y') {
			continue;
		}
		else {
			animalAdded = true;
			break;
		}
	}
}


void RemoveAnimal()
{

	cout << "Please enter the tracking number of the animal to be deleted." << endl;
	//Obtain specific tracking num
	cin >> trackingNum;

	//Search for record in vector
	for (int i = 0; i < animalList.size(); ++i) {
		if (trackingNum == animalList[i]->GetTrackingNum()){
			cout << "Record located.  Enter Y to delete.  Enter any other key to return to the main menu." << endl;
			cin >> userChoice;

			//confirm delete
			if (userChoice == 'y' || userChoice == 'Y') {
				animalList.erase(animalList.begin() + i);
				cout << "Animal successfully deleted" << endl;
				break;
			}
			else {
				break;
			}
		}
	}
	cout << "No record located with that tracking number." << endl;
}

void LoadDataFromFile()
{
	//
	ifstream animalFile("zoodata.txt");
	string line;

	//try to read file
	try {
		if (animalFile.is_open()) {
			//loop through file data
			while (getline(animalFile, line)) {
				//read line into a stringstream
				stringstream ss(line);

				//variables to store data from file


				//stringstream data into variables
				ss >> trackingNum >> animalName >> animalType >> animalSubType >> numEggs >> nursingStatus;

				//Create animal object for the data
				Animal* currAnimal = new Animal(trackingNum, animalName, animalType, animalSubType, numEggs, nursingStatus);
				//add animal to the vector
				animalList.push_back(currAnimal);
			}
			cout << "Load complete!" << endl;
			animalFile.close();
		}
	}
	catch (const ifstream::failure& e){
		cout << "Error in opening the file.";
	}
}

void SaveDataToFile()
{
	try{
	//open file and clear current contents
	ofstream animalFile("zoodata.txt", ofstream::out | ofstream::trunc);

	//Loop through vector and save data to file
	for (int i = 0; i < animalList.size(); ++i) {

		animalFile << right << setw(6) << setfill('0') << animalList[i]->GetTrackingNum() << "      ";
		animalFile << left << setw(16) << setfill(' ') << animalList[i]->GetAnimalName();
		animalFile << left << setw(16) << animalList[i]->GetAnimalType();
		animalFile << left << setw(16) << animalList[i]->GetAnimalSubType();
		animalFile << left << setw(7) << animalList[i]->GetNumEggs();
		animalFile << left << setw(7) << animalList[i]->GetNursingStatus() << endl;
	}
	animalFile.close();

	cout << "Data saved to file!" << endl;
	}
	catch (const ofstream::failure& e){
		cout << "Error in opening the file.";
	}

}

void DisplayMenu()
{

	//display menu options
	cout << "Welcome to your zoo interface!" << endl << endl;
	cout << "Please select from the following options:" << endl << endl;
	cout << "1. Load Animal Data" << endl;
	cout << "2. Generate Data" << endl;
	cout << "3. Display Animal Data" << endl;
	cout << "4. Add Record" << endl;
	cout << "5. Delete Record" << endl;
	cout << "6. Save Animal Data" << endl;
	cout << "7. Exit" << endl;

}


void DisplayData()
{
	cout << "Currently stored animal data: " << endl << endl;
	//Display table title
	cout << "Tracking #: " << "Name:           " << "Type:           " << "Sub-type:       " << "Eggs:  " << "Nurse: " << endl;

	//Loop through vector and print
	for (int i = 0; i < animalList.size(); ++i) {

		cout << right << setw(6) << setfill('0') << animalList[i]->GetTrackingNum() << "      ";
		cout << left << setw(16) << setfill(' ') << animalList[i]->GetAnimalName();
		cout << left << setw(16) << animalList[i]->GetAnimalType();
		cout << left << setw(16) << animalList[i]->GetAnimalSubType();
		cout << left << setw(7) << animalList[i]->GetNumEggs();
		cout << left << setw(7) << animalList[i]->GetNursingStatus() << endl;
	}
}



int main()
{
	//create vector to store animal records in memory
	vector<Animal> animalList;


	while (exitProgram != true) {

		DisplayMenu();

		cin >> menuSelection;

		//execute menu choice
		switch (menuSelection) {
		case 1:
			LoadDataFromFile();
			break;
		case 2:
			GenerateData();
			break;
		case 3:
			DisplayData();
			break;
		case 4:
			AddAnimal();
			break;
		case 5:
			RemoveAnimal();
			break;
		case 6:
			SaveDataToFile();
			break;
		case 7:
			exitProgram = true;
			break;

		}

	}

	return 1;
}
