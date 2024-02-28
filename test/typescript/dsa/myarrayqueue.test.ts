import MyArrayQueue from "../../../src/typescript/dsa/myarrayqueue";

let myArrayQueue: MyArrayQueue<number>;

beforeAll(() => {

});

beforeEach(() => {
    myArrayQueue = new MyArrayQueue<number>();
    myArrayQueue.clear();
});

test("Test constructor", () => {
    expect(() => {
        new MyArrayQueue<number>(-1);
    }).toThrow(Error);
});

test("Test equals", () => {
    expect(myArrayQueue.equals(myArrayQueue)).toBeFalsy();
});

test("Test isEmpty", () => {
    expect(myArrayQueue.isEmpty()).toBeTruthy();
});

test("Test offer", () => {
    myArrayQueue.offer(5);
    expect(myArrayQueue.peek()).toBeNull();
});

test("Test peek", () => {
    expect(myArrayQueue.peek()).toBeNull();
});

test("Test poll", () => {
    expect(myArrayQueue.poll()).toBeNull();
});

test("Test size", () => {
    expect(myArrayQueue.size()).toBe(0);
});

test("Test toString", () => {
    expect(myArrayQueue.toString()).toBe("[]");
});

afterEach(() => {

});

afterAll(() => {

});
