package dsa

import (
	"os"
	"testing"

	"go.uber.org/mock/gomock"
)

// Install mockgen with:
// go install go.uber.org/mock/mockgen@latest

// Preferably put beforeAll(), TestMain(), and afterAll() in separate test file

// beforeAll runs once before the unit tests begin.
func beforeAll() {
	var _ MyList[int] = (*MyArrayList[int])(nil)
	var _ MyList[int] = (*MyLinkedList[int])(nil)
}

// Entry function which starts unit test execution.
func TestMain(m *testing.M) {
	beforeAll()
	code := m.Run()
	afterAll()
	os.Exit(code)
}

func TestMyArrayList_Add(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	myArrayList.Clear()
	assertEquals(t, uint(0), myArrayList.Size())
	myArrayList.Add(0, 5)
	assertEquals(t, uint(1), myArrayList.Size())
	myArrayList.AddToEnd(6)
	assertEquals(t, uint(2), myArrayList.Size())
}

func TestMyArrayList_Contains(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	myArrayList.AddToEnd(5)
	assertTrue(t, myArrayList.Contains(5))
	assertFalse(t, myArrayList.Contains(6))
}

func TestMyArrayList_Equals(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	assertFalse(t, myArrayList.Equals(myArrayList))
}

func TestMyArrayList_Get(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	_, err := myArrayList.Get(0)
	assertNotNil(t, err)
	myArrayList.AddToEnd(5)
	res, _ := myArrayList.Get(0)
	assertEquals(t, 5, res)
}

func TestMyArrayList_IndexOf(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	assertEquals(t, -1, myArrayList.IndexOf(5))
	myArrayList.AddToEnd(5)
	assertEquals(t, 0, myArrayList.IndexOf(5))
}

func TestMyArrayList_IsEmpty(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	assertTrue(t, myArrayList.IsEmpty())
}

func TestMyArrayList_LastIndexOf(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	assertEquals(t, -1, myArrayList.LastIndexOf(5))
	myArrayList.AddToEnd(5)
	assertEquals(t, 0, myArrayList.LastIndexOf(5)) // failed
}

func TestMyArrayList_Remove(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	_, err := myArrayList.Remove(0)
	assertNotNil(t, err)
	myArrayList.AddToEnd(5)
	res, _ := myArrayList.Remove(0)
	assertEquals(t, 5, res)
	assertTrue(t, myArrayList.IsEmpty())
}

func TestMyArrayList_RemoveElement(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	assertFalse(t, myArrayList.RemoveElement(5))
	myArrayList.AddToEnd(5)
	assertTrue(t, myArrayList.RemoveElement(5))
	assertTrue(t, myArrayList.IsEmpty())
}

func TestMyArrayList_Set(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	_, err := myArrayList.Set(1, 5)
	assertNotNil(t, err)
	myArrayList.AddToEnd(5)
	res, _ := myArrayList.Set(0, 6)
	assertEquals(t, 5, res)
	res, _ = myArrayList.Get(0)
	assertEquals(t, 6, res)
}

func TestMyArrayList_Size(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	assertEquals(t, uint(0), myArrayList.Size())
}

func TestMyArrayList_ToString(t *testing.T) {
	myArrayList := NewArrayListDefault[int]()
	assertEquals(t, "[]", myArrayList.ToString())
	myArrayList.AddToEnd(5)
	assertEquals(t, "[5]", myArrayList.ToString())
	myArrayList.AddToEnd(6)
	assertEquals(t, "[5, 6]", myArrayList.ToString())
}

func TestMyArrayList_Mock(t *testing.T) {
	ctrl := gomock.NewController(t)
	defer ctrl.Finish()
	mockList := NewMockMyList[int](ctrl)
	mockList.EXPECT().Size().Return(uint(10))
	assertEquals(t, uint(10), mockList.Size())

	mockList.EXPECT().Contains(3).Return(true)
	mockList.EXPECT().Contains(gomock.Not(3)).Return(false)
	assertEquals(t, true, mockList.Contains(3))
	assertEquals(t, false, mockList.Contains(4))
	// No spying/wrapping mocks in GoMock currently
}

// afterAll runs once all unit tests have finished.
func afterAll() {
	// Cleanup goes here
}
