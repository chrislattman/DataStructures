package dsa;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class MyArrayListTest {
    MyArrayList<Integer> myArrayList;

    @BeforeAll
    static void initAll() {

    }

    @BeforeEach
    void init() {
        myArrayList = new MyArrayList<>();
        myArrayList.clear();
    }

    @Test
    void testAdd() {
        myArrayList.add(5);
        assertEquals(1, myArrayList.size());
    }

    @Test
    void testContains() {
        myArrayList.add(5);
        assertTrue(myArrayList.contains(5));
        assertFalse(myArrayList.contains(6));
    }

    @Test
    void testEquals() {
        assertTrue(myArrayList.equals(myArrayList));
        assertFalse(myArrayList.equals(null));
        MyArrayList<Integer> myArrayList2 = new MyArrayList<>();
        myArrayList2.add(7);
        assertFalse(myArrayList.equals(myArrayList2));
        myArrayList.add(7);
        assertTrue(myArrayList.equals(myArrayList2));
    }

    @Test
    void testGet() {
        assertThrows(IndexOutOfBoundsException.class, () -> myArrayList.get(0));
        myArrayList.add(5);
        assertEquals(5, myArrayList.get(0));
    }

    @Test
    void testIndexOf() {
        assertEquals(-1, myArrayList.indexOf(5));
        myArrayList.add(5);
        assertEquals(0, myArrayList.indexOf(5));
    }

    @Test
    void testIsEmpty() {
        assertTrue(myArrayList.isEmpty());
    }

    @Test
    void testLastIndexOf() {
        assertEquals(-1, myArrayList.lastIndexOf(5));
        myArrayList.add(5);
        assertEquals(0, myArrayList.lastIndexOf(5));
    }

    @Test
    void testRemove() {
        assertThrows(IndexOutOfBoundsException.class, () -> myArrayList.remove(0));
        myArrayList.add(5);
        assertEquals(5, myArrayList.remove(0));
        assertTrue(myArrayList.isEmpty());
    }

    @Test
    void testRemoveElement() {
        assertFalse(myArrayList.removeElement(5));
        myArrayList.add(5);
        assertTrue(myArrayList.removeElement(5));
        assertTrue(myArrayList.isEmpty());
    }

    @Test
    void testSet() {
        assertThrows(IndexOutOfBoundsException.class, () -> myArrayList.set(1, 5));
        myArrayList.add(5);
        assertEquals(5, myArrayList.set(0, 6));
        assertEquals(6, myArrayList.get(0));
    }

    @Test
    void testSize() {
        assertEquals(0, myArrayList.size());
    }

    @Test
    void testToString() {
        assertEquals("[]", myArrayList.toString());
        myArrayList.add(5);
        assertEquals("[5]", myArrayList.toString());
        myArrayList.add(6);
        assertEquals("[5, 6]", myArrayList.toString());
    }

    @AfterEach
    void tearDown() {

    }

    @AfterAll
    static void tearDownAll() {

    }
}
