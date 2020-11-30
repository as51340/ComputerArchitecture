#include <unordered_map>
#include <iostream>
#include <string>
#include "../IO/Timer.h"
#include <fstream>


#define NUM_ACTIONS 10000000

//Simulations of typical use, we create some object in file and then need to pass it to other file when this process ends. That's the reason why we
//are allocating space on heap two times when we could actually only once. WE SIMULATE STORING IN THIS FILE AND READING FROM ANOTHER FILE.
//enum needs bytes accordingly to information that stores. For example size of ActionType is 4bits

enum ActionType {PAST, PRESENT, FUTURE};

std::unordered_map<std::string, enum ActionType> conversion_table;



//we only care about performance not about data
class Action {
    public:
        std::string actionName;
        ActionType actionType;
        int actionIndex;
        
        Action() {
            actionName = "RandomName";
            actionType = PRESENT;
            actionIndex = 1;
        }
        
        void printAction() {
            std::cout << actionName << " " << actionType << " " << actionIndex << std::endl;
        }
        
        ~Action() {
            
        }
};


Action* createActions() {
    Action* actions= new Action[NUM_ACTIONS];
    return actions;
}


//neglect reserving on heap and deleting objects from heap
void storeActionsAsText() {
    Action* actions = createActions();
    std::ofstream stream("Actions.txt");
    for(int i = 0; i < NUM_ACTIONS; i++) {
        stream << actions[i].actionName << " " << actions[i].actionType << " " << actions[i].actionIndex << std::endl;
    }
    delete[] actions;
}

//neglect reserving on heap and deleting objects from heap
void readActionsFromText() {
    std::ifstream stream("../Action.txt");
    Action* actions = createActions();
    for(int i = 0; i< NUM_ACTIONS; i++) {
        std::string enumName;
        stream >> actions[i].actionName;
        stream >> enumName;
        actions[i].actionType = conversion_table[enumName];
        stream >> actions[i].actionIndex;
    }
    delete[] actions;
}

void simulateText() {
    Timer timer;
    storeActionsAsText();
    readActionsFromText();
}

void storeActionsAsBinary() {
    Action* actions = createActions();
    std::ofstream wb("../actions.dat", std::ios::out | std::ios::binary);
    if(!wb) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }
    for(int i = 0; i < NUM_ACTIONS; i++) {
        wb.write((char*) &actions[i], sizeof(Action));  
    }
    wb.close();
    if(!wb.good()) {
        std::cout << "Error occurred while writing to file" << std::endl;
        return;
    }
    delete[] actions;
}

void readActionsAsBinary() {
    Action* actions = createActions();
    std::ifstream rf("../actions.dat", std::ios::out | std::ios::binary);
    if(!rf) {
        std::cout << "Cannot open file for reading!" << std::endl;
        return; 
    }
    for(int i = 0; i < NUM_ACTIONS; i++) {
        rf.read((char*) &actions[i], sizeof(Action));
    }
    rf.close();
    if(!rf.good()) {
        std::cout << "Error occurred at reading time!" << std::endl;
        return;
    }
    delete[] actions;
}


void simulateBinary() {
    Timer timer;
    storeActionsAsBinary();
    readActionsAsBinary();
}




int main() {
    conversion_table["PAST"] = ActionType::PAST;
    conversion_table["PRESENT"] = ActionType::PRESENT;
    conversion_table["FUTURE"] = ActionType::FUTURE;
    std::cout << "Text simulation: " << std::endl;
    simulateText();    
    std::cout << std::endl << "Binary simulation: " << std::endl;
    simulateBinary();
}