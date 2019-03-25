#include <iostream>
#include "neumann.h"
using namespace std;

int main()
{
    NeumannSecondGenerator oneCase;

    int numberOfBevs[500][2];
    int numberOfPers[200][2];

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 2 ; j++){
            numberOfBevs[i][j] = 0;
        }
    }
    for(int i = 0;i < 100; i++){
        for(int j = 0;j < 2; j++){
            numberOfPers[i][j] = 0;
        }
    }

    int total1 = 1;
    int total2 = 1;

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            int cnt1 = 1;
            oneCase.setNumbers(i,j);
            oneCase.method();
            int h = 0;
            while(h < total1){
                if(numberOfBevs[h][0] == oneCase.getBev()){
                    numberOfBevs[h][1]++;
                    break;
                }
                h++;
            }
            if(h == total1){
                if(numberOfBevs[h-1][0] == 0 && numberOfBevs[h-1][1] == 0){
                    numberOfBevs[h-1][0] = oneCase.getBev();
                    numberOfBevs[h-1][1] = 1;
                }
                else{
                   numberOfBevs[h][0] = oneCase.getBev();
                    numberOfBevs[h][1] = 1;
                    total1++;
                }
            }

            int l = 0;
            while(l < total2){
                if(numberOfPers[l][0] == oneCase.getPer()){
                    numberOfPers[l][1]++;
                    break;
                }
                l++;
            }
            if(l == total2){
                if(numberOfPers[l-1][0] == 0 && numberOfPers[l-1][1] == 0){
                    numberOfPers[l-1][0] = oneCase.getPer();
                    numberOfPers[l-1][1] = 1;
                }
                else{
                   numberOfPers[l][0] = oneCase.getPer();
                    numberOfPers[l][1] = 1;
                    total2++;
                }
            }
        }
    }

    cout << "length of initiatory lines, and the number of their appearance:" << endl;
    for(int i = 0; i < total1; i++){
        cout << numberOfBevs[i][0] << "   " << numberOfBevs[i][1] << endl;
    }
    cout << "length of periods, and the number of their appearance:" << endl;
    for(int i = 0 ; i < total2; i++){
        cout << numberOfPers[i][0] << "   " << numberOfPers[i][1] << endl;
    }
    return 0;
}
