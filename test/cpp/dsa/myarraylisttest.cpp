#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <myarraylist.hpp>
#include <mylist.h>

class MyArrayListTest: public ::testing::Test {
protected:
    MyArrayList<int> myarraylist;

    static void SetUpTestSuite() {

    }

    void SetUp() override {
        myarraylist.clear();
    }

    void TearDown() override {

    }

    static void TearDownTestSuite() {

    }
};

class MockMyList: public MyList<int> {
public:
    MOCK_METHOD(void, add, (unsigned int index, const int &element), (override));
    MOCK_METHOD(void, add, (const int &element), (override));
    MOCK_METHOD(void, clear, (), (override));
    MOCK_METHOD(bool, contains, (const int &element), (const, override));
    MOCK_METHOD(int, get, (unsigned int index), (const, override));
    MOCK_METHOD(long, indexOf, (const int &element), (const, override));
    MOCK_METHOD(bool, isEmpty, (), (const, override));
    MOCK_METHOD(long, lastIndexOf, (const int &element), (const, override));
    MOCK_METHOD(int, remove, (unsigned int index), (override));
    MOCK_METHOD(bool, removeElement, (const int &element), (override));
    MOCK_METHOD(int, set, (unsigned int index, const int &element), (override));
    MOCK_METHOD(unsigned int, size, (), (const, override));
    MOCK_METHOD(int *, toArray, (), (const, override));
    MOCK_METHOD(std::string, toString, (), (const, override));
};

TEST_F(MyArrayListTest, TestAdd) {
    myarraylist.add(5);
    EXPECT_EQ((unsigned int)1, myarraylist.size());
}

TEST_F(MyArrayListTest, TestContains) {
    myarraylist.add(5);
    EXPECT_TRUE(myarraylist.contains(5));
    EXPECT_FALSE(myarraylist.contains(6));
}

TEST_F(MyArrayListTest, TestEquals) {
    EXPECT_TRUE(myarraylist == myarraylist);
    MyArrayList<int> myarraylist2;
    myarraylist2.add(7);
    EXPECT_FALSE(myarraylist == myarraylist2);
    myarraylist.add(7);
    EXPECT_TRUE(myarraylist == myarraylist2);
}

TEST_F(MyArrayListTest, TestGet) {
    EXPECT_THROW(myarraylist.get(0), std::out_of_range);
    myarraylist.add(5);
    EXPECT_EQ(5, myarraylist.get(0));
}

TEST_F(MyArrayListTest, TestIndexOf) {
    EXPECT_EQ(-1, myarraylist.indexOf(5));
    myarraylist.add(5);
    EXPECT_EQ(0, myarraylist.indexOf(5));
}

TEST_F(MyArrayListTest, TestIsEmpty) {
    EXPECT_TRUE(myarraylist.isEmpty());
}

TEST_F(MyArrayListTest, TestLastIndexOf) {
    EXPECT_EQ(-1, myarraylist.lastIndexOf(5));
    myarraylist.add(5);
    EXPECT_EQ(0, myarraylist.lastIndexOf(5));
}

TEST_F(MyArrayListTest, TestRemove) {
    EXPECT_THROW(myarraylist.remove(0), std::out_of_range);
    myarraylist.add(5);
    EXPECT_EQ(5, myarraylist.remove(0));
    EXPECT_TRUE(myarraylist.isEmpty());
}

TEST_F(MyArrayListTest, TestRemoveElement) {
    EXPECT_FALSE(myarraylist.removeElement(5));
    myarraylist.add(5);
    EXPECT_TRUE(myarraylist.removeElement(5));
    EXPECT_TRUE(myarraylist.isEmpty());
}

TEST_F(MyArrayListTest, TestSet) {
    EXPECT_THROW(myarraylist.set(1, 5), std::out_of_range);
    myarraylist.add(5);
    EXPECT_EQ(5, myarraylist.set(0, 6));
    EXPECT_EQ(6, myarraylist.get(0));
}

TEST_F(MyArrayListTest, TestSize) {
    EXPECT_EQ((unsigned int)0, myarraylist.size());
}

TEST_F(MyArrayListTest, TestToString) {
    // use EXPECT_STREQ for C-style strings
    EXPECT_EQ("[]", myarraylist.toString());
    myarraylist.add(5);
    EXPECT_EQ("[5]", myarraylist.toString());
    myarraylist.add(6);
    EXPECT_EQ("[5, 6]", myarraylist.toString());
}

TEST_F(MyArrayListTest, TestMock) {
    MockMyList mocklist;
    EXPECT_CALL(mocklist, size()).WillRepeatedly(testing::Return(10));
    EXPECT_EQ((unsigned int)10, mocklist.size());

    ON_CALL(mocklist, contains(testing::_)).WillByDefault(testing::Return(false));
    EXPECT_CALL(mocklist, contains(::testing::_)).Times(::testing::AnyNumber());
    EXPECT_CALL(mocklist, contains(3)).Times(1).WillOnce(testing::Return(true));
    EXPECT_TRUE(mocklist.contains(3));
    EXPECT_FALSE(mocklist.contains(4));
    // No spying/wrapping mocks in gmock currently without manually adding
    // ON_CALL()s in MockMyList constructor
}
