from typing import Any, List, TypeVar
from typing_extensions import override
from .mylist import MyList

T = TypeVar("T")

class MyArrayList(MyList[T]):
    """An array list data structure."""

    DEFAULT_CAPACITY = 10
    MIN_ARR_LENGTH_THRESHOLD = 100

    def __init__(self, initialCapacity: int = 10) -> None:
        """Constructs an array list instance with a specified initial capacity.

        Args:
            initialCapacity (int): initial capacity of this array list

        Raises:
            ValueError: if initialCapacity is negative
        """
        if initialCapacity < 0:
            raise ValueError("Negative capacity provided.")
        self._array = [T] * initialCapacity
        self._array_size = 0

    def add(self, index: int, element: T) -> None:
        pass

    def add(self, element: T) -> None:
        pass

    def clear(self) -> None:
        pass

    def contains(self, element: T) -> bool:
        return False

    @override
    def __delitem__(self, index: int) -> None:
        """Retrieves and removes an element from this list at a specified index.

        Args:
            index (int): index to remove element from
        """
        self.remove(index)

    def equals(self, object: Any) -> bool:
        return False

    @override
    def __eq__(self, object: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            object (Any): object to compare to this array list

        Returns:
            bool: result from `equals`
        """
        return self.equals(object)

    def get(self, index: int) -> T:
        return None

    @override
    def __getitem__(self, index: int) -> T:
        """Retrieves, but does not remove, an element from this list at the specified index.

        Args:
            index (int): index to retrieve element from

        Returns:
            element found
        """
        self.get(index)

    def indexOf(self, element: T) -> int:
        return 0

    @override
    def insert(self, index: int, element: T) -> None:
        """Inserts an element at the specified index.

        Args:
            index (int): index to add element
            element: element to add
        """
        self.add(index, element)

    def isEmpty(self) -> bool:
        return False

    def lastIndexOf(self, element: T) -> int:
        return 0

    @override
    def __len__(self) -> int:
        """Returns the number of elements in this list.

        Returns:
            int: size of list
        """
        return self._array_size

    def remove(self, index: int) -> T:
        return None

    def removeElement(self, element: T) -> bool:
        return False

    def set(self, index: int, element: T) -> T:
        return None

    @override
    def __setitem__(self, index: int, element: T) -> None:
        """Inserts an element at the specified index.

        Args:
            index (int): index to add element
            element: element to add
        """
        self.add(index, element)

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
