import MyList from "./mylist";

/**
 * An array list data structure. This class demonstrates explicit use of the
 * `public` keyword for public methods; however, it's not required.
 */
export default class MyArrayList<T> implements MyList<T> {
    public discriminator: "LIST";
    private array: T[];
    private array_size: number;
    private static readonly defaultCapacity = 10;
    private readonly minArrLenThreshold = 100;

    /**
     * Constructs an array list instance with a specified initial capacity.
     * @param initialCapacity initial capacity of this array list. Defaults to
     * 10.
     */
    public constructor(initialCapacity?: number) {
        if (initialCapacity === undefined) {
            initialCapacity = MyArrayList.defaultCapacity;
        } else if (initialCapacity < 0) {
            throw new Error("Negative capacity provided");
        }
        this.array = new Array<T>(initialCapacity);
        this.array_size = 0;
    }

    public add(element: T, index?: number): void {

    }

    public clear(): void {

    }

    public contains(element: T): boolean {
        return false;
    }

    public equals(obj: object): boolean {
        return false;
    }

    public get(index: number): T {
        throw new Error("Index out of bounds");
    }

    public indexOf(element: T): number {
        return -1;
    }

    public isEmpty(): boolean {
        return true;
    }

    public lastIndexOf(element: T): number {
        return -1;
    }

    public remove(index: number): T {
        throw new Error("Index out of bounds");
    }

    public removeElement(element: T): boolean {
        return false;
    }

    public set(index: number, element: T): T {
        throw new Error("Index out of bounds");
    }

    public size(): number {
        return 0;
    }

    public toArray(): T[] {
        return new Array<T>();
    }

    public toString(): string {
        return "[]";
    }

    /**
     * Doubles or halves the size of the internal array depending on size.
     * Used in add and remove methods.
     */
    private checkCapacity(): void {

    }

    /**
     * Helper function for index validation.
     * @param index index to validate
     * @param upperBound value that index must be strictly less than
     */
    private checkIndex(index: number, upperBound: number): void {

    }
}
