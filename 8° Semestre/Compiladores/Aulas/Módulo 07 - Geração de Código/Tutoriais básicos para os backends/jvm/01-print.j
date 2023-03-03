.class public pythontest
.super java/lang/Object

.method public static main([Ljava/lang/String;)V
.limit stack 10
.limit locals 10

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "--- EXEMPLO 01: PRINT ---"
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "Hello, World!"
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
bipush 15
invokevirtual java/io/PrintStream/println(I)V
return

.end method