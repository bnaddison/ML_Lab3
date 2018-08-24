// ADDBRA001 ML Lab 3

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <string>
#include <math.h>

#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

vector < pair< string, vector<float> > > data;

void readfile (string filename) {

  string line, input;
  ifstream in(filename);

  // Skip the first 5 lines
  getline(in, line);
  getline(in, line);
  getline(in, line);
  getline(in, line);
  getline(in, line);

  while ( getline(in >> ws, line) ) {

    string place = line;  // Place name
    getline(in, line);
    getline(in, line);
    float x = stof(line);  // January Rainfall recorded as float value
    getline(in, line);
    float y = stof(line);  // July Rainfall recorded as float value
    getline(in, line);
    getline(in, line);
    getline(in, line);

    vector <float> vars = {x,y};  // Jan/July components recorded as co-ordinate value
    pair<string, vector<float> > point(place, vars);  // pair to keep track of what values belong to what place
    data.push_back(point);
  }
}

// Component Average calculation function
float getAverage(int component) {
  float sum = 0;
  for (int i = 0; i < data.size(); i++) {
    sum += data[i].second[component];
  }
  float avg = sum/data.size();
  return avg;
}

// Variance/Covariance calculation function
float covar (int c1, int c2) {
  float sum = 0;
  for (int i = 0; i < data.size(); i++) {
    sum += (data[i].second[c1] - getAverage(c1))*(data[i].second[c2] - getAverage(c2));
  }
  float result = sum/(data.size()-1);
  return result;
}


int main () {

  readfile ("2018-AvgRainfall_mm_.txt");

  // 2x2 Matrix intialised
  Matrix<float, 2, 2> covarMatrix;

  // setting matrix vertices values
  covarMatrix(0,0) = covar(0,0);
  covarMatrix(0,1) = covar(0,1);
  covarMatrix(1,0) = covar(1,0);
  covarMatrix(1,1) = covar(1,1);

  EigenSolver<Matrix<float,2,2>> eigen(covarMatrix);
  cout << "Component 1 Variance: " << covar(0,0) << endl;
  cout << "Component 2 Variance: " << covar(1,1) << endl;
  cout << "Total Variance: " << covar(0,0) + covar(1,1) << endl << endl;
  cout << "Covariance Matrix:" << endl << "| " << covar(0,0) << ", " << covar(0,1) << " |" << endl << "| " << covar(1,0) << ", " << covar(1,1) << " |" << endl << endl;
  cout << "Eigenvalues:" << endl << eigen.eigenvalues().real() << endl << endl;
	cout << "Eigenvectors:" << endl << eigen.eigenvectors().real() << endl << endl;


  return 0;
}
