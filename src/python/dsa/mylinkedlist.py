from typing import Any, List, TypeVar
from typing_extensions import override
from .mylist import MyList

T = TypeVar("T")

class MyLinkedList(MyList[T]):
    """A singly linked list data structure."""

    def __init__(self) -> None:
        """Default constructor for this linked list."""
        self.clear()

    def add(self, index: int, element: T) -> None:
        pass

    def add(self, element: T) -> None:
        pass

    def clear(self) -> None:
        self._head = self.Node()
        self._size = 0

    def contains(self, element: T) -> bool:
        return False

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

    def indexOf(self, element: T) -> int:
        return 0

    def isEmpty(self) -> bool:
        return False

    def lastIndexOf(self, element: T) -> int:
        return 0

    def remove(self, index: int) -> T:
        return None

    def removeElement(self, element: T) -> bool:
        return False

    def set(self, index: int, element: T) -> T:
        return None

    def size(self) -> int:
        return 0

    def toArray(self) -> List[T]:
        return list()

    def toString(self) -> str:
        return ""

    @override
    def __str__(self) -> str:
        """Overrides the `__str__` method in the `object` class. Calls `toString`.

        Returns:
            str: result from `toString`
        """
        return self.toString()

    class Node:
        def __init__(self, data: T = None):
            self.data = data
            self.next: MyLinkedList.Node = None
