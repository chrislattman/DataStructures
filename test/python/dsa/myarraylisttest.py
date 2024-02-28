import sys
import unittest
from unittest.mock import Mock #, patch

sys.path.append("src/python")
from dsa.myarraylist import MyArrayList


class MyArrayListTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        return super().setUpClass()

    def setUp(self) -> None:
        self.myArrayList = MyArrayList[int]()
        self.myArrayList.clear()

    def test_constructor(self):
        self.assertRaises(ValueError, lambda: MyArrayList[int](-1))

    def test_add(self):
        self.myArrayList.add(5)
        self.assertEqual(0, self.myArrayList.size())

    def test_contains(self):
        self.myArrayList.add(5)
        self.assertFalse(self.myArrayList.contains(5))

    def test_equals(self):
        self.assertFalse(self.myArrayList.equals(self.myArrayList))

    def test_get(self):
        self.assertRaises(IndexError, lambda: self.myArrayList.get(0))

    def test_indexOf(self):
        self.assertEqual(-1, self.myArrayList.indexOf(5))

    def test_isEmpty(self):
        self.assertTrue(self.myArrayList.isEmpty())

    def test_lastIndexOf(self):
        self.assertEqual(-1, self.myArrayList.lastIndexOf(5))

    def test_removeAtIndex(self):
        self.assertRaises(IndexError, lambda: self.myArrayList.removeAtIndex(0))

    def test_removeElement(self):
        self.assertFalse(self.myArrayList.removeElement(5))

    def test_set(self):
        self.assertRaises(IndexError, lambda: self.myArrayList.set(1, 5))

    def test_size(self):
        self.assertEqual(0, self.myArrayList.size())

    def test_toString(self):
        self.assertEqual("[]", self.myArrayList.toString())

    def test_mock(self):
        # with patch("dsa.myarraylist.MyArrayList") as mock:
        #     mockList = mock.return_value
        #     mockList.size.return_value = 10
        #     self.assertEqual(10, mockList.size())
        mockList = Mock(spec=MyArrayList)
        mockList.size.return_value = 10
        self.assertEqual(10, mockList.size())

        spyList = Mock(wraps=self.myArrayList)
        def my_side_effect(value: int) -> bool:
            if value == 3:
                return True
            return False
        spyList.contains.side_effect = my_side_effect
        self.assertTrue(spyList.contains(3))
        self.assertFalse(spyList.contains(4))
        self.assertEqual(0, spyList.size())

    def tearDown(self) -> None:
        return super().tearDown()

    @classmethod
    def tearDownClass(cls) -> None:
        return super().tearDownClass()


if __name__ == "__main__":
    unittest.main()
