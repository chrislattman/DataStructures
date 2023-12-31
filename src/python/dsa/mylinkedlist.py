from typing import Any, List, Optional, TypeVar

from typing_extensions import override

from .mylist import MyList

T = TypeVar("T")


class MyLinkedList(MyList[T]):
    """A singly linked list data structure."""

    def __init__(self) -> None:
        """Default constructor for this linked list."""
        self.clear()

    def add(self, element: T, index: Optional[int] = None) -> None:
        pass

    def clear(self) -> None:
        self._head = self.Node()
        self._size = 0

    def contains(self, element: T) -> bool:
        return False

    def __delitem__(self, index: int) -> None:
        """Retrieves and removes an element from this linked list at a specified index.

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
            obj (Any): object to compare to this linked list

        Returns:
            bool: result from `equals`
        """
        return self.equals(obj)

    def get(self, index: int) -> T:
        raise IndexError()

    def __getitem__(self, index: int) -> T:
        """Retrieves, but does not remove, an element from this linked list at the specified index.

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
        """Returns the number of elements in this linked list.

        Returns:
            int: size of linked list
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

    def _checkIndex(self, index: int, upperBound: int) -> None:
        """Helper function for index validation.

        Args:
            index (int): index to validate
            upperBound (int): value that index must be strictly less than

        Raises:
            IndexError: if index is out of bounds
        """

    class Node:
        def __init__(self) -> None:
            self.data: Optional[T] = None
            self.next: Optional[MyLinkedList.Node] = None
