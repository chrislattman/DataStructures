from abc import ABC, abstractmethod
from typing import Any, MutableMapping, Optional, TypeVar

from .mylist import MyList

KT = TypeVar("KT")
VT = TypeVar("VT")


class MyMap(ABC, MutableMapping[KT, VT]):
    """Abstract base class (used as an interface) which defines methods for maps.

    Any subclass also needs to override `__getitem__`, `__setitem__`, `__delitem__`,
    `__iter__`, and `__len__`, as part of inheriting from `MutableMapping`.
    """

    @abstractmethod
    def clear(self) -> None:
        """Empties this map of all key-value pairs."""

    @abstractmethod
    def containsKey(self, key: KT) -> bool:
        """Checks if a key is in this map.

        Args:
            key: key to check for

        Returns:
            bool: True if key was found, False otherwise
        """

    @abstractmethod
    def containsValue(self, value: VT) -> bool:
        """Checks if a value is in this map.

        Args:
            value: value to check for

        Returns:
            bool: True if value was found, False otherwise
        """

    @abstractmethod
    def equals(self, object: Any) -> bool:
        """Compares an object with this map for equality.

        Args:
            object (Any): object to compare to this map

        Returns:
            bool: True if object and this map are equal
        """

    @abstractmethod
    def get(self, key: KT) -> Optional[VT]:
        """Returns the value associated with the specified key.

        Args:
            key: key to search for

        Returns:
            value associated with key, or None if key was not found
        """

    @abstractmethod
    def getOrDefault(self, key: KT, defaultValue: VT) -> Optional[VT]:
        """Returns the value associated with the specified key, or a default value if they key was not found.

        Args:
            key: key to search for
            defaultValue: value to return if key was not found in this map

        Returns:
            value associated with key, or defaultValue if key was not found
        """

    @abstractmethod
    def isEmpty(self) -> bool:
        """Checks if this map has no key-value pairs.

        Returns:
            bool: True if this map is empty, False otherwise
        """

    @abstractmethod
    def keyList(self) -> MyList[KT]:
        """Returns a copy of the keys in this map.

        Returns:
            MyList: a list of the keys
        """

    @abstractmethod
    def put(self, key: KT, value: VT) -> Optional[VT]:
        """Inserts a key-value pair into this map. None keys and None values are not permitted.

        Args:
            key: key to add
            value: value associated with key

        Returns:
            previous value associated with key, or None if either key was not found, key is None, or value is None
        """

    @abstractmethod
    def putIfAbsent(self, key: KT, value: VT) -> Optional[VT]:
        """Inserts a key-value pair into this map only if key was not found. None keys and None values are not permitted.

        Args:
            key: key to add
            value: value associated with key

        Returns:
            current value associated with key, or None if either key was not found, key is None, or value is None
        """

    @abstractmethod
    def remove(self, key: KT) -> Optional[VT]:
        """Removes a key-value pair from this map.

        Args:
            key: key to remove

        Returns:
            value associated with key prior to removal, or None if key was not found
        """

    @abstractmethod
    def removeIfPresent(self, key: KT, value: VT) -> bool:
        """Removes a key-value pair from this map only if the key's current value matches the specified value.

        Args:
            key: key to remove
            value: value to check for

        Returns:
            bool: True if the specific key-value pair was found, False otherwise
        """

    @abstractmethod
    def replace(self, key: KT, value: VT) -> Optional[VT]:
        """Replaces the value for a key with another value. None values are not permitted.

        Args:
            key: key to modify value of
            value: new value for key

        Returns:
            previous value associated with key, or None if key was not found or value is None
        """

    @abstractmethod
    def replaceIfPresent(self, key: KT, oldValue: VT, newValue: VT) -> bool:
        """Replaces the value for a key only if the key's current value matches the specified old value.

        None values are not permitted.

        Args:
            key: key to modify value of
            oldValue: old value for key
            newValue: new value for key

        Returns:
            bool: True if the key was found and had a value of oldValue, False otherwise
        """

    @abstractmethod
    def size(self) -> int:
        """Returns the number of key-value pairs in this map.

        Returns:
            int: size of map
        """

    @abstractmethod
    def toString(self) -> str:
        """Returns a string representation of this map, e.g. "{key1=value1, key2=value2, key3=value3, ..., keyN=valueN}".

        Returns:
            str: string form of this map
        """
