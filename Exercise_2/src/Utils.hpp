#pragma once
#include <iostream>

using namespace std;

bool ImportValue (const string& inputFilePath,
                  const unsigned int& S,
                  const size_t& n,
                  double*& r,
                  double*& w);

double RateReturn (const size_t& n,
                            const double* const& w,
                            const double* const& r);

bool ExportValue (const string& outputFilePath,
                  const size_t& n,
                  const int& S,
                  const double* const& w,
                  const double* const& r,
                  const double& portfolioValue);

string ArrayToString (const size_t& n,
                      const int& S,
                      const double* w,
                      const double*r);
