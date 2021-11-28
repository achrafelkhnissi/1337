## EXERCISE 08
* Create a function that displays all different combinations of **n** numbers by ascending order.
* **n** will be so that: 0 < n < 10.
* If **n** == 2, here's the expected output:
```
$>./a.out | cat -e
01, 02, 03, ..., 09, 12, ..., 79, 89$>
```
* Here's how it should be prototyped:
```C
void	ft_print_combn(int n);
```
+ Files to turn in: ft_print_combn.c
+ Allowed functions: ft_putchar

## EXAMPLE

```zsh
➜  ex08 git:(master) ✗ ./a.out 1
0, 1, 2, 3, 4, 5, 6, 7, 8, 9
➜  ex08 git:(master) ✗ ./a.out 2 
01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89
➜  ex08 git:(master) ✗ ./a.out 3 
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789
➜  ex08 git:(master) ✗ ./a.out 4 
0123, 0124, 0125, 0126, 0127, 0128, 0129, 0134, 0135, 0136, 0137, 0138, 0139, 0145, 0146, 0147, 0148, 0149, 0156, 0157, 0158, 0159, 0167, 0168, 0169, 0178, 0179, 0189, 0234, 0235, 0236, 0237, 0238, 0239, 0245, 0246, 0247, 0248, 0249, 0256, 0257, 0258, 0259, 0267, 0268, 0269, 0278, 0279, 0289, 0345, 0346, 0347, 0348, 0349, 0356, 0357, 0358, 0359, 0367, 0368, 0369, 0378, 0379, 0389, 0456, 0457, 0458, 0459, 0467, 0468, 0469, 0478, 0479, 0489, 0567, 0568, 0569, 0578, 0579, 0589, 0678, 0679, 0689, 0789, 1234, 1235, 1236, 1237, 1238, 1239, 1245, 1246, 1247, 1248, 1249, 1256, 1257, 1258, 1259, 1267, 1268, 1269, 1278, 1279, 1289, 1345, 1346, 1347, 1348, 1349, 1356, 1357, 1358, 1359, 1367, 1368, 1369, 1378, 1379, 1389, 1456, 1457, 1458, 1459, 1467, 1468, 1469, 1478, 1479, 1489, 1567, 1568, 1569, 1578, 1579, 1589, 1678, 1679, 1689, 1789, 2345, 2346, 2347, 2348, 2349, 2356, 2357, 2358, 2359, 2367, 2368, 2369, 2378, 2379, 2389, 2456, 2457, 2458, 2459, 2467, 2468, 2469, 2478, 2479, 2489, 2567, 2568, 2569, 2578, 2579, 2589, 2678, 2679, 2689, 2789, 3456, 3457, 3458, 3459, 3467, 3468, 3469, 3478, 3479, 3489, 3567, 3568, 3569, 3578, 3579, 3589, 3678, 3679, 3689, 3789, 4567, 4568, 4569, 4578, 4579, 4589, 4678, 4679, 4689, 4789, 5678, 5679, 5689, 5789, 6789
➜  ex08 git:(master) ✗ ./a.out 5
01234, 01235, 01236, 01237, 01238, 01239, 01245, 01246, 01247, 01248, 01249, 01256, 01257, 01258, 01259, 01267, 01268, 01269, 01278, 01279, 01289, 01345, 01346, 01347, 01348, 01349, 01356, 01357, 01358, 01359, 01367, 01368, 01369, 01378, 01379, 01389, 01456, 01457, 01458, 01459, 01467, 01468, 01469, 01478, 01479, 01489, 01567, 01568, 01569, 01578, 01579, 01589, 01678, 01679, 01689, 01789, 02345, 02346, 02347, 02348, 02349, 02356, 02357, 02358, 02359, 02367, 02368, 02369, 02378, 02379, 02389, 02456, 02457, 02458, 02459, 02467, 02468, 02469, 02478, 02479, 02489, 02567, 02568, 02569, 02578, 02579, 02589, 02678, 02679, 02689, 02789, 03456, 03457, 03458, 03459, 03467, 03468, 03469, 03478, 03479, 03489, 03567, 03568, 03569, 03578, 03579, 03589, 03678, 03679, 03689, 03789, 04567, 04568, 04569, 04578, 04579, 04589, 04678, 04679, 04689, 04789, 05678, 05679, 05689, 05789, 06789, 12345, 12346, 12347, 12348, 12349, 12356, 12357, 12358, 12359, 12367, 12368, 12369, 12378, 12379, 12389, 12456, 12457, 12458, 12459, 12467, 12468, 12469, 12478, 12479, 12489, 12567, 12568, 12569, 12578, 12579, 12589, 12678, 12679, 12689, 12789, 13456, 13457, 13458, 13459, 13467, 13468, 13469, 13478, 13479, 13489, 13567, 13568, 13569, 13578, 13579, 13589, 13678, 13679, 13689, 13789, 14567, 14568, 14569, 14578, 14579, 14589, 14678, 14679, 14689, 14789, 15678, 15679, 15689, 15789, 16789, 23456, 23457, 23458, 23459, 23467, 23468, 23469, 23478, 23479, 23489, 23567, 23568, 23569, 23578, 23579, 23589, 23678, 23679, 23689, 23789, 24567, 24568, 24569, 24578, 24579, 24589, 24678, 24679, 24689, 24789, 25678, 25679, 25689, 25789, 26789, 34567, 34568, 34569, 34578, 34579, 34589, 34678, 34679, 34689, 34789, 35678, 35679, 35689, 35789, 36789, 45678, 45679, 45689, 45789, 46789, 56789
➜  ex08 git:(master) ✗ ./a.out 6
012345, 012346, 012347, 012348, 012349, 012356, 012357, 012358, 012359, 012367, 012368, 012369, 012378, 012379, 012389, 012456, 012457, 012458, 012459, 012467, 012468, 012469, 012478, 012479, 012489, 012567, 012568, 012569, 012578, 012579, 012589, 012678, 012679, 012689, 012789, 013456, 013457, 013458, 013459, 013467, 013468, 013469, 013478, 013479, 013489, 013567, 013568, 013569, 013578, 013579, 013589, 013678, 013679, 013689, 013789, 014567, 014568, 014569, 014578, 014579, 014589, 014678, 014679, 014689, 014789, 015678, 015679, 015689, 015789, 016789, 023456, 023457, 023458, 023459, 023467, 023468, 023469, 023478, 023479, 023489, 023567, 023568, 023569, 023578, 023579, 023589, 023678, 023679, 023689, 023789, 024567, 024568, 024569, 024578, 024579, 024589, 024678, 024679, 024689, 024789, 025678, 025679, 025689, 025789, 026789, 034567, 034568, 034569, 034578, 034579, 034589, 034678, 034679, 034689, 034789, 035678, 035679, 035689, 035789, 036789, 045678, 045679, 045689, 045789, 046789, 056789, 123456, 123457, 123458, 123459, 123467, 123468, 123469, 123478, 123479, 123489, 123567, 123568, 123569, 123578, 123579, 123589, 123678, 123679, 123689, 123789, 124567, 124568, 124569, 124578, 124579, 124589, 124678, 124679, 124689, 124789, 125678, 125679, 125689, 125789, 126789, 134567, 134568, 134569, 134578, 134579, 134589, 134678, 134679, 134689, 134789, 135678, 135679, 135689, 135789, 136789, 145678, 145679, 145689, 145789, 146789, 156789, 234567, 234568, 234569, 234578, 234579, 234589, 234678, 234679, 234689, 234789, 235678, 235679, 235689, 235789, 236789, 245678, 245679, 245689, 245789, 246789, 256789, 345678, 345679, 345689, 345789, 346789, 356789, 456789
➜  ex08 git:(master) ✗ ./a.out 7
0123456, 0123457, 0123458, 0123459, 0123467, 0123468, 0123469, 0123478, 0123479, 0123489, 0123567, 0123568, 0123569, 0123578, 0123579, 0123589, 0123678, 0123679, 0123689, 0123789, 0124567, 0124568, 0124569, 0124578, 0124579, 0124589, 0124678, 0124679, 0124689, 0124789, 0125678, 0125679, 0125689, 0125789, 0126789, 0134567, 0134568, 0134569, 0134578, 0134579, 0134589, 0134678, 0134679, 0134689, 0134789, 0135678, 0135679, 0135689, 0135789, 0136789, 0145678, 0145679, 0145689, 0145789, 0146789, 0156789, 0234567, 0234568, 0234569, 0234578, 0234579, 0234589, 0234678, 0234679, 0234689, 0234789, 0235678, 0235679, 0235689, 0235789, 0236789, 0245678, 0245679, 0245689, 0245789, 0246789, 0256789, 0345678, 0345679, 0345689, 0345789, 0346789, 0356789, 0456789, 1234567, 1234568, 1234569, 1234578, 1234579, 1234589, 1234678, 1234679, 1234689, 1234789, 1235678, 1235679, 1235689, 1235789, 1236789, 1245678, 1245679, 1245689, 1245789, 1246789, 1256789, 1345678, 1345679, 1345689, 1345789, 1346789, 1356789, 1456789, 2345678, 2345679, 2345689, 2345789, 2346789, 2356789, 2456789, 3456789
➜  ex08 git:(master) ✗ ./a.out 8
01234567, 01234568, 01234569, 01234578, 01234579, 01234589, 01234678, 01234679, 01234689, 01234789, 01235678, 01235679, 01235689, 01235789, 01236789, 01245678, 01245679, 01245689, 01245789, 01246789, 01256789, 01345678, 01345679, 01345689, 01345789, 01346789, 01356789, 01456789, 02345678, 02345679, 02345689, 02345789, 02346789, 02356789, 02456789, 03456789, 12345678, 12345679, 12345689, 12345789, 12346789, 12356789, 12456789, 13456789, 23456789
➜  ex08 git:(master) ✗ ./a.out 9
012345678, 012345679, 012345689, 012345789, 012346789, 012356789, 012456789, 013456789, 023456789, 123456789
```

