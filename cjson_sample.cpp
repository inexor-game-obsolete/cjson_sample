/*cjson_sample - a simple api to handle package.json files
Copyright (C) 2014  Fohlen <fohlen@einhufer.info>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>
#include "cJSON.h" //include cJSON.h using some g++ magic

using namespace std;

// Define api prototypes
map<string, cJSON *> package;
cJSON * getProperty(string cat, string property);
cJSON * setProperty(string cat, string property);

int main() {
	
	// Package.json demo
	fstream f;
	f.open("package.json"); // Open in rw mode


	if(!f.is_open()) exit(EXIT_FAILURE);

	cJSON * item; // Parser
	string line, json; // Input
	//map<string, cJSON> package; // Package.json representation

	while (f.good()) {
		std::getline(f, line, '\n');
		json.append(line);
	}

	item = cJSON_Parse(json.c_str());

	//cJSON *subitem = item->child; // This is actually anything beneath the root tree
	/*while (subitem)
	{
		// handle subitem
	    // if (subitem->child) parse_object(subitem->child);
		string name = subitem->string;
		package.insert(name, subitem);

	    subitem = subitem->next;
	}*/

	//string maps[] = getProperty("content", "maps");
	//setProperty("title", "alterNateTitle");
	//f.write(cJSON_Print(item)); //Overwrite using modified version?

	return 0;
}


