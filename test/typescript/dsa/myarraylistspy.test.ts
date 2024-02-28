import MyArrayList from "../../../src/typescript/dsa/myarraylist";

test("Test spy", () => {
    // eslint-disable-next-line @typescript-eslint/no-unused-vars
    const containsMock = jest.spyOn(
        MyArrayList.prototype, "contains").mockImplementation((value: number) => {
            if (value == 3) {
                return true;
            }
            return false;
    });
    // Spying on contains() method (but not for a specific MyArrayList object)
    const spyList = new MyArrayList<number>();
    expect(spyList.contains(3)).toBeTruthy();
    expect(spyList.contains(4)).toBeFalsy();
    expect(spyList.size()).toBe(0);
});
