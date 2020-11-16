/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream inputfile;
	inputfile.open(filename.c_str(), ios_base::in);

	if (!inputfile.is_open()){
		contents.clear();
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	string line;
	while(!inputfile.eof()){
		getline(inputfile, line);
		contents += line;
	}

	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outputfile;
	outputfile.open(filename.c_str(), ios_base::out);

	if(!outputfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	for(unsigned int i = 0; i < myEntryVector.size(); i++){
		outputfile << myEntryVector[i] << endl;
	}
	return SUCCESS;
}



