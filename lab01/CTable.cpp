#include <iostream>
#include "CTable.h"

CTable::CTable() : size(10), s_name("default value") {
    pTable = new int[size];
    std::cout << "bezparametrowy: " << s_name << std::endl;
}

CTable::CTable(int size, std::string s_name) : size(size), s_name(s_name) {
    pTable = new int[size];
    std::cout << "parametrowy: " << s_name << std::endl;
}

CTable::CTable(CTable &other) : size(other.size), s_name(other.s_name + "_copy") {
    pTable = new int[size];
    for (int i = 0; i < size; i++) {
        pTable[i] = other.pTable[i];
    }
    std::cout << "kopiujacy: " << s_name << std::endl;
}

CTable::~CTable() {
    std::cout << "usuwam: " << this->s_name << std::endl;
    delete[] this->pTable;
}

void CTable::setName(std::string newName) {
    this->s_name = newName;
}

bool CTable::setNewSize(int newSize) {
    if (newSize > 0) {
        int* newTable = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            newTable[i] = this->pTable[i];
        }
        delete[] this->pTable;
        this->pTable = newTable;
        this->size = newSize;
        return true;
    }
    return false;
}
CTable* CTable::pcClone() {
    return new CTable(*this);
}
int* CTable::getpTable(){
    return this->pTable;
}
int CTable::getSize(){
    return this->size;
}
void CTable::setpTable(int* newTable){
    this->pTable = newTable;
}
void CTable::setSize(int newSize){
    this->size = newSize;
}


void v_mod_tab(CTable* pcTable, int newSize){
    if(newSize > 0){
        pcTable->setNewSize(newSize);
    }
}

void v_mod_tab(CTable cTable, int newSize){
    if(newSize > 0){
        cTable.setNewSize(newSize);
    }
}