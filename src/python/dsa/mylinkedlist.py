from typing import Any, List, TypeVar
from typing_extensions import override
from .mylist import MyList

T = TypeVar("T")

class MyLinkedList(MyList[T]):
    """A singly linked list data structure."""

    def __init__(self) -> None:
        """Default constructor for this linked list."""
        self.clear()

    def add(self, element: T, index: int = None) -> None:
        pass

    def clear(self) -> None:
        self._head = self.Node()
        self._size = 0

    def contains(self, element: T) -> bool:
        return False

    def __delitem__(self, index: int) -> None:
        """Retrieves and removes an element from this list at a specified index.

        Args:
            index (int): index to remove element from

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size() - 1, inclusive)
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

    def __getitem__(self, index: int) -> T:
        """Retrieves, but does not remove, an element from this list at the specified index.

        Args:
            index (int): index to retrieve element from

        Returns:
            element found

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size() - 1, inclusive)
        """
        self.get(index)

    def indexOf(self, element: T) -> int:
        return 0

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
        return False

    def lastIndexOf(self, element: T) -> int:
        return 0

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

    def _checkIndex(self, index: int, upperBound: int) -> None:
        """Helper function for index validation.

        Args:
            index (int): index to validate
            upperBound (int): value that index must be strictly less than

        Raises:
            IndexError: if index is out of bounds
        """
        pass

    class Node:
        def __init__(self, data: T = None) -> None:
            self.data = data
            self.next: MyLinkedList.Node = None
