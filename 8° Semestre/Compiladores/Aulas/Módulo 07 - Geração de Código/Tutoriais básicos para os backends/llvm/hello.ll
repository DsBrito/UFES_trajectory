; ModuleID = 'hello.c'

@.str = private unnamed_addr constant [15 x i8] c"Hello, World!\0A\00", align 1

define dso_local i32 @main() #0 {
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i64 0, i64 0))
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