## EXPLAINING

### ft_print_combn() function

Check the examples.

1. We initialize the variable size to hold the input number.
2. Initialize an array with [size] as its size.
3. Initialize an index variable to hold the indexes of the array which is (size - 1)\
	which is the index of the last element.
4. We have to go through the array from last to first starting from the last element\
	down to the first element. and the last element is size - 1 which is the index\
	variable now. So we make a while loop while(index >= 0) while the index isn't\
	the first element we go through the array and assaign the value of index to\
	the current element, and then decrement index-- and repread the process.\
	for example if the input is 9 the array gonna be like {0, 1, 2, 3, 4, 5, 6, 7, 8}.
5. Print the array before stating incrementing any value.
6. Starting a while loop with the condition to check if the first element of the array == 10 - the input.\
	for example: if the input is 4 the array gonna be like {0, 1, 2, 3}\
	10 - 4 = 6.\
	so as long as the the first element is equal or less than 6 the loop gonna continue.\
	6 because the final result must be {6, 7, 8, 9}
7. We check if the last element is less than 9, if true we increment the last element\	and we gonna keep incrementing it as long as it is still less than 9, we stop once we reach number 9.\
	if the value of the last element is 9\
	we check_array() and pass the return value to index.\
	then we check if the value of index is less or equal to 0\
	(because if it is the it means we reached the end of the program)\
	if true we break from the while loop.\
	then we reset_array().\
	then we print_array() the chanches.\

