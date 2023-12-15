from typing import Any, TypeVar
from typing_extensions import override
from .mymap import MyMap
from .mylist import MyList

KT = TypeVar("KT")
VT = TypeVar("VT")

class MyHashMap(MyMap[KT, VT]):
    """A hash map data structure utilizing quadratic probing (open addressing). Also called a hash table."""

    DEFAULT_CAPACITY = 16
    DEFAULT_LOAD_FACTOR = 0.75

    def __init__(self, initialCapacity: int = 16, loadFactor: float = 0.75) -> None:
        """Constructs a hash map instance with the specified initial capacity and load factor.

        Args:
            initialCapacity (int, optional): initial capacity of this hash map. Defaults to 16.
            loadFactor (float, optional): maximum value of (number of key-value pairs / number of total slots in hash map)
            before rehashing occurs. Defaults to 0.75.

        Raises:
            ValueError: if initialCapacity is negative or loadFactor is nonpositive
        """
        if initialCapacity < 0:
            raise ValueError("Initial capacity is negative")
        if loadFactor <= 0:
            raise ValueError("Load factor is nonpositive")
        self._key_array = [KT] * initialCapacity
        self._value_array = [VT] * initialCapacity
        self._loadFactor = loadFactor
        self._map_size = 0

    def clear(self) -> None:
        pass

    def containsKey(self, key: KT) -> bool:
        return False

    def containsValue(self, value: VT) -> bool:
        return False

    def equals(self, object: Any) -> bool:
        return False

    @override
    def __eq__(self, object: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            object (Any): object to compare to this hash map

        Returns:
            bool: result from `equals`
        """
        return self.equals(object)

    def get(self, key: KT) -> VT:
        return None

    @override
    def __getitem__(self, key: KT) -> VT:
        """Necessary for inheriting from `MyMap`. Calls `get`.

        Args:
            key: key to search for

        Returns:
            value associated with key, or None if key was not found
        """
        return self.get(key)

    def getOrDefault(self, key: KT, defaultValue: VT) -> VT:
        return None

    def isEmpty(self) -> bool:
        return False

    @override
    def __iter__(self) -> Any:
        """Necessary for inheriting from `MyMap`. Returns an iterator over the keys.

        Returns:
            iterator for this hash map's keys
        """
        return iter(self._key_array)

    def keyList(self) -> MyList[KT]:
        return None

    @override
    def __len__(self) -> int:
        """Necessary for inheriting from `MyMap`. Returns the size of the hash map.

        Returns:
            int: size of hash map
        """
        return self._map_size

    def put(self, key: KT, value: VT) -> VT:
        return None

    def putIfAbsent(self, key: KT, value: VT) -> VT:
        return None

    def remove(self, key: KT) -> VT:
        return None

    def remove(self, key: KT, value: VT) -> bool:
        return False

    def replace(self, key: KT, value: VT) -> VT:
        return None

    def replace(self, key: KT, oldValue: VT, newValue: VT) -> bool:
        return False

    def size(self) -> int:
        return 0

    def toString(self) -> str:
        return ""

    @override
    def __str__(self) -> str:
        """Overrides the `__str__` method in the `object` class. Calls `toString`.

        Returns:
            str: result from `toString`
        """
        return self.toString()