#include<iostream>
const int NUMBER_DEAFULT_LENGTH = 0;
const int BASE = 10;

class CNumber {
private:
    int* pi_number;
    int i_length;
    bool is_negative;

    static CNumber multiply(const CNumber& c_number1, const CNumber& c_number2);
    static CNumber divide(const CNumber& c_number1, const CNumber& c_number2);
    static CNumber subtraction(const CNumber& c_number1, const CNumber& c_number2);
    static CNumber add(int* pi_number1, int size1, int* pi_number2, int size2);

    //helper methods
    static bool is_greater_with_lead_zeros(int* number1, int size1, int* number2, int size2);
    static void subtraction_with_lead_zeros(int* number1, int size1, int* number2, int size2);
    static void shift_left(int* table, int size, int shift);
    static void shift_right(int* table, int size, int shift);
    static void adjust_pi_number(int*& pi_number, int& size);

    bool is_abs_val_greater(const CNumber& c_number) const;
    void set_from_int(int number);
    CNumber check_cases_sub(const CNumber& c_number) const;
    CNumber check_cases_add(const CNumber& c_number) const;
    int toInt() const;

public:
    CNumber();
    CNumber(int number);
    CNumber(int* pi_number, int size, bool is_negative);
    CNumber(const CNumber& c_number);
    ~CNumber();

    CNumber operator+(const CNumber& c_number) const;
    CNumber operator+(int number) const;

    CNumber operator-(const CNumber& c_number) const;
    CNumber operator-(int number) const;

    bool operator>=(const CNumber& c_number) const;
    bool operator>(const CNumber& c_number) const;


    CNumber& operator<=(const CNumber& other);


    bool operator==(const CNumber& c_number) const;
    bool operator==(int number) const;

    CNumber operator*(const CNumber& c_number) const;
    CNumber operator*(int number) const;

    CNumber operator/(const CNumber& c_number) const;
    CNumber operator/(int number) const;

    CNumber& operator=(const CNumber& c_number);
    CNumber& operator=(int i_number);


    int* get_pitab();
    int get_length();
    bool get_is_negative();

    std::string toString();

    friend int operator<=(int &val, const CNumber& pcother);

};