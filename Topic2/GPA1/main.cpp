#include <iostream>

using namespace std;

struct rational {
   int numerator;
   int denominator;
};

void reduce(rational*, rational*);
bool isEqual(rational*, rational*);
unsigned int gcd(unsigned int, unsigned int);

int main()
{
    int result;
    struct rational num1, num2;

    cout << "Enter Details of Number 1 " << endl;
    cout << "Enter Numerator :" << endl;
    cin >> num1.numerator;
    cout << "Enter Denominator :" << endl;
    cin >> num1.denominator;
    cout << "Enter Details of Number 2 " << endl;
    cout << "Enter Numerator :" << endl;
    cin >> num2.numerator;
    cout << "Enter Denominator :" << endl;
    cin >> num2.denominator;

    result = isEqual(&num1, &num2);     //to check rational 'num1' is equal to rational 'num2'

    if(result == true)
        cout << "Both rational numbers are equal" << endl;
    else
        cout << "Both rational numbers are not equal" << endl;

    return 0;
}

unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

void reduce(rational *input_rational, rational *output_rational)
{
    unsigned int _gcd = gcd(input_rational->numerator, input_rational->denominator);

    output_rational->numerator = input_rational->numerator/_gcd;
    output_rational->denominator = input_rational->denominator/_gcd;
}

bool isEqual(rational *num1, rational *num2)
{
    rational *num1_reduced = new rational;
    reduce(num1, num1_reduced);

    rational *num2_reduced = new rational;
    reduce(num2, num2_reduced);

    bool result = num1_reduced->numerator == num2_reduced->numerator
        && num1_reduced->denominator == num2_reduced->denominator;

    delete num1_reduced;
    delete num2_reduced;

    return result;
}


