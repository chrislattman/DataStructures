import sys
import unittest

sys.path.append("src/python")
from dsa.myarrayqueue import MyArrayQueue


class MyArrayQueueTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        return super().setUpClass()

    def setUp(self) -> None:
        self.myArrayQueue = MyArrayQueue[int]()
        self.myArrayQueue.clear()

    def test_equals(self):
        self.assertFalse(self.myArrayQueue.equals(self.myArrayQueue))

    def test_isEmpty(self):
        self.assertTrue(self.myArrayQueue.isEmpty())

    def test_offer(self):
        self.myArrayQueue.offer(5)
        self.assertIsNone(self.myArrayQueue.peek())

    def test_peek(self):
        self.assertIsNone(self.myArrayQueue.peek())

    def test_poll(self):
        self.assertIsNone(self.myArrayQueue.poll())

    def test_size(self):
        self.assertEqual(0, self.myArrayQueue.size())

    def test_toString(self):
        self.assertEqual("[]", self.myArrayQueue.toString())

    def tearDown(self) -> None:
        return super().tearDown()

    @classmethod
    def tearDownClass(cls) -> None:
        return super().tearDownClass()


if __name__ == "__main__":
    unittest.main()
