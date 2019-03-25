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

    int myVar1 = 0;
    int myVar2 = 0;

    int total1 = 1;
    int total2 = 1;

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            int cnt1 = 1;
            myVar1 = i;
            myVar2 = j;
            oneCase.setNumbers(myVar1,myVar2);
            oneCase.method();
     //       int temp4 = cnt1;
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

    cout << "bevezeto szakaszok:" << endl;
    for(int i = 0; i < total1; i++){
        cout << numberOfBevs[i][0] << "   " << numberOfBevs[i][1] << endl;
    }
    cout << "periodusok:" << endl;
    for(int i = 0 ; i < total2; i++){
        cout << numberOfPers[i][0] << "   " << numberOfPers[i][1] << endl;
    }
    return 0;
}
