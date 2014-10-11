/*cjson_sample - a simple api to handle package.json files
Copyright (C) 2014  Fohlen <fohlen@einhufer.info>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
*/

#include <iostream>
#include <cstdlib>
#include <set>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "cJSON.h" //include cJSON.h using some g++ magic

using namespace std;

// Define api prototypes
map<string, cJSON *> package;
vector<cJSON *> getProperty(string cat);
cJSON* getProperty(string cat, string property); //This could also return typecasted values?
void setProperty(string cat, string property, cJSON * value);
void setProperty(string cat, string property, vector<cJSON *> values);
void setProperty(string cat, vector<cJSON *> values);
void setProperty(string cat, cJSON* value);

int main() {
	
	// Package.json demo
	fstream f;
	f.open("package.json"); // Open in rw mode


	if(!f.is_open()) exit(EXIT_FAILURE);

	cJSON * item; // Parser
	string line, json; // Input
	set<string> categories = { "title", "author", "date", "license", "content" }; //TODO: This ONLY work's with c++11 switch
	//map<string, cJSON *> package; // Package.json representation

	while (f.good()) {
		std::getline(f, line, '\n');
		json.append(line);
	}

	item = cJSON_Parse(json.c_str());
	cJSON *subitem = item->child; // This is actually anything beneath the root tree

	while (subitem)
	{
		// handle subitem
		string name = subitem->string;

		// Do some odd checks here
		if (categories.find(name) != categories.end()) {
			package[name] = subitem;
		}

	    subitem = subitem->next;
	}

	//cJSON* author = getProperty("author");
	//author->valuestring = "someone else";
	//setProperty("author", author);

	f.close();

	return EXIT_SUCCESS;
}

vector<cJSON *> getProperty(string cat) {
	cJSON* item = package[cat];
	vector<cJSON *> properties;

	while(item) {
		if (item->string == cat) {
			cJSON* subitem = item->child;

			while(subitem) {
				properties.push_back(subitem->child);
			}
		}

		item = item->next;
	}

	return properties;
}

/*TODO: This actually needs typecasting n stuff?
void setProperty(string cat, string property, vector<cJSON *> values) {
	cJSON* item = package[cat];

	while(item) {
			if (item->string == property) {
				cJSON* subitem = item->child;

				for(values::size_type i = 0; i != values.size(); i++) {
					cJSON_ReplaceItemInArray(subitem, values[i]->string, values[i]);
				}
			}

			item = item->next;
	}
}*/
