from typing import Any, List, Optional, TypeVar

from typing_extensions import override

from .myqueue import MyQueue

T = TypeVar("T")


class MyArrayQueue(MyQueue[T]):
    """An array queue data structure (FIFO)."""

    DEFAULT_CAPACITY = 16
    MIN_ARR_LENGTH_THRESHOLD = 100

    def __init__(self, initialCapacity: Optional[int] = None) -> None:
        """Constructs an array queue instance with a specified initial capacity.

        Args:
            initialCapacity (int): initial capacity of this array queue. Defaults to 16.

        Raises:
            ValueError: if initialCapacity is negative
        """
        if not initialCapacity:
            initialCapacity = self.DEFAULT_CAPACITY
        elif initialCapacity < 0:
            raise ValueError("Negative capacity provided")
        self._array = [None] * initialCapacity
        self._array_size = 0

    def clear(self) -> None:
        pass

    def equals(self, obj: Any) -> bool:
        return False

    @override
    def __eq__(self, obj: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            obj (Any): object to compare to this array queue

        Returns:
            bool: result from `equals`
        """
        return self.equals(obj)

    def isEmpty(self) -> bool:
        return True

    def __len__(self) -> int:
        """Returns the number of elements in this array queue.

        Returns:
            int: size of array queue
        """
        return self.size()

    def offer(self, element: T) -> None:
        pass

    def peek(self) -> Optional[T]:
        return None

    def poll(self) -> Optional[T]:
        return None

    def size(self) -> int:
        return 0

    def toArray(self) -> List[T]:
        return []

    def toString(self) -> str:
        return "[]"

    @override
    def __str__(self) -> str:
        """Overrides the `__str__` method in the `object` class. Calls `toString`.

        Returns:
            str: result from `toString`
        """
        return self.toString()

    def _checkCapacity(self) -> None:
        """Doubles or halves the size of the internal array depending on size. Used in offer and poll methods."""
