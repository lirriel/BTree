////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         30.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <assert.h>
#include <stdexcept>


//#include "int_stack.h"
//#include "stack_machine.h"

#include "btree.h"


using namespace std;
using namespace xi;



/** \brief Тестирует открытие дерева в новом файле (1). */
void stOpenFileBTree()
{
    using namespace xi;

    string fn = "f:\\temp\\20170526\\btrees\\st1.xibt";
    FileBaseBTree bt(2, 10, nullptr, fn);               // без компаратора!
    
}

struct ByteComparator : BaseBTree::IComparator {
    virtual bool compare(const Byte* lhv, const Byte* rhv, UInt sz) override
    {
        if (*lhv < *rhv)
            return true;
        return false;
    }

    // простейшая реализация — побайтное сравнение
    virtual bool isEqual(const Byte* lhv, const Byte* rhv, UInt sz) override
    {
        for (UInt i = 0; i < sz; ++i)
            if (*lhv != *rhv)
                return false;

        return true;
    }

};

void test16(){
    std::string fn = "Insert4.xibt";

    ByteComparator comparator;
    FileBaseBTree bt(2, 1, &comparator, fn);


//    Byte els[] = { 0x01, 0x11, 0x09, 0x05, 0x07, 0x03, 0x03 };
    Byte els[] = { 0x01, 0x11, 0x09, 0x05, 0x07, 0x03, 0x03, 0x12, 0x10, 0x03, 0x14, 0x28, 0x03, 0x16, 0x03, 0x03, 0x03, 0x04, 0x01 };
    for (int i = 0; i < sizeof(els) / sizeof(els[0]); ++i)
    {
        Byte& el = els[i];
        bt.insert(&el);
    }

    Byte& el = els[1];
    std::list<Byte*> keys;
    el = 0x17;
    int i = bt.searchAll(&el, keys);
    cout << i <<  endl;
}



int main()
{
//    stOpenFileBTree();
    test16();
    cout << "Hello, World!" << endl;
    return 0;
}