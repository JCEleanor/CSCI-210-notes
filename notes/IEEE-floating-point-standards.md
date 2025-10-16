# IEEE 754 Single-Precision Floating-Point Standard

The **IEEE 754 Single-Precision Floating-Point** standard is the most common way computers represent real numbers (like 3.14 or -0.0025) in a compact, 32-bit format.

It functions like a binary version of scientific notation (e.g., 6.022 x 10²³), breaking a number down into three fundamental parts: the sign, the exponent, and the fraction (or mantissa).

### The 32-Bit Structure

A 32-bit single-precision float is divided into three distinct fields:

| Part      | Size    | Description                               |
| :-------- | :------ | :---------------------------------------- |
| **Sign**  | 1 bit   | Determines if the number is positive or negative. |
| **Exponent**| 8 bits  | Represents the scale or magnitude of the number. |
| **Fraction**| 23 bits | Represents the precision digits of the number. |

**Visual Layout:**
`S | EEEEEEEE | FFFFFFFFFFFFFFFFFFFFFFF`

The value of a number is reconstructed using this formula:

**Value = (-1)^Sign * (1.Fraction) * 2^(Exponent - 127)**

---

### 1. The Sign Bit (S)

This is the most straightforward part of the standard.
*   **0** = Positive number
*   **1** = Negative number

---

### 2. The Exponent (E)

The exponent field determines the overall magnitude of the number—whether it's very large or very small.

*   It's an 8-bit field, capable of holding 256 different values (from 0 to 255).
*   **Biased Representation:** To represent both positive and negative exponents, the standard uses a **bias of 127**. The actual exponent is found by subtracting this bias from the stored value.
    *   **Actual Exponent = Stored Exponent - 127**
*   This method allows the actual exponent to range from -126 to +127.
*   The two extreme exponent values, 0 (all `0`s) and 255 (all `1`s), are reserved for representing special cases.

---

### 3. The Fraction / Mantissa (F)

The fraction (also known as the mantissa or significand) holds the significant digits of the number, determining its precision.

*   **Normalized Form & The Hidden Bit:** Any binary number can be expressed in scientific notation as `1.xxxx... * 2^exponent`. Because the leading digit for any non-zero number is *always* `1`, it doesn't need to be explicitly stored. This is known as the **"hidden bit"** or "implicit bit."
*   The 23 bits of the fraction field are used to store the digits that come *after* this implicit `1.`.
*   This clever optimization effectively provides **24 bits of precision** while only requiring 23 bits of storage.

---

### Representing Special Values

The IEEE 754 standard reserves specific patterns in the exponent field to represent values that are not ordinary numbers.

#### 1. Representing Zero

A value is interpreted as zero when the exponent and fraction fields are both all zeros. The sign bit can be either 0 or 1, which leads to two distinct representations of zero: `+0` and `-0`.

*   **Exponent:** `00000000`
*   **Fraction:** `00000000000000000000000`
*   **Sign Bit:** `0` for `+0`, `1` for `-0`.

#### 2. Representing Very Small (Denormalized) Numbers

To represent numbers that are smaller than the smallest possible "normal" number, the standard uses a format called **denormalized** (or **subnormal**) numbers. This allows for "gradual underflow," where precision is lost gracefully as a number approaches zero.

A number is denormalized if:
*   **Exponent:** `00000000`
*   **Fraction:** Any non-zero value.

In this case, the "hidden bit" is assumed to be `0` (not `1`), and the exponent is fixed at the lowest possible value (-126). The formula becomes:
**Value = (-1)^Sign * (0.Fraction) * 2^(-126)**

#### 3. Representing Exceptional Values (Infinity and NaN)

Exceptional values are used for results of operations that overflow the representable range or are mathematically undefined. This is handled when the exponent field is all ones.

*   **Exponent:** `11111111`

There are two sub-cases:

*   **Infinity:** If the **fraction field is all zeros**, the value represents **infinity**. This occurs during overflow or division by zero. The sign bit determines whether it is positive infinity (`+∞`) or negative infinity (`-∞`).

*   **NaN (Not a Number):** If the **fraction field is any non-zero value**, the value is **NaN**. This is the result of mathematically invalid operations, such as `0/0` or the square root of a negative number.

### Example: Representing -12.75

1.  **Sign:** The number is negative, so the **Sign bit = 1**.

2.  **Binary Conversion:**
    *   `12` in decimal is `1100` in binary.
    *   `0.75` in decimal is `0.5 + 0.25`, which is `1/2 + 1/4` or `.11` in binary.
    *   Combining these, `12.75` in binary is `1100.11`.

3.  **Normalize (Scientific Notation):**
    *   To get the form `1.xxxx...`, move the binary point: `1.10011 * 2^3`.

4.  **Calculate the Component Fields:**
    *   **Exponent:** The actual exponent is `3`. The value to be stored is `3 + 127 (bias) = 130`.
        *   `130` in 8-bit binary is `10000010`.
    *   **Fraction:** The fraction is the part after the `1.` in the normalized form: `10011`.
        *   This is padded with zeros to fill the 23-bit field: `10011000000000000000000`.

5.  **Assemble the Final 32-bit Representation:**

    **`1 | 10000010 | 10011000000000000000000`**
