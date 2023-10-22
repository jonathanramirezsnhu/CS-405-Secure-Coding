// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
/*
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}
*/
// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0

    add_entries(1);

    // is the collection still empty?
    // if not empty, what must the size be?
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeIsGreaterOrEqualToSize)
{
    //Data for testing
    add_entries(20);
    //For 0
    ASSERT_TRUE(collection->max_size() >= 0);
    //For 1
    ASSERT_TRUE(collection->max_size() >= 1);
    //For 5
    ASSERT_TRUE(collection->max_size() >= 5);
    //For 10
    ASSERT_TRUE(collection->max_size() >= 10);
}
// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityIsGreaterOrEqualToSize)
{
    //Data for testing
    add_entries(15);
    //For 0
    ASSERT_TRUE(collection->capacity() >= 0);
    //For 1
    ASSERT_TRUE(collection->capacity() >= 1);
    //For 5
    ASSERT_TRUE(collection->capacity() >= 5);
    //For 10
    ASSERT_TRUE(collection->capacity() >= 10);
}
// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, DoesResizingIncreaseCollection)
{
    //the original size
    add_entries(20);
    int originalSize = collection->size();
    //resizing colletion from 2 to 30
    collection->resize(30);

    ASSERT_TRUE(collection->size() > originalSize);
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, DoesResizingDecreaseCollection)
{
    //the original size
    add_entries(20);
    int originalSize = collection->size();
    //resizing collection from 20 to 2
    collection->resize(2);

    ASSERT_TRUE(collection->size() < originalSize);
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, DoesResizingDecreaseCollectionToZero)
{
    //the original size
    add_entries(20);
    int originalSize = collection->size();
    int zeroVal = 0;
    //resizing collection from 20 to 0
    collection->resize(0);

    ASSERT_TRUE(collection->size() == zeroVal);
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, DoesClearErasesCollection)
{
    //original size
    add_entries(20);
    int originalSize = collection->size();

    //clear the collection
    collection->clear();
    //ASSERT_TRUE(collection->size() == 0);
    ASSERT_TRUE(collection->size() == NULL);

}
// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, DoesEraseActuallyErasesCollectionAtCustomRange)
{
    //original size
    add_entries(20);
    collection->erase(collection->begin() + 9, collection->end());
    //Verifies entries from 10 to 20 are removed
    ASSERT_TRUE(collection->size() < 10);
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, DoesReserveIncreasesCapacityButNotCollectionSize)
{
    //original size
    add_entries(20);
    int capacity = 30;
    int size = collection->size();
    //adds 10 empty containers
    collection->reserve(30);
    ASSERT_TRUE(collection->size() == size);
    //checks to see if original capacity(20) is greater 
    ASSERT_TRUE(collection->capacity() > 20);
}
// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, IsOutOfRangeThrownWhenCallingAtWithOutOfBoundsIndex)
{
    //original size
    add_entries(10);
    std::vector <int> myVector;
    for (int i = 0; i < collection->size(); i++) {
        myVector.push_back(i);
    }
    EXPECT_THROW(myVector.at(14), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
//Positive Test
TEST_F(CollectionTest, DoesCollectionHaveMorethanFiveNumbersDivisiblebyTwo)
{
    //original size
    add_entries(20);
    std::vector<int> newCollection;

    for (int i = 0; i < collection->size(); ++i) {
        if ((i % 2) == 0) {
            newCollection.push_back(i);
        }
    }
    
    ASSERT_TRUE(newCollection.size() > 5);

}

//Negative Test
TEST_F(CollectionTest, CollectionMustEqualSecondCollectionValues) 
{
    add_entries(5);
    std::vector<int> secondCollection;
    secondCollection.push_back(1);
    secondCollection.push_back(2);
    secondCollection.push_back(3);
    secondCollection.push_back(4);
    secondCollection.push_back(5);

    //is it not true that collection equals second collection?
    ASSERT_FALSE(collection->size() != secondCollection.size());
}