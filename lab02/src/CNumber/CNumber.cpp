#include <iostream>
#include "../../include/CNumber.h"
#include <cmath>


CNumber::CNumber() : i_length(NUMBER_DEAFULT_LENGTH), is_negative(false) {
    pi_number = new int[i_length];
}

CNumber::CNumber(int i_number) {
    set_from_int(i_number);
}


int* CNumber::get_pitab(){return pi_number;}
int CNumber::get_length(){return i_length;}
bool CNumber::get_is_negative(){return is_negative;}

int CNumber::toInt() const {
    int number = 0;
    for (int i = i_length - 1; i >= 0; i--)
    {
        number += pi_number[i] * pow(BASE, i);
    }
    if (is_negative) {
        number = -number;
    }
    return number;
}



CNumber::CNumber(int* pi_number, int size, bool is_negative) : pi_number(pi_number), i_length(size), is_negative(is_negative) {}

std::string CNumber::toString() {
    std::string result;
    if(is_negative) result += "-";
    for(int i = i_length - 1; i >= 0; i--)
    {
        result += pi_number[i] + '0';
    }
    return result;
}

CNumber::~CNumber() {
    delete[] pi_number;
}

CNumber::CNumber(const CNumber& pcOther){
        i_length = pcOther.i_length;
        is_negative = pcOther.is_negative;
        pi_number = new int[i_length];
        for (int i = 0; i < i_length; i++)
        {
            pi_number[i] = pcOther.pi_number[i];
        }
}


void CNumber::set_from_int(int i_number) {
    i_length = (i_number == 0) ? 1 : floor(log10(abs(i_number)) + 1);
    is_negative = i_number < 0;
    pi_number = new int[i_length];

    for (int i = 0; i < i_length; i++)
    {
        pi_number[i] = abs(i_number) % 10;
        i_number /= 10;
    }
}

CNumber CNumber::check_cases_sub(const CNumber& c_number) const {
    CNumber result;
    if (this->is_negative && c_number.is_negative)
    {
        if (*this > c_number) {result.is_negative = true; result =  (*this, c_number);}
        if (*this == c_number) {result.is_negative = false, result = CNumber(0);}
        else { result.is_negative = false; result = subtraction(c_number, *this); }
    }
    else if (this->is_negative)
    {
        result = add(this->pi_number, this->i_length, c_number.pi_number, c_number.i_length);
        result.is_negative = true;
    }
    else if (c_number.is_negative)
    {
        result = add(this->pi_number, this->i_length, c_number.pi_number, c_number.i_length);
    }
    else
    {
        if (*this > c_number) { result = subtraction(*this, c_number); }
        else if(*this == c_number) {result.is_negative = false, result = CNumber(0);}
        else { result = subtraction(c_number, *this); result.is_negative = true; }
    }
    while (result.i_length > 1 && result.pi_number[result.i_length - 1] == 0) {
        result.i_length--;
    }
    return result;
}

CNumber CNumber::check_cases_add(const CNumber& c_number) const{
    CNumber result;
    if (this->is_negative && c_number.is_negative)
    {
        result = add(this->pi_number, this->i_length, c_number.pi_number, c_number.i_length);
        result.is_negative = true;
    }
    else if (this->is_negative)
    {
        if (is_abs_val_greater(c_number))
        {
           result = subtraction(*this, c_number);
            result.is_negative = true;
        }
        else if(*this == c_number) result = CNumber(0);
        else result = subtraction(c_number, *this);
    }
    else if (c_number.is_negative)
    {
        if (!is_abs_val_greater(c_number))
        {
            result = subtraction(c_number, *this);
            result.is_negative = true;
        }
        else if(*this == c_number) {result = CNumber(0);}
        else result = subtraction(*this, c_number);
    }
    else
    {
        result = add(this->pi_number, this->i_length, c_number.pi_number, c_number.i_length);
    }
    return result;
}