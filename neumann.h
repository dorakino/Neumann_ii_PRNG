#ifndef _NEUMANN_H
#define  _NEUMANN_H

#include <iostream>
using namespace std;

class NeumannSecondGenerator{
private:
    int a = 0;
    int b = 0;

    int bev = 0;
    int per = 0;
public:
    void setNumbers(const int& first,const int& second){
        a = first;
        b = second;
    };

    int generateNumber(int aa, int bb){
        int myArr[4];
        int result;
        int numberOfDigits;

        int var = aa * bb;
        numberOfDigits = 0;
        int temp = var;
        while(temp >= 1){
            temp /= 10;
            numberOfDigits++;
        }
        int temp1 = numberOfDigits;
        for(int i = 4; i > 0; i--){
            if(temp1 > 0){
                myArr[i-1] = var % 10 ;
                var /= 10;
                temp1--;
            }
            else{
                myArr[i-1] = 0;
            }
        }
        if(numberOfDigits < 3){
            result = myArr[2] * 10 + myArr[3];
        }
        else{
            result = myArr[1] * 10 + myArr[2];
        }
        return result;
    };
    void method(){
        int cnt = 2;
        int tempArr[200];
        tempArr[0] = a;
        tempArr[1] = b;

        int myInt1 = a;
        int myInt2 = b;

        int temp6;
        int temp7;

        bool appeared = false;
        while(!appeared){
            temp6 = generateNumber(myInt1,myInt2);
            temp7 = generateNumber(myInt2,temp6);

            tempArr[cnt] = temp6;
            int j = 0;
            while(j < cnt)
            {
                if((tempArr[j] == temp6) && (tempArr[j+1] == temp7)){
                    appeared = true;
                    bev = j;
                    per = cnt - bev;
                    break;
                }
                j++;
            }
            if(cnt == 2 && bev == 0){
                per = 1;
            }
            myInt1 = myInt2;
            myInt2 = temp6;
            cnt++;
        }
    };
    int getFirst(){
        return a;
    };

    int getSecond(){
        return b;
    };

    int getBev(){
        return bev;
    };

    int getPer(){
        return per;
    };
};
#endif
