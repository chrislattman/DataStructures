/* eslint-disable arrow-body-style */
import MyArrayList from "../../../src/typescript/dsa/myarraylist";
const mockSize = jest.fn().mockReturnValue(10);
// All instances of MyArrayList in this entire file are mocks
jest.mock("../../../src/typescript/dsa/myarraylist", () => {
    return jest.fn().mockImplementation(() => {
        return {size: mockSize};
    });
});

test("Test mock", () => {
    const mockList = new MyArrayList<number>();
    expect(mockList.size()).toBe(10);
});
