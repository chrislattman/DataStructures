from typing import Any, List, TypeVar
from typing_extensions import override
from .myqueue import MyQueue

T = TypeVar("T")

class MyPriorityQueue(MyQueue[T]):
    """A priority queue data structure. Also called a (binary) heap."""

    DEFAULT_CAPACITY = 11
    MIN_ARR_LENGTH_THRESHOLD = 100

    def __init__(self, initialCapacity: int = None, isMinHeap: bool = True) -> None:
        """Constructs either a min heap or a max heap with a specified initial capacity.

        Args:
            initialCapacity (int, optional): initial capacity of this priority queue. Defaults to 11.
            isMinHeap (bool, optional): if True, this priority queue will be a min heap; otherwise, it will be a max heap

        Raises:
            ValueError: if initialCapacity is negative
        """
        if not initialCapacity:
            initialCapacity = self.DEFAULT_CAPACITY
        elif initialCapacity < 0:
            raise ValueError("Negative capacity provided.")
        self._array = [T] * initialCapacity
        self._array_size = 0
        self._isMinHeap = isMinHeap

    def clear(self) -> None:
        pass

    def equals(self, object: Any) -> bool:
        return False

    @override
    def __eq__(self, object: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            object (Any): object to compare to this priority queue

        Returns:
            bool: result from `equals`
        """
        return self.equals(object)

    def isEmpty(self) -> bool:
        return False

    def __len__(self) -> int:
        """Returns the number of elements in this priority queue.

        Returns:
            int: size of priority queue
        """
        return self.size()

    def offer(self, element: T) -> None:
        pass

    def peek(self) -> T:
        return None

    def poll(self) -> T:
        return None

    def size(self) -> int:
        return 0

    def toArray(self) -> List[T]:
        return None

    def toString(self) -> str:
        return ""

    @override
    def __str__(self) -> str:
        """Overrides the `__str__` method in the `object` class. Calls `toString`.

        Returns:
            str: result from `toString`
        """
        return self.toString()

    def _checkCapacity(self) -> None:
        """Doubles or halves the size of the internal array depending on size. Used in offer and poll methods."""
        pass

    def _getBestIndex(self, leftIndex: int) -> int:
        """Returns the index of the lesser element of the internal array if this is a min heap.

        Otherwise, returns the index of the greater element. Indices should be distinct and increasing.

        Args:
            leftIndex (int): left array index

        Returns:
            int: the index of the desired element, or -1 if: leftIndex is out of bounds, _array[leftIndex] and
            _array[leftIndex + 1] are both None, or _array[-1] is None; in a non-None tie, left element wins
        """
        return -1
