del /s /q program.exe

gonmake -dir "./" -o "program.exe" -cu "--target=x86_64-w64-mingw32 -std=c++26 -O0 -fdiagnostics-absolute-paths -fcolor-diagnostics -fansi-escape-codes"
if exist "program.exe" (
  program
) else (
  echo Error!
)
