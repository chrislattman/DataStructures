package dsa

import (
	"os"
	"testing"
)

// beforeAll runs once before the unit tests begin.
func beforeAll() {

}

// Entry function which starts unit test execution.
func TestMain(m *testing.M) {
	beforeAll()
	code := m.Run()
	afterAll()
	os.Exit(code)
}

func TestAdd(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	myArrayList.Clear()
	myArrayList.Add(5, 0)
	myArrayList.AddToEnd(6)
	assertEquals(t, uint32(0), myArrayList.Size())
}

func TestContains(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	myArrayList.AddToEnd(5)
	assertFalse(t, myArrayList.Contains(5))
}

func TestEquals(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	assertFalse(t, myArrayList.Equals(myArrayList))
}

func TestGet(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	_, err := myArrayList.Get(0)
	assertNil(t, err)
}

func TestIndexOf(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	assertEquals(t, int64(-1), myArrayList.IndexOf(5))
}

func TestIsEmpty(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	assertTrue(t, myArrayList.IsEmpty())
}

func TestLastIndexOf(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	assertEquals(t, int64(-1), myArrayList.LastIndexOf(5))
}

func TestRemove(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	_, err := myArrayList.Remove(0)
	assertNil(t, err)
}

func TestRemoveElement(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	assertFalse(t, myArrayList.RemoveElement(5))
}

func TestSet(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	_, err := myArrayList.Set(1, 5)
	assertNil(t, err)
}

func TestSize(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	assertEquals(t, uint32(0), myArrayList.Size())
}

func TestToString(t *testing.T) {
	myArrayList := MyArrayList[int]{}
	assertEquals(t, "[]", myArrayList.ToString())
}

// afterAll runs once all unit tests have finished.
func afterAll() {

}
