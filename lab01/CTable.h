#ifndef LAB01_JEDREK_CTABLE_H
#define LAB01_JEDREK_CTABLE_H


#include <string>

const int FILL_VALUE = 34;

class CTable {

private:
    std::string s_name;
    int size;
    int* pTable;

public:
    CTable();
    CTable(int size, std::string s_name);
    CTable(CTable &other);
    ~CTable();
    void setName(std::string newName);
    bool setNewSize(int newSize);
    CTable* pcClone();
    int* getpTable();
    int getSize();
    void setpTable(int* newTable);
    void setSize(int newSize);
};

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);


#endif //LAB01_JEDREK_CTABLE_H