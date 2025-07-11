package dsa

import "testing"

// assertEquals fails if expected does not equal actual.
func assertEquals(t *testing.T, expected, actual any) {
	if actual != expected {
		t.Fatalf("expected %v but was %v\n", expected, actual)
	}
}

// assertTrue fails if actual is false.
func assertTrue(t *testing.T, actual bool) {
	if !actual {
		t.Fatal("expected true but was false")
	}
}

// assertFalse fails if actual is true.
func assertFalse(t *testing.T, actual bool) {
	if actual {
		t.Fatal("expected false but was true")
	}
}

// assertNil fails if actual is non-nil.
func assertNil(t *testing.T, actual any) {
	if actual != nil {
		t.Fatal("expected nil but was non-nil")
	}
}

// assertNotNil fails if actual is nil.
func assertNotNil(t *testing.T, actual any) {
	if actual == nil {
		t.Fatal("expected non-nil but was nil")
	}
}
