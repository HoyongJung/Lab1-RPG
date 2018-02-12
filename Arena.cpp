#include "Arena.h"
	/*
	*	addFighter(string)
	*
	*	Adds a new fighter to the collection of fighters in the arena. Do not allow
	*	duplicate names.  Reject any string that does not adhere to the format
	*	outlined in the lab specs.
	*
	*	Return true if a new fighter was added; false otherwise.
	*/
	bool Arena::addFighter(string info) {
	    stringstream ss(info);
	    //string errorCheck;
	    string name;
	    string type;
	    int maxHP;
	    int strength;
	    int speed;
	    int magic;
	    bool isName = false;
	    bool isError = false;
	    
	    if (ss >> name >> type >> maxHP >> strength >> speed >> magic) {
	    	//if (ss >> errorCheck) {
	    	if (!ss.eof()) {
	    		isError = true;
	    	}
		    for (int i = 0; i < fighters.size(); ++i) {
	    		if (name == fighters.at(i)->getName()) {
		            isName = true;
		        }
	    	}
	    	if (!isName && !isError) {
	    		if (type == "R") {
	    			fighters.push_back(new Robot(name, maxHP, strength, speed, magic));
	    		}
	    		else if (type == "A") {
	    			fighters.push_back(new Archer(name, maxHP, strength, speed, magic));
	    		}
	    		else if (type == "C") {
	    			fighters.push_back(new Cleric(name, maxHP, strength, speed, magic));
	    		}
	    		else {
	    			return false;
	    		}
	    		return true;
	    	}
	    	else {
				    return false;
	    	}
	    }
	    else {
	    	return false;
	    }
	}

	/*
	*	removeFighter(string)
	*
	*	Removes the fighter whose name is equal to the given name.  Does nothing if
	*	no fighter is found with the given name.
	*
	*	Return true if a fighter is removed; false otherwise.
	*/
	bool Arena::removeFighter(string name) {
	    for (int i = 0; i < fighters.size(); ++i) {
	        if (name == fighters.at(i)->getName()) {
	        	delete fighters[i];
	            fighters.erase(fighters.begin() + i);
	            return true;
	        }
	    }
	    return false;
	}

	/*
	*	getFighter(string)
	*
	*	Returns the memory address of a fighter whose name is equal to the given
	*	name.  Returns NULL if no fighter is found with the given name.
	*
	*	Return a memory address if a fighter is found; NULL otherwise.
	*/
	FighterInterface* Arena::getFighter(string name) {
	    for (Fighter* fp : fighters) {
	    	if (fp->getName() == name) {
	    		return fp;
	    	}
	    }
	    return NULL;
	}

	/*
	*	getSize()
	*
	*	Returns the number of fighters in the arena.
	*
	*	Return a non-negative integer.
	*/
	int Arena::getSize() const {
	    return fighters.size();
	}