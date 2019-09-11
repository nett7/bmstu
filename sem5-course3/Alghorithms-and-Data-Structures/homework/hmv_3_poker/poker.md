## attempt 0

0.

for numbers:

[x], [x], 2, 3, 4, 5, 6, 7, 8, 9, t, j, q, k, a, [x]

map to hex

[0], [1], 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, [f]

hex - 2

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, [d], [e], [f]

for pics:

clubs (♣), diamonds (♦), hearts (♥) and spades (♠)

map to 0-3:

(♣):0, (♦):1, (♥):2, (♠):3

1. 

num 1 + pic 1 + num 2 + pic 2

4 + 2 + 4 + 2 = 12

Example:

2 of (♥) + A of (♠)

0x0 + 2 + 0xc + 3

0000+10+1100+11

000010110011 (12 b)

## attempt 1
### hand matrix

![](hand_matrix.png)

0.

for numbers:

[x], [x], 2, 3, 4, 5, 6, 7, 8, 9, t, j, q, k, a, [x]

map to hex

[0], [1], 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, [f]

hex - 2

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, [d], [e], [f]

for pics:

clubs (♣), diamonds (♦), hearts (♥) and spades (♠)

map to 0-3:

(♣):0, (♦):1, (♥):2, (♠):3

00, 01, 02, 03, 10, 11, 12, 13, 20, 21, 22, 23, 30, 31, 32, 33

map combos to hex

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f

1.

Green + yellow = 78 combo

64 < 91 < 128 -> 7 bits

2.

4^2 = 16 combos = 4 bits

3.

7 + 4 = 8 bits

4. 

sort in disc order

5.

numb# + combo

Example:

2 of (♥) + A of (♠)

sort in discending order

A of (♠) + 2 of (♥)

A2 -> #12 -> 1100b -> 0001100b+

(♠)+(♥) -> 32 -> 0xe -> 1110b

00011001110 (11b)




