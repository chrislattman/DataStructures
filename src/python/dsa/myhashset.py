from typing import Any, List, TypeVar
from typing_extensions import override
from .myset import MySet
from .myhashmap import MyHashMap

T = TypeVar("T")

class MyHashSet(MySet[T]):
    """A hash set data structure built upon a hash map."""

    DEFAULT_CAPACITY = 16
    DEFAULT_LOAD_FACTOR = 0.75

    def __init__(self, initialCapacity: int = 16, loadFactor: float = 0.75) -> None:
        """Constructs a hash set instance with the specified initial capacity and load factor.

        Args:
            initialCapacity (int, optional): initial capacity of this hash set. Defaults to 16.
            loadFactor (float, optional): maximum value of (number of key-value pairs / number of total slots in hash set)
            before rehashing occurs. Defaults to 0.75.

        Raises:
            ValueError: if initialCapacity is negative or loadFactor is nonpositive
        """
        self._map = MyHashMap[T, int](initialCapacity, loadFactor)

    def add(self, element: T) -> bool:
        return False

    def clear(self) -> None:
        pass

    def contains(self, element: T) -> bool:
        return False

    @override
    def __contains__(self, element: T) -> bool:
        """Checks if an element is in this set.

        Args:
            element: element to check for

        Returns:
            bool: True if found, False otherwise
        """
        return self.contains(element)

    @override
    def discard(self, element: T) -> None:
        """Removes an element from this set.

        Args:
            element: element to remove
        """
        self.remove(element)

    def equals(self, object: Any) -> bool:
        return False

    @override
    def __eq__(self, object: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            object (Any): object to compare to this hash set

        Returns:
            bool: result from `equals`
        """
        return self.equals(object)

    def isEmpty(self) -> bool:
        return False

    @override
    def __iter__(self) -> Any:
        """Returns an iterator over the keys.

        Returns:
            iterator for this hash set
        """
        return iter(self._map._key_array)

    @override
    def __len__(self) -> int:
        """Returns the number of elements in this set.

        Returns:
            int: size of set
        """
        return self.size()

    def remove(self, element: T) -> bool:
        return False

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
