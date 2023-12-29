from typing import Any, Optional, TypeVar

from typing_extensions import override

from .myarraylist import MyArrayList
from .mylist import MyList
from .mymap import MyMap

KT = TypeVar("KT")
VT = TypeVar("VT")


class MyHashMap(MyMap[KT, VT]):
    """A hash map data structure utilizing quadratic probing (open addressing). Also called a hash table."""

    DEFAULT_CAPACITY = 16
    DEFAULT_LOAD_FACTOR = 0.75

    def __init__(
        self, initialCapacity: Optional[int] = None, loadFactor: Optional[float] = None
    ) -> None:
        """Constructs a hash map instance with the specified initial capacity and load factor.

        Args:
            initialCapacity (int, optional): initial capacity of this hash map. Defaults to 16.
            loadFactor (float, optional): maximum value of (number of key-value pairs / number of total slots in hash map)
            before rehashing occurs. Defaults to 0.75.

        Raises:
            ValueError: if initialCapacity is negative or loadFactor is nonpositive
        """
        if not initialCapacity:
            initialCapacity = self.DEFAULT_CAPACITY
        elif initialCapacity < 0:
            raise ValueError("Initial capacity is negative")
        if not loadFactor:
            loadFactor = self.DEFAULT_LOAD_FACTOR
        elif loadFactor <= 0:
            raise ValueError("Load factor is nonpositive")
        self._key_array = [None] * initialCapacity
        self._value_array = [None] * initialCapacity
        self._loadFactor = loadFactor
        self._map_size = 0

    def clear(self) -> None:
        pass

    def containsKey(self, key: KT) -> bool:
        return False

    def containsValue(self, value: VT) -> bool:
        return False

    def __delitem__(self, key: KT) -> None:
        """Necessary for inheriting from `MyMap`. Calls `remove`.

        Args:
            key: key to remove
        """
        self.remove(key)

    def equals(self, obj: Any) -> bool:
        return False

    @override
    def __eq__(self, obj: Any) -> bool:
        """Overrides the `__eq__` method in the `object` class. Calls `equals`.

        Args:
            obj (Any): object to compare to this hash map

        Returns:
            bool: result from `equals`
        """
        return self.equals(obj)

    def getValue(self, key: KT) -> Optional[VT]:
        return None

    def __getitem__(self, key: KT) -> Optional[VT]:
        """Necessary for inheriting from `MyMap`. Calls `get`.

        Args:
            key: key to search for

        Returns:
            value associated with key, or None if key was not found
        """
        return self.getValue(key)

    def getOrDefault(self, key: KT, defaultValue: VT) -> Optional[VT]:
        return None

    def isEmpty(self) -> bool:
        return False

    def __iter__(self) -> Any:
        """Necessary for inheriting from `MyMap`. Returns an iterator over the keys.

        Returns:
            iterator for this hash map's keys
        """
        return iter(self._key_array)

    def keyList(self) -> MyList[KT]:
        newlist = MyArrayList[KT]()
        return newlist

    def __len__(self) -> int:
        """Necessary for inheriting from `MyMap`. Returns the size of the hash map.

        Returns:
            int: size of hash map
        """
        return self.size()

    def put(self, key: KT, value: VT) -> Optional[VT]:
        return None

    def putIfAbsent(self, key: KT, value: VT) -> Optional[VT]:
        return None

    def remove(self, key: KT) -> Optional[VT]:
        return None

    def removeIfPresent(self, key: KT, value: VT) -> bool:
        return False

    def replace(self, key: KT, value: VT) -> Optional[VT]:
        return None

    def replaceIfPresent(self, key: KT, oldValue: VT, newValue: VT) -> bool:
        return False

    def __setitem__(self, key: KT, value: VT) -> None:
        """Necessary for inheriting from `MyMap`. Calls `put`.

        Args:
            key: key to add
            value: value associated with key
        """
        self.put(key, value)

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

    def _insert(
        self,
        key: KT,
        newValue: VT,
        oldValue: VT,
        addOnlyIfAbsent: bool,
        addOnlyIfKeyExists: bool,
    ) -> Optional[VT]:
        """Internal function used to add or modify a key-value pair in this hash map.

        Args:
            key: key to add
            newValue: value to be associated with key
            oldValue: current value to check for (existing key only), leave as None if not applicable
            addOnlyIfAbsent (bool): if false, replace current value with specified new value
            addOnlyIfKeyExists (bool): if true, only replace value if key already exists

        Returns:
            previous or current value associated with key, or None if either key was not found, key is None,
            or newValue is None
        """
        return None

    def _resizeMap(self) -> None:
        """Increases the hash map size and rehashes the key-value pairs when load factor has been surpassed."""
