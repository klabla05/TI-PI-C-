#include <iostream>
using namespace std;
float result = 0;
float add(float a, float b){
    result = a+b;
    return result;
}
float minus(float a, float b){
    result = a-b;
    return result;
}
float multiplication(float a, float b){
    result = a*b;
    return result;
}
float divide(float a, float b){
    if(b!=0){
        result = a/b;
        return result;
    }
    else {
        cout<<"You can not divide by 0";
    }
}
int check_number(float a, float b){
    while (true) {
        cout<<"Give the first number: ";
        cin>>a;
        cout<<"Give the second number: ";
        cin>>b;
        
    }
}
int main(){
    float a;
    float b;
    int decide;
    cout<<"Welcome to the calculator. Please, give the two numbers, and then decide what you want to do with them"<<endl;
    cout<<"Thanks, now you will decide what to do with them. The options are:"<<endl<<"1. Add the numbers"<<endl<<"2. You can substract one another"<<endl;
    cout<<"3. Multiply them"<<endl<<"4. Divide them"<<endl;;
    cout<<"To decide, just type in the number of the operation that you are interested in";
}