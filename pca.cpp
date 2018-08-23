// ADDBRA001 Lab 3

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <string>
#include <math.h>

using namespace std;

vector <string> places;
vector <float> x_vals;
vector <float> y_vals;
vector < pair< string, pair<float,float> > > data;
int main () {

  string line, input;

  string h_place, xVar, yVar, obs, place, vars;

  string space;

  int obs_total, vars_total;

  //string x, y;


  cout << "Enter Input File name:" << endl;
  //cin >> input;

  ifstream in("2018-AvgRainfall_mm_.txt");

  getline(in, line);
  getline(in, line);
  getline(in, line);
  getline(in, line);
  getline(in, line);

  //in >> h_place >> xVar >> yVar >> space >> obs >> obs_total >> space >> place >> space >> x >> y >> space >> vars >> vars_total;
/*
  places.push_back(place);
  x_vals.push_back(x);
  y_vals.push_back(y);

*/
  while ( getline(in >> ws, line) ) {

    place = line;
    getline(in, line);
    getline(in, line);
    float x = stof(line);
    getline(in, line);
    float y = stof(line);
    getline(in, line);
    getline(in, line);
    getline(in, line);


    pair<float, float> vars (x, y);
    pair<string, pair<float, float> > point(place, vars);
    data.push_back(point);

  }
  for (int i = 0; i < data.size(); i++) {
    cout << data[i].first << " " << data[i].second.first << " " << data[i].second.second << endl;
  }
  //cout << places << xVar << yVar << obs << obs_total<< endl;

return 0;
}
