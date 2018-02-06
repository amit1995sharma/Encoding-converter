# Encoding-converter
Conversion of UTF-16 to UTF-8 format

In file utfchangenew.cpp 

Hex_to_binary_conversion Do the work for us.

The algorithm behind this is 
as folllow 

For the first byte  the values will be in this form 0XXXXXXX  which will support the value till 7F or we can say x007F


As soon as the last bit changes to 1 for example 80 or x0080 the binary changes to 1000 0000


What happen is UTF-8 is that as is find last bit Active to 1 it will great a format in which 

1) it will new byte and ahead and set 110 to its begining


2) add 000 as prfex to our current 1000 0000   it will look like   000 1000 0000
Now it have 11 bit pair with it.


3) Now we will devide this 11 bit to a pair of 5 and 6

pair-1 = 00010

pair-2 = 000000


4) Now in pair-1 110 will added and pair-2 will be added with 10

Now complete pair will look like 1100 0010 1000 0000   which is equal to C2 80

Note

1 byte first bit is 0

2 byte starting bits 110

3 byte starting bits 1110

4 byte starting bits 11110



