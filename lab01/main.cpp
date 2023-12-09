#include <iostream>
#include "CTable.h"

void v_print_table(int* table, int iSize){
    if(iSize > 0 && table != nullptr){
        std::cout << "[ ";
        for (int i = 0; i < iSize; i++){
            std::cout << &table[i] << " ";
        }
        std::cout << "]";
    }
    std::cout << std::endl; 
}

void v_alloc_table_fill(int iSize){
    if(iSize > 0){
        int* table = new int [iSize];
        for(int i = 0; i < iSize; i++){
            *(table + i) = FILL_VALUE;
        }
        v_print_table(table, iSize);
        delete[] table;
    }
    std::cout << std::endl << std::endl;
}

bool b_alloc_table_2_dim(int*** piTable, int sizeX, int sizeY){
    if(sizeX > 0 && sizeY > 0){
        int** pointers_table = new int*[sizeX];
        for(int i = 0; i < sizeX; i++){
            pointers_table[i] = new int[sizeY];
        }
        *piTable = pointers_table;
        return true;
    }
    return false;
}

void v_print_table_2_dim(int*** piTable, int sizeX, int sizeY) {
    if (sizeX > 0 && sizeY > 0) {
        for (int y = 0; y < sizeY; y++) {
            for (int x = 0; x < sizeX; x++) {
                std::cout << (*piTable)[x][y] << " ";
            }
            std::cout << std::endl;
        }
    }
}

bool b_dealloc_2_dim(int*** piTable, int sizeX, int sizeY){
    if(sizeX > 0 && sizeY > 0){
        for(int i = 0; i < sizeX; i++){
            delete[] (*piTable)[i];
        }
        delete[] *piTable;
        *piTable = nullptr;
        return true;
    }
    return false;
}





int main(){
    v_alloc_table_fill(5);

    int** two_dimensional;
    if(b_alloc_table_2_dim(&two_dimensional, 4, 6)){
        two_dimensional[0][0] = 10;
        two_dimensional[3][5] = 777;
        two_dimensional[1][2] = 13;
        std::cout << std::endl;
        v_print_table_2_dim(&two_dimensional, 4, 6);
        if(b_dealloc_2_dim(&two_dimensional, 4, 6)){
            std::cout << "usunieto macierz";
        }
    }


    std::cout << std::endl;
    std::cout << std::endl;

    CTable tablica1;
    CTable tablica2(7, "tablica numer 2");
    CTable tablica3(tablica2);
    CTable* p_new_tab;
    p_new_tab = tablica1.pcClone();

    std::cout << std::endl;
    std::cout << "TABLICE PRZED ZMIANA ROZMIAROW";
    std::cout << std::endl;

    std::cout << "stan tablicy 1: " << std::endl;
    v_print_table(tablica1.getpTable(), tablica1.getSize());
    std::cout << "stan tablicy 2: " << std::endl;
    v_print_table(tablica2.getpTable(), tablica2.getSize());
    std::cout << "stan tablicy 3: " << std::endl;
    v_print_table(tablica3.getpTable(), tablica3.getSize());
    std::cout << "stan tablicy p_new_tab: " << std::endl;
    v_print_table((*p_new_tab).getpTable(), (*p_new_tab).getSize());


    std::cout << std::endl;
    std::cout << "TABLICE PO ZMIANIE ROZMIAROW";
    std::cout << std::endl;

    tablica1.setName("zmienilem nazwe");
    tablica1.setNewSize(3);
    tablica2.setNewSize(10);
    tablica3.setNewSize(-1);
    (*p_new_tab).setNewSize(20);

    std::cout << "stan tablicy 1: " << std::endl;
    v_print_table(tablica1.getpTable(), tablica1.getSize());
    std::cout << "stan tablicy 2: " << std::endl;
    v_print_table(tablica2.getpTable(), tablica2.getSize());
    std::cout << "stan tablicy 3: " << std::endl;
    v_print_table(tablica3.getpTable(), tablica3.getSize());
    std::cout << "stan tablicy p_new_tab: " << std::endl;
    v_print_table((*p_new_tab).getpTable(), (*p_new_tab).getSize());




    std::cout << std::endl;
    std::cout << "TEST PRZEKAZANIA PRZEZ WSKAZNIK I PRZEZ WARTOSC:";
    std::cout << std::endl;
    v_mod_tab(p_new_tab, 7);
    v_mod_tab(tablica1, 100);

    std::cout << "stan tablicy 1: " << std::endl;
    v_print_table(tablica1.getpTable(), tablica1.getSize());
    std::cout << "stan tablicy p_new_tab: " << std::endl;
    v_print_table((*p_new_tab).getpTable(), (*p_new_tab).getSize());


    std::cout << std::endl;
    std::cout << std::endl;


    CTable* tablicaobiektow = new CTable[5];
    delete[] tablicaobiektow;
    delete p_new_tab;
    return 0;
}