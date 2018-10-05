#pragma once
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

//delta1,delta2,delta3,zegavalue


map<int, double> getCut(string dataline){
	map<int, double> buffer;
	stringstream SS1;
	stringstream SS2;
	int ID=0;
	for (unsigned int i = 0; i < dataline.length(); ++i) {
		SS1.str("");
		SS1 << dataline.at(i);
		if (SS1.str() != ",") {
			SS2 << SS1.str();
		}
		else {
			buffer[ID] = stod(SS2.str());
			SS2.str("");
			ID++;
		}
	}
	if (SS1.str() != ",") {
		buffer[ID] = stod(SS2.str());
	}
	return buffer;
}


class Alator {

public:
	void setFile(string filepath) {
		filename = filepath;
	}

	map<int, double> getFrom(int pos) {
		map<int, double> dataD;
		readLoad(pos);
		// Here : cut of data string
		dataD = getCut(rawdata);
		return dataD;
	}


private:
	string filename;
	string rawdata;
	friend map<int, double> getCut(string dataline);
	void readLoad(int pos) {
		int i = 0;
		string line;
		ifstream fichier(filename);
		if (fichier.is_open()) {
			while (getline(fichier, line)) {
				if (pos == i) { rawdata = line; break; }
				i++;
			}
			fichier.close();
		}
	}

};

bool is_pair(double x) {
	double y = x / 2;
	if ( y - (int)y == 0 ) {
		return true;
	}
	return false;
}

int heuristic_prime(int x) {
	return !((2 ^ (x - 1) % x) % 2);
}

double calculus(double delta1, double delta2, double delta3, int x) {
	return (x / sqrt(delta1)) * log(abs(int(cos(tan(delta2*x)))) + x) + sin(tan(sqrt(sqrt(delta3*x))));
}

class Disector {
public:
	void compose(double delta1, double delta2, double delta3, double zegavalue) {
		double y;
		for (int i = 1; i != 100; i++) {
			y = calculus(delta1, delta2, delta3, i);
			if (y > 1) {
				if (heuristic_prime((int)round(y))) {
					matrixP[i] = true;
				}
				else {
					matrixP[i] = false;
				}
			}
		}
	}

	double getRatio() {
		double Tokay=0.0;
		double Total=0.0;
		for (map<int, bool>::iterator it = matrixP.begin(); it != matrixP.end(); ++it) {
			Total++;
			if (it->second) { Tokay++; }
		}
		return (Tokay / Total)*100;
	}



private:
	map<int, bool> matrixP;

	friend bool is_pair(double x);
};