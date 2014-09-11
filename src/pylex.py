# this is "string en comentario" a comment in python
s = "Something string"
for x in s:
# is this a valid comment
	x = True
	while x:
# comments dont matter at ident
		x = False
	pass

#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
x = "Codigo de prueba"
avanza = True
while avanza: #comentario a media linea
	y += 1
	if y == 8 :
		#comentario nueva linea
		print "Y es 8"
		avanza = False
	else:
#Comentario mal identado	
		print " esta es una cadenaa"
		z = 10
print "Termina el programa"


num = 2
num1 = 2 * 3
num2 = 2 / 1
num2 -= 1 
while num < 11:
	if num % 2 == 0:
		print num , " es par"
	else:
		print num , " es impar"	
	num += 1
cadena = "Palabra"
for c in cadena:
    print c
