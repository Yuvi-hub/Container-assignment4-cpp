#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <iostream>
#include <sstream>

using namespace ContainerNs;


TEST_CASE("Testing MyContainer's add(), size(), remove(), getElements()")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(15);

    CHECK(container.size()==4);

    std::vector<int> vect;
    
    vect = container.getElements();

    CHECK(vect[0]==7);
    CHECK(vect[1]==15);
    CHECK(vect[2]==6);
    CHECK(vect[3]==15);

    container.remove(15);

    vect = container.getElements();
    CHECK(vect[0]==7);
    CHECK(vect[2]==6);

    CHECK_NOTHROW(container.remove(6));
    
    CHECK_THROWS(container.remove(15));
}

TEST_CASE("Testing MyContainer's << operator")
{
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);

    std::ostringstream oss;
    oss << container;

    CHECK(oss.str() == "[ 7 15 6 ]\n");
}


TEST_CASE("Testing operator ++ of AscendingOrder") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(10);

    auto it = container.begin_ascending_order();
    
    // Checking the elements in ascending order

    CHECK(*it == 1); 

    ++it;
    CHECK(*it == 5); 

    ++it;
    CHECK(*it == 10);
}

TEST_CASE("Testing operator [] of AscendingOrder") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(10);

    auto it = container.begin_ascending_order();
    
    // Checking the elements in ascending order

    CHECK(it[0] == 1); 

    CHECK(it[1] == 5); 

    CHECK(it[2] == 10);
}

TEST_CASE("Testing operator == and operator != of AscendingOrder") {
    
    MyContainer<int> container;
    container.addElement(4);
    container.addElement(1);
    container.addElement(9);

    auto it1 = container.begin_ascending_order();
    auto it2 = container.begin_ascending_order();
    
    CHECK(it1 == it2);

    CHECK(!(it1 != it2));
    
    CHECK(!(it1[1] == *it2));

    CHECK(it1[1] != *it2);

    auto itEnd = container.end_ascending_order();
    while (it1 != itEnd) {
        ++it1;
    }
    CHECK(it1 == itEnd);  
    CHECK(!(it1 != itEnd));  
}

TEST_CASE("Testing operator ++ of DescendingOrder") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(10);

    auto it = container.begin_descending_order();
    
    // Checking the elements in descending order

    CHECK(*it == 10); 

    ++it;
    CHECK(*it == 5); 

    ++it;
    CHECK(*it == 1);
}

TEST_CASE("Testing operator [] of DescendingOrder") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(10);

    auto it = container.begin_descending_order();
    
    // Checking the elements in descending order

    CHECK(it[0] == 10); 

    CHECK(it[1] == 5); 

    CHECK(it[2] == 1);
}

TEST_CASE("Testing operator == and operator != of DescendingOrder") {
    
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(9);

    auto it1 = container.begin_descending_order();
    auto it2 = container.begin_descending_order();
    
    CHECK(it1 == it2);

    CHECK(!(it1 != it2));
    
    CHECK(!(it1[1] == *it2));

    CHECK(it1[1] != *it2);

    auto itEnd = container.end_descending_order();
    while (it1 != itEnd) {
        ++it1;
    }
    CHECK(it1 == itEnd);  
    CHECK(!(it1 != itEnd));  
}

TEST_CASE("Testing operator ++ of SideCrossOrder") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    auto it = container.begin_side_cross_order();
    
    // Checking the elements in SideCrossOrder

    CHECK(*it == 1); 

    ++it;
    CHECK(*it == 15); 

    ++it;
    CHECK(*it == 2);

    ++it;
    CHECK(*it == 7);

    ++it;
    CHECK(*it == 6);
}

TEST_CASE("Testing operator [] of SideCrossOrder") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    auto it = container.begin_side_cross_order();
    
    // Checking the elements in SideCrossOrder order

    CHECK(it[0] == 1); 

    CHECK(it[1] == 15); 

    CHECK(it[2] == 2);

    CHECK(it[3] == 7);

    CHECK(it[4] == 6);
}

TEST_CASE("Testing operator == and operator != of SideCrossOrder") {
    
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    auto it1 = container.begin_side_cross_order();
    auto it2 = container.begin_side_cross_order();
    
    CHECK(it1 == it2);

    CHECK(!(it1 != it2));
    
    CHECK(!(it1[1] == *it2));

    CHECK(it1[1] != *it2);

    auto itEnd = container.end_side_cross_order();
    while (it1 != itEnd) {
        ++it1;
    }
    CHECK(it1 == itEnd);  
    CHECK(!(it1 != itEnd));  
}

TEST_CASE("Testing operator ++ of ReverseOrder") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(10);

    auto it = container.begin_reverse_order();
    
    // Checking the elements in reverse order

    CHECK(*it == 10); 

    ++it;
    CHECK(*it == 1); 

    ++it;
    CHECK(*it == 5);
}

