.class public prueba
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "Hola mundo!"
invokevirtual java/io/PrintStream/println
(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
bipush 2
bipush 3
imul
bipush 4
iadd
bipush 1
isub
invokevirtual java/io/PrintStream/println
(I)V
bipush 22

return
.end method
.end class
