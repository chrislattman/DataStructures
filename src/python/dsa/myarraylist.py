from typing import Any, List, Optional, TypeVar

from typing_extensions import override

from .mylist import MyList

T = TypeVar("T")


class MyArrayList(MyList[T]):
    """An array list data structure."""

    DEFAULT_CAPACITY = 10
    MIN_ARR_LENGTH_THRESHOLD = 100

    def __init__(self, initialCapacity: Optional[int] = None) -> None:
        """Constructs an array list instance with a specified initial capacity.

        Args:
            initialCapacity (int): initial capacity of this array list. Defaults to 10.

        Raises:
            ValueError: if initialCapacity is negative
        """
        if initialCapacity is None:
            initialCapacity = self.DEFAULT_CAPACITY
        elif initialCapacity < 0:
            raise ValueError("Negative capacity provided")
        self._array = [None] * initialCapacity
        self._array_size = 0

    def add(self, element: T, index: Optional[int] = None) -> None:
        pass

    def clear(self) -> None:
        pass

    def contains(self, element: T) -> bool:
        return False

    def __delitem__(self, index: int) -> None:
        """Retrieves and removes an element from this array list at a specified index.

        Args:
            index (int): index to remove element from

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size() - 1, inclusive)
        """
        self.removeAtIndex(index)

    def equals(self, obj: Any) -> bool:
        return False

    @override
    def __eq__(self, obj: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            obj (Any): object to compare to this array list

        Returns:
            bool: result from `equals`
        """
        return self.equals(obj)

    def get(self, index: int) -> T:
        raise IndexError()

    def __getitem__(self, index: int) -> T:
        """Retrieves, but does not remove, an element from this array list at the specified index.

        Args:
            index (int): index to retrieve element from

        Returns:
            element found

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size() - 1, inclusive)
        """
        return self.get(index)

    def indexOf(self, element: T) -> int:
        return -1

    def insert(self, index: int, element: T) -> None:
        """Inserts an element at the specified index.

        Args:
            index (int): index to add element
            element: element to add

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size(), inclusive)
        """
        self.add(element, index)

    def isEmpty(self) -> bool:
        return True

    def lastIndexOf(self, element: T) -> int:
        return -1

    def __len__(self) -> int:
        """Returns the number of elements in this array list.

        Returns:
            int: size of array list
        """
        return self.size()

    def removeAtIndex(self, index: int) -> T:
        raise IndexError()

    def removeElement(self, element: T) -> bool:
        return False

    def set(self, index: int, element: T) -> T:
        raise IndexError()

    def __setitem__(self, index: int, element: T) -> None:
        """Inserts an element at the specified index.

        Args:
            index (int): index to add element
            element: element to add

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size(), inclusive)
        """
        self.add(element, index)

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
        """Doubles or halves the size of the internal array depending on size. Used in add and remove methods."""

    def _checkIndex(self, index: int, upperBound: int) -> None:
        """Helper function for index validation.

        Args:
            index (int): index to validate
            upperBound (int): value that index must be strictly less than

        Raises:
            IndexError: if index is out of bounds
        """
        if index < 0 or index >= upperBound:
            raise IndexError("index is out of bounds")
