#include "../../include/CNumber.h"


bool CNumber::is_abs_val_greater(const CNumber& c_number) const {
    if (i_length > c_number.i_length)
    {
        return true;
    }
    else if (i_length < c_number.i_length)
    {
        return false;
    }
    for (int i = i_length - 1; i >= 0; i--)
    {
        if (pi_number[i] > c_number.pi_number[i])
        {
            return true;
        }
        else if (pi_number[i] < c_number.pi_number[i])
        {
            return false;
        }
    }
    return false;
}

void CNumber::adjust_pi_number(int*& pi_number, int& size) {
    while (size > 1 && pi_number[size - 1] == 0)
    {
        size--;
    }
    int* new_pi_number = new int[size];
    for (int i = 0; i < size; i++)
    {
        new_pi_number[i] = pi_number[i];
    }
    delete[] pi_number;
    pi_number = new_pi_number;
}

CNumber CNumber::add(int* pi_number1, int size1, int* pi_number2, int size2) {
    int max_length = std::max(size1, size2) + 1;
    int* result = new int[max_length];
    int carry = 0;
    for (int i = 0; i < max_length; i++)
    {
        int cnumber1 = (i < size1) ? pi_number1[i] : 0;
        int cnumber2 = (i < size2) ? pi_number2[i] : 0;
        int sum = cnumber1 + cnumber2 + carry;
        result[i] = sum % BASE;
        carry = sum / BASE;
    }
    adjust_pi_number(result, max_length);
    CNumber toReturn;
    toReturn.pi_number = result;
    toReturn.i_length = max_length;
    return toReturn;
}

void CNumber::subtraction_with_lead_zeros(int* number1, int size1, int* number2, int size2) {
    int max_length = std::max(size1, size2);
    int borrow = 0;
    for (int i = 0; i < max_length; i++)
    {
        int digit1 = i >= size1 ? 0 : number1[i];
        int digit2 = i >= size2 ? 0 : number2[i];
        int difference = digit1 - digit2 - borrow;
        if (difference < 0) {
            difference += BASE;
            borrow = 1;
        } else borrow = 0;

        number1[i] = difference;
    }
}

CNumber CNumber::subtraction(const CNumber &c_number1, const CNumber &c_number2) {
    int max_length = std::max(c_number1.i_length, c_number2.i_length);
    int* result = new int[max_length];
    int borrow = 0;
    for (int i = 0; i < max_length; i++)
    {
        int digit1 = i >= c_number1.i_length ? 0 : c_number1.pi_number[i];
        int digit2 = i >= c_number2.i_length ? 0 : c_number2.pi_number[i];
        int difference = digit1 - digit2 - borrow;
        if (difference < 0)
        {
            difference += BASE;
            borrow = 1;
        }
        else borrow = 0;
        result[i] = difference;
    }
    adjust_pi_number(result, max_length);
    CNumber toReturn;
    toReturn.pi_number = result;
    toReturn.i_length = max_length;
    return toReturn;
}


CNumber CNumber::multiply(const CNumber& c_number1, const CNumber& c_number2) {
    int size = c_number1.i_length + c_number2.i_length;
    int* result_number = new int[size]();

    for (int i = 0; i < c_number1.i_length; i++) {
        int carry = 0;
        for (int j = 0; j < c_number2.i_length; j++) {
            int& result_digit = result_number[i + j];
            int current_product = c_number1.pi_number[i] * c_number2.pi_number[j] + result_digit + carry;
            result_digit = current_product % BASE;
            carry = current_product / BASE;
        }
        if (carry > 0) {
            result_number[i + c_number2.i_length] += carry;
        }
    }

    adjust_pi_number(result_number, size);
    CNumber result(result_number, size, false);
    return result;
}




CNumber CNumber::divide(const CNumber& c_number1, const CNumber& c_number2){
    int rest[c_number1.i_length];
    int result_size = c_number1.i_length - c_number2.i_length + 1;
    CNumber result(new int[result_size], result_size, false);
    int current_index = c_number1.i_length;
    int size = 1;
    bool lead_zero_flag = false;
    while(current_index > 0)
    {
        CNumber::shift_left(rest, size, 1);
        rest[0] = c_number1.pi_number[current_index - 1];
        int result_digit = 0;
        while(CNumber::is_greater_with_lead_zeros(rest, size, c_number2.pi_number, c_number2.i_length))
        {
            CNumber::subtraction_with_lead_zeros(rest, size, c_number2.pi_number, c_number2.i_length);
            result_digit++;
            lead_zero_flag = true;
        }
        if(lead_zero_flag) {result.pi_number[result_size - 1] = result_digit; result_size--;}
        current_index--;
        size++;
    }
    if(result_size == 1)
    {
        CNumber::shift_right(result.pi_number, result.i_length, 1);
        result.i_length--;
    }
    return result;
}

bool CNumber::is_greater_with_lead_zeros(int *number1, int size1, int *number2, int size2)  {
    int this_idx = size1 - 1;
    int other_idx = size2 - 1;

    while (this_idx >= 0 && number1[this_idx] == 0) this_idx--;
    while (other_idx >= 0 && number2[other_idx] == 0) other_idx--;

    if (this_idx + 1 > other_idx + 1) return true;
    else if (this_idx + 1 < other_idx + 1) return false;

    for (int i = this_idx; i >= 0; i--)
    {
        if (number1[i] > number2[i]) return true;
        else if (number1[i] < number2[i]) return false;
    }
    return true;
}
