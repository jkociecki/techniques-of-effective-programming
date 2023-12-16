template<typename T>
T NodeOperatorTwoArguments<T>::evaluate() const {
    double left_value = left->evaluate();
    double right_value = right->evaluate();

    if (operatation == ADDITION) return left_value + right_value;
    if (operatation == SUBTRACTION) return left_value - right_value;
    if (operatation == MULTIPLICATION) return left_value * right_value;
    if (operatation == DIVISION) return left_value / right_value;

    return 0;
}

template<typename T>
std::string NodeOperatorTwoArguments<T>::toString() const
{
    return operatation;
}

template<typename T>
std::vector<Node<T>*> NodeOperatorTwoArguments<T>::getVariables() const
{
    return std::vector<Node<T>*>() = {left, right};
}

template<typename T>
NodeOperatorTwoArguments<T>::~NodeOperatorTwoArguments()
{
    delete left;
    delete right;
}

template<typename T>
NodeOperatorTwoArguments<T>* NodeOperatorTwoArguments<T>::clone() const
{
    return new NodeOperatorTwoArguments(*this);
}
