# Encoding-converter
Conversion of UTF-16 to UTF-8 format

Created one buffer list with character      
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"-_.~"

After recieving the UTF-16 string, break it to chracter or 1 byte.

Now Check each byte in the above list std:npos with do that for us.

If the byte is present in the list it will add it to the result

otherwise it will call hex(c) funtion with will convert that byte to Uppercase and Hexadecimal code and add to the list

for example:

☺ (smily) UTF-16 3-bytes
it will break it and check the values
1-byte = 226 which will not be present in the buffer so it will create hexadecimal code and generate E2
2nd byte = 152 generate 98
3rd byte = 186 generate BA

Outout will be E298BA



