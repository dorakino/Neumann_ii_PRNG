#include <iostream>
#include <vector>
#include <algorithm>
#include "neumann.h"
using namespace std;

int main()
{
    NeumannSecondGenerator oneCase;
    vector< vector<int> > vecNumberOfBevs;
    vector< vector<int> > vecNumberOfPers;

    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);

    vecNumberOfBevs.push_back(temp);
    vecNumberOfPers.push_back(temp);

    int total1 = vecNumberOfBevs.size();
    int total2 = vecNumberOfPers.size();

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            oneCase.setNumbers(i,j);
            oneCase.method();

            int h = 0;
            while(h < total1){
                if(vecNumberOfBevs[h][0] == oneCase.getBev()){
                    vecNumberOfBevs[h][1]++;
                    break;
                }
                h++;
            }
            if(h == total1){
                vector<int> myrow1;
                if((vecNumberOfBevs[h-1][0] == 0) && (vecNumberOfBevs[h-1][1] == 0)){
                    vecNumberOfBevs[h-1][0] = oneCase.getBev();
                    vecNumberOfBevs[h-1][1] = 1;
                }
                else{
                    myrow1.push_back(oneCase.getBev());
                    myrow1.push_back(1);
                    vecNumberOfBevs.push_back(myrow1);
                    total1++;
                }
            }

            int l = 0;
            while(l < total2){
                if(vecNumberOfPers[l][0] == oneCase.getPer()) {
                    vecNumberOfPers[l][1]++;
                    break;
                }
                l++;
            }
            if(l == total2){
                vector<int> myrow2;
                if((vecNumberOfPers[l-1][0] == 0) && (vecNumberOfPers[l-1][1] == 0)){
                    vecNumberOfPers[l-1][0] = oneCase.getPer();
                    vecNumberOfPers[l-1][1] = 1;
                }
                else{
                    myrow2.push_back(oneCase.getPer());
                    myrow2.push_back(1);
                    vecNumberOfPers.push_back(myrow2);
                    total2++;
                }
            }
        }
    }

    std::sort(vecNumberOfBevs.begin(),vecNumberOfBevs.end());
    std::sort(vecNumberOfPers.begin(),vecNumberOfPers.end());

    cout << "length of initiatory lines, and the number of their appearance:" << endl;
    for(int i = 0; i < total1; i++){
        cout << vecNumberOfBevs[i][0] << "   " << vecNumberOfBevs[i][1] << endl;
    }

    cout << "length of periods, and the number of their appearance:" << endl;
    for(int i = 0 ; i < total2; i++){
        cout << vecNumberOfPers[i][0] << "   " << vecNumberOfPers[i][1] << endl;
    }
    return 0;
}
