import { MyArrayList } from "../../../src/typescript/dsa/myarraylist";

let myArrayList: MyArrayList<number>;

beforeAll(() => {

});

beforeEach(() => {
    myArrayList = new MyArrayList<number>();
    myArrayList.clear();
});

test("Test add", () => {
    myArrayList.add(5);
    expect(myArrayList.size()).toBe(0);
});

test("Test contains", () => {
    myArrayList.add(5);
    expect(myArrayList.contains(5)).toBeFalsy();
});

test("Test equals", () => {
    expect(myArrayList.equals(myArrayList)).toBeFalsy();
});

test("Test get", () => {
    expect(() => {
        myArrayList.get(0);
    }).toThrow(Error);
});

test("Test indexOf", () => {
    expect(myArrayList.indexOf(5)).toBe(-1);
});

test("Test isEmpty", () => {
    expect(myArrayList.isEmpty()).toBeTruthy();
});

test("Test lastIndexOf", () => {
    expect(myArrayList.lastIndexOf(5)).toBe(-1);
});

test("Test remove", () => {
    expect(() => {
        myArrayList.remove(0);
    }).toThrow(Error);
});

test("Test removeElement", () => {
    expect(myArrayList.removeElement(5)).toBeFalsy();
});

test("Test set", () => {
    expect(() => {
        myArrayList.set(1, 5);
    }).toThrow(Error);
});

test("Test size", () => {
    expect(myArrayList.size()).toBe(0);
});

test("Test toString", () => {
    expect(myArrayList.toString()).toBe("[]");
});

afterEach(() => {

});

afterAll(() => {

});
