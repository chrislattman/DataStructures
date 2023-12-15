from abc import ABC, abstractmethod
from typing import Any, Generic, List, TypeVar

T = TypeVar("T")

class MyList(ABC, Generic[T]):
    """Abstract base class (used as an interface) which defines methods for lists."""

    @classmethod
    def __subclasshook__(cls, __subclass: type) -> bool:
        """Ensures that any subclass of this class overrides all abstract methods."""
        methods_list = [func for func in dir(MyList) if not func.startswith("__")]
        callable_methods = [hasattr(__subclass, func) and callable(getattr(__subclass, func)) for func in methods_list]
        return all(callable_methods) or NotImplemented

    @abstractmethod
    def add(self, index: int, element: T) -> None:
        """Inserts an element at the specified index.

        Args:
            index (int): index to add element
            element: element to add

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size(), inclusive)
        """

    @abstractmethod
    def add(self, element: T) -> None:
        """Inserts an element at the end of this list.

        Args:
            element: element to add
        """

    @abstractmethod
    def clear(self) -> None:
        """Empties this list of all elements."""

    @abstractmethod
    def contains(self, element: T) -> bool:
        """Checks if an element is in this list.

        Args:
            element: element to check for

        Returns:
            bool: True if found, False otherwise
        """

    @abstractmethod
    def equals(self, object: Any) -> bool:
        """Compares an object with this list for equality.

        Args:
            object (Any): object to compare to this list

        Returns:
            bool: True if object and this list are equal
        """

    @abstractmethod
    def get(self, index: int) -> T:
        """Retrieves, but does not remove, an element from this list at the specified index.

        Args:
            index (int): index to retrieve element from

        Returns:
            T: element found

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size() - 1, inclusive)
        """

    @abstractmethod
    def indexOf(self, element: T) -> int:
        """Returns the index of the first occurrence of an element found in this list.

        Args:
            element: element to search for

        Returns:
            int: index of the first occurrence of element, or -1 if not found
        """

    @abstractmethod
    def isEmpty(self) -> bool:
        """Checks if this list has no elements.

        Returns:
            bool: True if this list is empty, False otherwise
        """

    @abstractmethod
    def lastIndexOf(self, element: T) -> int:
        """Returns the index of the last occurrence of an element found in this list.

        Args:
            element: element to search for

        Returns:
            int: index of the last occurrence of element, or -1 if not found
        """

    @abstractmethod
    def remove(self, index: int) -> T:
        """Retrieves and removes an element from this list at a specified index.

        Args:
            index (int): index to remove element from

        Returns:
            T: element found at index

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size() - 1, inclusive)
        """

    @abstractmethod
    def removeElement(self, element: T) -> bool:
        """Retrieves and removes the first occurrence of an element from this list.

        Args:
            element: element to remove first occurrence of

        Returns:
            bool: True if successful, False otherwise
        """

    @abstractmethod
    def set(self, index: int, element: T) -> T:
        """Sets the existing element at a specified index to a new value.

        Args:
            index (int): index to set element at
            element: new value to set existing element to

        Returns:
            T: old value of the element at position index

        Raises:
            IndexError: if index is out of bounds (index must be between 0 and size() - 1, inclusive)
        """

    @abstractmethod
    def size(self) -> int:
        """Returns the number of elements in this list.

        Returns:
            int: size of list
        """

    @abstractmethod
    def toArray(self) -> List[T]:
        """Returns an array containing all the elements in this list.

        Returns:
            List[T]: array of list elements
        """

    @abstractmethod
    def toString(self) -> str:
        """Returns a string representation of this list, e.g. "[element1, element2, element3, ..., elementN]".

        Returns:
            str: string form of this list
        """
