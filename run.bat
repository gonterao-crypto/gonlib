gonmakev2 --gmakefile gmakefile.gmake --dir ./ --buildcommandecho --thread 2 --diff --outpath program.exe
if not errorlevel 1 (
  call runonly.bat
) else (
  echo Error!
)
