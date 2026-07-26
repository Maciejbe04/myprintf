# myprintf

Done:

specifier	
d or i	Signed decimal integer
u	Unsigned decimal integer	
o	Unsigned octal	610
x	Unsigned hexadecimal integer
X	Unsigned hexadecimal integer (uppercase)
c	Character	
s	String of characters	
p	Pointer address	
n	Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location.	
%	A % followed by another % character will write a single % to the stream.


To do:

f	Decimal floating point, lowercase	
F	Decimal floating point, uppercase	
e	Scientific notation (mantissa/exponent), lowercase	
E	Scientific notation (mantissa/exponent), uppercase	
g	Use the shortest representation: %e or %f	
G	Use the shortest representation: %E or %F	
a	Hexadecimal floating point, lowercase	
A	Hexadecimal floating point, uppercase		
p	Pointer address	
n	Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location.	