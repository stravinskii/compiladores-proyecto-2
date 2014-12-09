.class public hello
.super java/lang/Object

.method public static main([Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   ;ldc 2.0
   ;ldc 3.0
   ;fmul
   ;ldc 4.0
   ;fadd
   ;ldc 1.0
   ;fsub
   ;istore_1
   ;iload_1
   ;ldc "Hello there"
   iconst_1
   invokevirtual java/io/PrintStream/println (Z)V
   
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokestatic hello/helloworld ()Ljava/lang/String;
   invokevirtual java/io/PrintStream/println (Ljava/lang/String;)V

   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokestatic hello/boolreturn ()Z
   invokevirtual java/io/PrintStream/println (Z)V
   return
.end method

.method public static helloworld()Ljava/lang/String;
   ldc "Hello, world"
   areturn
.end method

.method public static boolreturn()Z
   iconst_0
   ireturn
.end method


.end class
