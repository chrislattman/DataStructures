from typing import Generic, List, Optional, TypeVar

from .mypriorityqueue import MyPriorityQueue

T = TypeVar("T")


class Algorithms(Generic[T]):
    """Functions to search and sort lists."""

    @staticmethod
    def binarySearch(
        mylist: List[T], key: T, startIndex: int = 0, endIndex: Optional[int] = None
    ) -> int:
        """Performs a binary search on a list for a specified key, and returns the index of the first match found.

        Result is undefined for an unsorted list.

        Args:
            mylist (List): list to search in
            key: key to find
            startIndex (int, optional): index of first element to search.
            endIndex (int, optional): index of last element to search. Defaults to len(list) - 1.

        Returns:
            int: index of key in list, or -1 if key not found
        """
        if not endIndex:
            endIndex = len(mylist) - 1
        return -1

    @staticmethod
    def mergesort(mylist: List[T]) -> None:
        """Performs an in-memory merge sort of the list.

        Args:
            mylist (List): list to sort
        """
        size = len(mylist)
        temp = [None] * size
        for i in range(size):
            temp[i] = mylist[i]
        Algorithms._mergesort(mylist, temp, 0, size - 1)

    @staticmethod
    def quicksort(mylist: List[T]) -> None:
        """Performs an in-memory quicksort of the list.

        Args:
            mylist (List): list to sort
        """
        Algorithms._quicksort(mylist, 0, len(mylist) - 1)

    @staticmethod
    def heapsort(mylist: List[T]) -> None:
        """Performs an in-memory heapsort of the list.

        Args:
            mylist (List): list to sort
        """
        minHeap = MyPriorityQueue[T](len(mylist))
        mylist_size = len(mylist)
        for i in range(mylist_size):
            minHeap.offer(mylist[i])
            del mylist[i]
        for i in range(mylist_size):
            mylist.append(minHeap.poll())

    @staticmethod
    def _mergesort(mylist: List[T], temp: List[T], left: int, right: int) -> None:
        """Internal merge sort divide and conquer function for lists.

        Args:
            mylist (List): list to sort
            temp (List): temporary list
            left (int): left index
            right (int): right index
        """

    @staticmethod
    def _quicksort(mylist: List[T], left: int, right: int) -> None:
        """Internal high level quicksort function for lists.

        Args:
            mylist (List): list to sort
            left (int): left index
            right (int): right index
        """
        if left < right:
            pivotIndex = Algorithms._partition(mylist, left, right)
            Algorithms._quicksort(mylist, left, pivotIndex - 1)
            Algorithms._quicksort(mylist, pivotIndex, right)

    @staticmethod
    def _partition(mylist: List[T], left: int, right: int) -> int:
        """Partition function for quicksort for lists.

        Args:
            mylist (List): list to sort
            left (int): left index
            right (int): right index

        Returns:
            int: pivot location
        """
        if right - left > 1:
            pivot = Algorithms._findMedian(
                mylist[left], mylist[(left + right) // 2], mylist[right]
            )
        else:
            pivot = mylist[left]
        return 0

    @staticmethod
    def _findMedian(a: T, b: T, c: T) -> T:
        """Finds the median of three values. Used for quicksort.

        Args:
            a: first value
            b: second value
            c: third value

        Returns:
            T: the median of the first, second, and third values
        """
        return b
