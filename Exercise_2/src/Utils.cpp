#include <Utils.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;


bool ImportValue(const string& inputFilePath,
                 unsigned int& S,
                 size_t& n,
                 double*& r,
                 double*& w)
{

    //apro il file
    ifstream ifs;
    ifs.open(inputFilePath);
    if (ifs.fail()) {
        cerr << "Apertura del file fallita" << endl;
        return false;
    }

    char ch;
    string line;

    while (!ifs.eof()) {
        getline (ifs,line);
        istringstream convertS;
        convertS.str(line);
        convertS >> ch >> ch >> S ;//salta i valori di S e ;
        break;
    }
    while (!ifs.eof()) {
        istringstream convertN;
        convertN.str(line);
        convertN >> ch >> ch >> n; //salta i valori di n e ;
        break;
    }
    w = new double [n];
    r = new double [n];
    while (!ifs.eof())
        {
            getline (ifs,line);
    }

    istringstream convert;
    for (unsigned int i = 0; i < n; i++) {
        convert >> w[i] >> ch >> r[i];   //ho creato i miei vettori w ed r
    }


    ifs.close();
    return true;
    }


double RateReturn (size_t& n,
                            const double* const& w,
                            const double* const& r)
{
    double rateofreturn = 0;

    for (unsigned int i = 0; i < n; i++ ) {
        rateofreturn = rateofreturn + (r[i]*w[i]);

        return rateofreturn;
    }
}

bool ExportValue (const string& outputFilePath,
                  const size_t& n,
                  const int& S,
                  const double* const& w,
                  const double* const& r,
                  const double& rateofreturn) {
    ofstream file;
    file.open(outputFilePath);
    if (file.fail()) {
        cerr << "Errore nell'apertura del file!"<< endl;
        return false;
    }
    file << "S= " << S <<endl;
    file << "n= " << n << endl;
    for (unsigned int i = 0; i < n; i++) {
        file << "w = " << w << endl;
    }

    for (unsigned int i = 0; i < n; i++) {
        file << "r = " << r << endl;
    }
    double V = S * (1+rateofreturn);

    file << "Rate of return of the porfolio: " << rateofreturn << endl;
    file << "V = " << V << endl;

    file.close();

    return true;
}

string ArraytoString(const size_t& n,
                    const int& S,
                    const double* w,
                    const double*r) {

    string stringa;
    ostringstream toString;
    toString << "S=" << S << endl;
    toString << "n=" << n << endl;
    toString << "[" ;
    for (unsigned int i = 0; i< n; i++) {
        toString << w[i] << " " ;

    }
    toString << "]" << endl ;

    toString << "[" ;

    for (unsigned int i = 0; i < n; i++) {
        toString << r[i] << " " ;
    }
    toString << "]" << endl;

    toString << "Rate of return of portfolio:" << endl;
    toString << "V: " << endl;
    string line = toString.str();
    return line;

}


