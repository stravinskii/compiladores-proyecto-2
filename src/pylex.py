# this is a comment in python
for x in xrange(1,10):
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