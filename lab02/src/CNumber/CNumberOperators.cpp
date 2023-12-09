#include "../../include/CNumber.h"



CNumber& CNumber::operator<=(const CNumber& other) {
    if (this != &other) {
        delete[] pi_number;
        i_length = other.i_length;
        is_negative = other.is_negative;
        pi_number = new int[i_length];
        for (int i = 0; i < i_length; i++) {
            pi_number[i] = other.pi_number[i];
        }
    }
    return *this;
}



bool CNumber::operator==(const CNumber& c_number) const {
    if (is_negative != c_number.is_negative || i_length != c_number.i_length) return false;

    for (int i = 0; i < i_length; i++)
    {
        if (pi_number[i] != c_number.pi_number[i]) return false;

    }
    return true;
}
bool CNumber::operator==(const int number) const{
    CNumber temp(number);
    return *this == temp;
}




CNumber& CNumber::operator=(int i_number){
    delete[] pi_number;
    set_from_int(i_number);
    return *this;
}
CNumber& CNumber::operator=(const CNumber& c_number){
    if (this == &c_number) return *this;
    delete[] pi_number;
    i_length = c_number.i_length;
    is_negative = c_number.is_negative;
    pi_number = new int[i_length];
    for (int i = 0; i < i_length; i++)
    {
        pi_number[i] = c_number.pi_number[i];
    }
    return *this;
}


CNumber CNumber::operator-(const CNumber& c_number) const {
    return check_cases_sub(c_number);
}
CNumber CNumber::operator-(const int number) const{
    CNumber temp(number);
    temp = *this - temp;
    return temp;
}


CNumber CNumber::operator*(const CNumber& c_number) const {
    CNumber result = multiply(*this, c_number);
    if (this->is_negative && !c_number.is_negative) result.is_negative = true;
    else if (!this->is_negative && c_number.is_negative) result.is_negative = true;
    return result;
}
CNumber CNumber::operator*(const int number) const {
    CNumber temp(number);
    temp = *this * temp;
    return temp;
}


CNumber CNumber::operator+(const CNumber& c_number) const {
    return check_cases_add(c_number);
}
CNumber CNumber::operator+(const int number) const {
    CNumber temp(number);
    temp = *this + temp;
    return temp;
}




CNumber CNumber::operator/(const CNumber &c_number) const {
    CNumber result(0);
    if (c_number == 0) throw std::invalid_argument("pamietaj cholero nie dziel przez 0");
    else if(!is_abs_val_greater(c_number)) return result;
    else
    {
        result = divide(*this, c_number);
        if (this->is_negative && !c_number.is_negative) result.is_negative = true;
        else if (!this->is_negative && c_number.is_negative) result.is_negative = true;
        return result;
    }
}
CNumber CNumber::operator/(const int number) const {
    CNumber temp(number);
    temp = *this / temp;
    return temp;
}





bool CNumber::operator>(const CNumber& c_number) const {
    if (is_negative && !c_number.is_negative) return false;
    else if (!is_negative && c_number.is_negative) return true;
    else if (i_length > c_number.i_length) return !is_negative;
    else if (i_length < c_number.i_length) return is_negative;


    for (int i = i_length - 1; i >= 0; i--)
    {
        if (pi_number[i] > c_number.pi_number[i]) return !is_negative;
        else if (pi_number[i] < c_number.pi_number[i]) return is_negative;
    }
    return false;
}
bool CNumber::operator>=(const CNumber& c_number) const {
    if (is_negative && !c_number.is_negative) return false;
    else if (!is_negative && c_number.is_negative) return true;
    else if (i_length > c_number.i_length) return !is_negative;
    else if (i_length < c_number.i_length) return is_negative;

    for (int i = i_length - 1; i >= 0; i--)
    {
        if (pi_number[i] > c_number.pi_number[i]) return !is_negative;
        else if (pi_number[i] < c_number.pi_number[i]) return is_negative;

    }
    return true;
}





void CNumber::shift_left(int *table, int size, int shift) {
    for (int i = size - 1; i >= shift; i--)
    {
        table[i] = table[i - shift];
    }
    for (int i = 0; i < shift; i++)
    {
        table[i] = 0;
    }
}
void CNumber::shift_right(int *table, int size, int shift) {
    for (int i = 0; i < size - shift; i++)
    {
        table[i] = table[i + shift];
    }
    for (int i = size - shift; i < size; i++)
    {
        table[i] = 0;
    }
}

//void ExpressionTree::join(ExpressionTree* first, ExpressionTree* second)
//{
//    Node* first_parent = first->get_parent_of_leaf(first->root, nullptr);
//    if (is_variable(first_parent->get_child(0)->data))
//    {
//        delete first_parent->children->at(0);
//        first_parent->children->at(0) = second->root;
//    }
//    else
//    {
//        delete first_parent->children->at(1);
//        first_parent->children->at(1) = second->root;
//    }
//}
//
//ExpressionTree ExpressionTree::operator+(const ExpressionTree& tree) const
//{
//    ExpressionTree* result = new ExpressionTree(*this);
//    ExpressionTree::join(result, new ExpressionTree(tree));
//    return *result;
//}



//
//ExpressionTree ExpressionTree::add_trees(const ExpressionTree& first, const ExpressionTree& second)
//{
//    ExpressionTree result = ExpressionTree(first);
//    Node* result_parent = result.get_parent_of_leaf(result.root, nullptr);
//    Node* second_tree_node = new Node(*second.root);
//
//    if (is_variable(result_parent->get_child(0)->data))
//    {
//        delete result_parent->children->at(0);
//        result_parent->children->at(0) = second_tree_node;
//    }
//    else
//    {
//        delete result_parent->children->at(1);
//        result_parent->children->at(1) = second_tree_node;
//    }
//
//    return result;
//}