TEST_CASE("Testing operator [] of ReverseOrder") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(10);

    auto it = container.begin_reverse_order();
    
    // Checking the elements in reverse order

    CHECK(it[0] == 10); 

    CHECK(it[1] == 1); 

    CHECK(it[2] == 5);
}

TEST_CASE("Testing operator == and operator != of ReverseOrder") {
    
    MyContainer<int> container;
    container.addElement(4);
    container.addElement(1);
    container.addElement(9);

    auto it1 = container.begin_reverse_order();
    auto it2 = container.begin_reverse_order();
    
    CHECK(it1 == it2);

    CHECK(!(it1 != it2));
    
    CHECK(!(it1[1] == *it2));

    CHECK(it1[1] != *it2);

    auto itEnd = container.end_reverse_order();
    while (it1 != itEnd) {
        ++it1;
    }
    CHECK(it1 == itEnd);  
    CHECK(!(it1 != itEnd));  
}

TEST_CASE("Testing operator ++ of Order") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);

    auto it = container.begin_order();
    
    // Checking the elements in original order

    CHECK(*it == 7); 

    ++it;
    CHECK(*it == 15); 

    ++it;
    CHECK(*it == 6);
}

TEST_CASE("Testing operator [] of Order") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);

    auto it = container.begin_order();
    
    // Checking the elements in original order

    CHECK(it[0] == 7); 

    CHECK(it[1] == 15); 

    CHECK(it[2] == 6);
}

TEST_CASE("Testing operator == and operator != of Order") {
    
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);

    auto it1 = container.begin_order();
    auto it2 = container.begin_order();
    
    CHECK(it1 == it2);

    CHECK(!(it1 != it2));
    
    CHECK(!(it1[1] == *it2));

    CHECK(it1[1] != *it2);

    auto itEnd = container.end_order();
    while (it1 != itEnd) {
        ++it1;
    }
    CHECK(it1 == itEnd);  
    CHECK(!(it1 != itEnd));  
}

TEST_CASE("Testing operator ++ of MiddleOutOrder") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    auto it = container.begin_middle_out_order();
    
    // Checking the elements in middle-out order

    CHECK(*it == 6); 

    ++it;
    CHECK(*it == 15); 

    ++it;
    CHECK(*it == 1);

    ++it;
    CHECK(*it == 7);

    ++it;
    CHECK(*it == 2);

    // Teting for even number of items in the container

    MyContainer<int> container2;
    container2.addElement(7);
    container2.addElement(15);
    container2.addElement(6);
    container2.addElement(1);

    auto it2 = container.begin_middle_out_order();
    
    // Checking the elements in middle-out order

    CHECK(*it2 == 6); 

    ++it2;
    CHECK(*it2 == 15); 

    ++it2;
    CHECK(*it2 == 1);

    ++it2;
    CHECK(*it2 == 7);
}

TEST_CASE("Testing operator [] of MiddleOutOrder") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    auto it = container.begin_middle_out_order();
    
    // Checking the elements in middle-out order

    CHECK(it[0] == 6); 

    CHECK(it[1] == 15); 

    CHECK(it[2] == 1);

    CHECK(it[3] == 7);

    CHECK(it[4] == 2);


    // Testing the iterator for even number of elements in the container


    MyContainer<int> container2;
    container2.addElement(7);
    container2.addElement(15);
    container2.addElement(6);
    container2.addElement(1);

    auto it2 = container2.begin_middle_out_order();
    
    // Checking the elements in middle-out order

    CHECK(it2[0] == 6); 

    CHECK(it2[1] == 15); 

    CHECK(it2[2] == 1);

    CHECK(it2[3] == 7);

}

TEST_CASE("Testing operator == and operator != of MiddleOutOrder") {
    
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    auto it1 = container.begin_ascending_order();
    auto it2 = container.begin_ascending_order();
    
    CHECK(it1 == it2);

    CHECK(!(it1 != it2));
    
    CHECK(!(it1[1] == *it2));

    CHECK(it1[1] != *it2);

    auto itEnd = container.end_ascending_order();
    while (it1 != itEnd) {
        ++it1;
    }
    CHECK(it1 == itEnd);  
    CHECK(!(it1 != itEnd));  

    
    // Testing the iterator for even number of elements in the container

    MyContainer<int> container2;
    container2.addElement(7);
    container2.addElement(15);
    container2.addElement(6);
    container2.addElement(1);
    container2.addElement(2);

    auto itB1 = container2.begin_ascending_order();
    auto itB2 = container2.begin_ascending_order();
    
    CHECK(itB1 == itB2);

    CHECK(!(itB1 != itB2));
    
    CHECK(!(itB1[1] == *itB2));

    CHECK(itB1[1] != *itB2);

    auto itEnd2 = container.end_ascending_order();
    while (itB1 != itEnd2) {
        ++itB1;
    }
    CHECK(itB1 == itEnd2);  
    CHECK(!(itB1 != itEnd2));  


}
