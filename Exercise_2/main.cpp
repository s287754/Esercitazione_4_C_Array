#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Utils.hpp>

using namespace std;

int main ()
{
    string inputFileName = "data.csv";
    int S;
    size_t n = 0;
    double* w = nullptr;
    double* r= nullptr;

    if (!ImportValue(inputFileName,S,n,w,r)) {
        cerr << "Errore nel caricamento dei dati" << endl;
            }
    else {
        cout << "Caricamento avvenuto con successo: S = " <<  S << "n = " << n << "w = " << ArrayToString (n,S,w,r) << "r = " << ArrayToString (n,S,w,r) << endl;
            }



    double rateofreturn = RateReturn (n,w,r);
    cout << "Rate of return of the portfolio " << rateofreturn  << endl;

    string outputFileName = "result.txt";

    if (!ExportValue (outputFileName,n,S,w,r,rateofreturn)) {
        cerr << "Esportazione su file non riuscita" << endl;
        return -1;
    }
    else {
        cout << "Esportazione dei risultati avvenuta con successo" << endl;
    }


    delete [] r;
    delete [] w;

    return 0;

}


