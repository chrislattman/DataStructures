from typing import Any, Generic, List, Optional, TypeVar

from typing_extensions import override

T = TypeVar("T")


class MyStack(Generic[T]):
    """A stack data structure (LIFO)."""

    DEFAULT_CAPACITY = 10
    MIN_ARR_LENGTH_THRESHOLD = 100

    def __init__(self) -> None:
        """Default constructor for this stack."""
        self.clear()

    def clear(self) -> None:
        """Empties this stack of all elements."""
        self._array = [None] * self.DEFAULT_CAPACITY
        self._array_size = 0

    def equals(self, obj: Any) -> bool:
        """Compares an object with this stack for equality.

        Args:
            obj (Any): object to compare to this stack

        Returns:
            bool: True if obj and this stack are equal
        """
        return False

    @override
    def __eq__(self, obj: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            obj (Any): object to compare to this stack

        Returns:
            bool: result from `equals`
        """
        return self.equals(obj)

    def isEmpty(self) -> bool:
        """Checks if this stack has no elements.

        Returns:
            bool: True if this stack is empty, False otherwise
        """
        return True

    def peek(self) -> Optional[T]:
        """Retrieves, but does not remove, the element at the top of this stack.

        Returns:
            topmost element on stack, or None if stack is empty
        """
        return None

    def pop(self) -> Optional[T]:
        """Retrieves and removes the element at the top of this stack.

        Returns:
            topmost element on stack, or None if stack is empty
        """
        return None

    def push(self, element: T) -> None:
        """Inserts an element at the top of this stack.

        Args:
            element: element to add
        """

    def size(self) -> int:
        """Returns the number of elements in this stack.

        Returns:
            int: size of stack
        """
        return 0

    def toArray(self) -> List[T]:
        """Returns an array containing all the elements in this stack.

        Returns:
            List: array of stack elements
        """
        return []

    def toString(self) -> str:
        """Returns a string representation of this stack, e.g. "[element1, element2, element3, ..., elementN]".

        Returns:
            str: string form of this stack
        """
        return "[]"

    @override
    def __str__(self) -> str:
        """Overrides the `__str__` method in the `object` class. Calls `toString`.

        Returns:
            str: result from `toString`
        """
        return self.toString()

    def _checkCapacity(self) -> None:
        """Doubles or halves the size of the internal array depending on size. Used in pop and push methods."""
