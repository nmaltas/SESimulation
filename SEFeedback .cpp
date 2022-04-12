#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream> // Use this line to export data in a .txt file

using namespace std;
int RandomVariable;

bool RBG ( int P ){
RandomVariable = (rand()%100) +1 ;

if (RandomVariable <= P) {
    return 1;
}
else {
    return 0;
}
}

int main(){

srand(time(0));
int Input1, Input2, Input3, Input4, NumberOfInputs, TotalInputs, Output1, Output2, Feedback;
int P = 2;
double Total;
int Iterations = 100000;
double Throughput = 0;


cout << "Inputs\tOutputs\tThroughput\n";
cout << "****************************************\n";

//////////////////////////////////////////////////
// THIS PART'S PURPOSE IS TO EXPORT THE DATA TO A .TXT FILE. OMMIT IT OTHERWISE
ofstream Data;
Data.open("C:\\Users\\silma\\Desktop\\Data.txt");
Data << "Inputs\tOutputs\tThroughput\n";
Data << "****************************************\n";
/////////////////////////////////////////////////

for ( P; P <= 100; P = P + 2){
    Total = 0;
    TotalInputs = 0;
    Feedback = 0;
    for (int i = 0; i < Iterations; i++) {
        Input1 = RBG(P);
        Input2 = RBG(P);
        Input3 = RBG(P);
        Input4 = Feedback;
        NumberOfInputs = Input1 + Input2 + Input3 + Feedback;

        if (NumberOfInputs == 0) {
            Output1 = Output2 = Feedback = 0;
        }
        else if (NumberOfInputs == 1) {
            Output1 = 1;
            Output2 = 0;
            Feedback = 0;
        }
        else if (NumberOfInputs == 2) {
            Output1 = 1;
            Output2 = 1;
            Feedback = 0;
        }
        else {
            Output1 = 1;
            Output2 = 1;
            Feedback = 1;
        }
        TotalInputs = TotalInputs + NumberOfInputs;
        Total = Total + Output1 + Output2;


    }

    Throughput = Total/Iterations;
    cout << TotalInputs << "\t|" <<Total << "\t|" << Throughput << endl;
    Data << TotalInputs << "\t" <<Total << "\t" << Throughput << endl; // THIS LINE EXPORTS TO A .TXT FILE
}



    return 0;
}
