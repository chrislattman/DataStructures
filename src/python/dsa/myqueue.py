from abc import ABC, abstractmethod
from typing import Any, Generic, List, Optional, Sized, TypeVar

T = TypeVar("T")


class MyQueue(ABC, Sized, Generic[T]):
    """Abstract base class (used as an interface) which defines methods for lists.

    Any subclass also needs to override `__len__` as part of inheriting from `Sized`.
    """

    @abstractmethod
    def clear(self) -> None:
        """Empties this queue of all elements."""

    @abstractmethod
    def equals(self, object: Any) -> bool:
        """Compares an object with this queue for equality.

        Args:
            object (Any): object to compare to this queue

        Returns:
            bool: True if object and this queue are equal
        """

    @abstractmethod
    def isEmpty(self) -> bool:
        """Checks if this queue has no elements.

        Returns:
            bool: True if this queue is empty, False otherwise
        """

    @abstractmethod
    def offer(self, element: T) -> None:
        """Inserts an element to this queue. None elements are not permitted.

        Args:
            element: element to add
        """

    @abstractmethod
    def peek(self) -> Optional[T]:
        """Retrieves, but does not remove, the element at the front of this queue.

        Returns:
            element at the front of this queue, or None if queue is empty
        """

    @abstractmethod
    def poll(self) -> Optional[T]:
        """Retrieves and removes the element at the front of this queue.

        Returns:
            element at the front of this queue, or None if queue is empty
        """

    @abstractmethod
    def size(self) -> int:
        """Returns the number of elements in this queue.

        Returns:
            int: size of queue
        """

    @abstractmethod
    def toArray(self) -> List[T]:
        """Returns an array containing all the elements in this queue.

        Returns:
            List: array of queue elements
        """

    @abstractmethod
    def toString(self) -> str:
        """Returns a string representation of this queue, e.g. "[element1, element2, element3, ..., elementN]".

        Returns:
            str: string form of this queue
        """