### check_array() function

The function take an array and the length of the array and return an integer that represent an index of the array.\
We get the index by start counting from behind and check if the element before the last == the last element - 1, and go through the array till the condition is no longer true.

for example:\
suppose we have the number 1999\
the index number is the number 9 after 1 -> 1(9)99 because it is not possible to increment all the 9 number after the number 1, and in 1299 the index number is 12(9)9\
in our exercise because we cannot have 999 because of the rule that we have to get an output of a decremented numbers from 9--.\
The other example es: 1789.\
Here the index number is 7.. 1(7)89.\
more examples: 012(9), 0(1), 123(8)9.. and so on.

1. We initialize index to the size of the array - 1
2. While the index is greater than or equal to 0 and the last element of the array == 9. (starting from the last elemet)
3. While the condition above is true we check if the element in the current index equal to the element after the index - 1
4. While the condition above is true we decrement the index by 1, and check go back to step 3.
5. If false we break from the loop and return the index.

Note: if the index is equal or less than 0 it means that hit the final number of the program ex: 6789 (if the input is 4 and the starting number is 0123)

### reset_array() function:

The idea behind reset_array() is simple, it takes three parameters (array, size of array and an index), the index is the position where the last number who reached the point of limit, which is the return value from check_array().\
It takes the array and the length of the array + the index where to start the reset from\
for example suppose out array is {0, 1, 2, 3, 7, 8, 9}\
The index is gonna 4\
so the function gonna increase the value of index[4 - 1]
and go through the array giving the next index the value of the previous [index] + 1\
so the result of out example gonna be {0, 1, 2, 4, 5, 6, 7}\

1. First we initialize (i) to the number before the index\
	ex: index = 1(7)89\
	i = index - 1\
	i = (1)789
2. Increment i by 1. (i++) -> 2789
3. While the two conditions is true
	- (i < size of array - 1) (size - 1) is the last element of the array
 	because we need to increment the i + 1 element till we reach the end 
	of the array.
	- We can check if (i >= 0) but it is not necessary because if (i >= 0)
	the program ends before we reach this point for the first place.
4. While the condition above is true
	- We give the number that comes after (i) (i = (2)789) (i + 1 = 2(7)89)
	the value of (i) + 1;\
	-> Then 2(3)89\
	now we increment (i) by 1, therefore (i) now point to the next element\
	and keep repeating this action till we hit the last elemet\
	so the final result is 2345


Note : The greater the number is, the slower the compilation goes, that's why i optimized my code very well.


### BUGS I FACED
+ I forgot to check the return value of the "check array" function, and therefore i get a segmentation fault error. Because it is suppose to return -1 when we reach the final result, so because i forgot to check for that, i kept getting the error because the functions kept writing values outside of the array.
