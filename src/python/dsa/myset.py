from abc import ABC, abstractmethod
from typing import Any, List, MutableSet, TypeVar

T = TypeVar("T")

class MySet(ABC, MutableSet[T]):
    """Abstract base class (used as an interface) which defines methods for sets.

    Any subclass also needs to override `__contains__`, `__iter__`, `__len__`,
    `add`, and `discard`, as part of inheriting from `MutableSet`.
    """

    @abstractmethod
    def clear(self) -> None:
        """Empties this set of all elements."""

    @abstractmethod
    def contains(self, element: T) -> bool:
        """Checks if an element is in this set.

        Args:
            element: element to check for

        Returns:
            bool: True if found, False otherwise
        """

    @abstractmethod
    def equals(self, object: Any) -> bool:
        """Compares an object with this set for equality.

        Args:
            object (Any): object to compare to this set

        Returns:
            bool: True if object and this set are equal
        """

    @abstractmethod
    def isEmpty(self) -> bool:
        """Checks if this set has no elements.

        Returns:
            bool: True if this set is empty, False otherwise
        """

    @abstractmethod
    def remove(self, element: T) -> bool:
        """Removes an element from this set.

        Args:
            element: element to remove

        Returns:
            bool: True if element found, False otherwise
        """

    @abstractmethod
    def size(self) -> int:
        """Returns the number of elements in this set.

        Returns:
            int: size of set
        """

    @abstractmethod
    def toArray(self) -> List[T]:
        """Returns an array containing all the elements in this set.

        Returns:
            List: array of set elements
        """

    @abstractmethod
    def toString(self) -> str:
        """Returns a string representation of this set, e.g. "[element1, element2, element3, ..., elementN]".

        Returns:
            str: string form of this set
        """
