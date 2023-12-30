import sys
import unittest

sys.path.append("../../../src/python")
from dsa.mylinkedlist import MyLinkedList


class MyLinkedListTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        return super().setUpClass()

    def setUp(self) -> None:
        self.myLinkedList = MyLinkedList[int]()

    def test(self):
        self.assertTrue(True, "not true")

    def tearDown(self) -> None:
        return super().tearDown()

    @classmethod
    def tearDownClass(cls) -> None:
        return super().tearDownClass()


if __name__ == "__main__":
    unittest.main()
