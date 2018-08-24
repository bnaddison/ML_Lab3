// ADDBRA001 Lab 3

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

vector <string> places;
vector <float> x_vals;
vector <float> y_vals;
vector < pair< string, vector<float> > > data;

void readfile (string filename) {

  string line, input;


  ifstream in(filename);

  getline(in, line);
  getline(in, line);
  getline(in, line);
  getline(in, line);
  getline(in, line);

  while ( getline(in >> ws, line) ) {

    string place = line;
    getline(in, line);
    getline(in, line);
    float x = stof(line);
    getline(in, line);
    float y = stof(line);
    getline(in, line);
    getline(in, line);
    getline(in, line);

    vector <float> vars = {x,y};
    //pair<float, float> vars (x, y);
    pair<string, vector<float> > point(place, vars);
    data.push_back(point);
    //delete vars;

  }
}

float getAverage(int component) {
  float sum = 0;
  for (int i = 0; i < data.size(); i++) {
    sum += data[i].second[component];
  }
  float avg = sum/data.size();
  return avg;
}

float var (int component) {
  float sum = 0;

  for (int i = 0; i < data.size(); i++) {
    sum += pow(data[i].second[component] - getAverage(component), 2);
  }

  float result = sum/(data.size()-1);

  return result;

}

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
  cout << var(0) << " " << var(1) << " " << covar(0,1) << " " << covar(1,0) << endl;
/*
  for (int i = 0; i < data.size(); i++) {
    cout << data[i].first << " " << data[i].second[0] << " " << data[i].second[1] << endl;
  } */
  //cout << places << xVar << yVar << obs << obs_total<< endl;

return 0;
}
