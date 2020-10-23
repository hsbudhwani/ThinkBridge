// C++ program to print a given number in words. 

#include <iostream>
#include<cmath>
#include<cctype>

using namespace std;
string convertToWords(int);


int main()
{
    cout<<"******************************"<<endl;
    cout<<"----------Hello User----------"<<endl<<endl;
    cout<<"******************************"<<endl<<endl;
    double inputNum;
    char choice ='y';

    //Loop Starts Here
    while (choice == 'y' || choice == 'Y')
    {

    cout << "Enter the Currency Value\n";

    //Receive user input & Checking for Character

    while(!(cin >> inputNum)){
        cout <<"Invalid Character, Please Enter Valid currency Value from 00 to 9,99,999.99 "<<endl;
        cin.clear();
        cin.ignore(123,'\n');
    }

    //For invalid Input

    if(inputNum<0.0 || inputNum>1000000){
    cout <<"Enter the Valid currency Value from 00 to 9,99,999.99"<<endl;
    }

    //For Zero Input

    if(inputNum==isdigit(0))
    cout <<"Rs. zero ONLY";

    //For Whole Number this will execute

    if(inputNum>0.0 && inputNum<1000000)
    {
    // convert given number in words
    cout <<"Rs. "<< convertToWords(inputNum);
    }

    //For Decimal Part this will Execute

    float fractionPart=inputNum - floor(inputNum);
    fractionPart*=100;

    if(fractionPart>0 && fractionPart<100)
    cout <<(int)fractionPart<<"/100 ONLY";

    else if(fractionPart==0 && inputNum>0.0 && inputNum<1000000)
    cout<<" ONLY";

    cout<<endl<<"Would you like to perform another conversation? (Y/N) :"<<endl;
    cin>>choice;
    }//End of While Loop
    cout<<endl;
    cout<<"******************************"<<endl;
    cout<<"---------- Good Bye ----------"<<endl<<endl;
    cout<<"******************************"<<endl<<endl;
    return 0;
}

// strings at index 0 is not used, it is to make array
// indexing simple
string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };

// strings at index 0 and 1 are not used, they is to
// make array indexing simple
string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };

// n is 1- or 2-digit number
string numToWords(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    // if n is non-zero
    if (n)
        str += s;

    return str;
}

// Function to print a given number in words
string convertToWords(int n)
{
    // stores word representation of given number n
    string out;

    // handles digits at hundred thousands and one
    // millions places (if any)
    out += numToWords(((n / 100000) % 100), "lakh ");

    // handles digits at thousands and tens thousands
    // places (if any)
    out += numToWords(((n / 1000) % 100), "thousand ");

    // handles digit at hundreds places (if any)
    out += numToWords(((n / 100) % 10), "hundred ");

    if (n > 100 && n % 100)
        out += "and ";

    // handles digits at ones and tens places (if any)
    out += numToWords((n % 100), "");

    return out;
}
