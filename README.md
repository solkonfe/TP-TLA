# Trabajo Práctico Especial - "72.39 - Autómatas, Teoría de Lenguajes y Compiladores"

Este lenguaje propone una capa de abstracción para quienes desean incursionar en el mundo de la programaicón web y, mas precisamente, HTML pero encuentran que su sintaxis es engorrosa para iniciarse. El mismo permtie, con *keywords* muy simples, generar un output en HTML para que el usuario deba preocuparse únicamente por lo que espera de su página, y no por la sintaxis de la misma. 

## Requerimientos

Para construir el compilador, se requieren las siguientes dependencias:

* [Bison v3.8.2](https://www.gnu.org/software/bison/)
* [CMake v3.22.2](https://cmake.org/)
* [Flex v2.6.4](https://github.com/westes/flex)
* [GCC v11.1.0](https://gcc.gnu.org/)
* [Make v4.3](https://www.gnu.org/software/make/)

Si en lugar de trabajar con un entorno _Linux_, se está construyendo el proyecto sobre un entorno _Microsoft Windows_, se debe instalar _Microsoft Visual Studio 2022_ con las extensiones para desarrollar aplicaciones en _C/C++_, así como también las herramientas requeridas, con excepción del compilador _GCC_ y la herramienta _Make_.

## Construcción

Para construir el proyecto por completo, ejecute en la raíz del repositorio el siguiente comando:

```bash
user@machine:path/ $ cmake -S . -B bin
user@machine:path/ $ cd bin
user@machine:path/ $ make
```
También fue creado el archivo `compileIt.sh`, que hace esto mismo. Solo es necesario correr el archivo de la siguiente manera:

```
./compileIt.sh
```

En un entorno _Microsoft Windows_, en lugar de ejecutar el comando `make`, se deberá abrir la solución generada `bin/Compiler.sln` con el IDE _Microsoft Visual Studio 2022_. Los ejecutables que este sistema construye se depositan dentro del directorio `bin/Debug` y `bin/Release` según corresponda.

## Ejecución

Para compilar los testeos, puede correr el programa tester.sh

```
./tester.sh
```

Luego, las salidas de cada test se encuentran dentro de la carpeta:

```bash
src/logs/testlogs
```

Es posible también que, ante el fallo de alguno de los tests, el output no se guarde en los logs dado que pudo haber finalizado de manera abrupta. Es por eso que se recomienda ejecutar los testeos **individualmente** de la siguiente manera:
```
cat tests/test{i} | bin/Compiler
```
donde _i_ es un índice para el número de test.

## Integrantes
Nombre | Legajo
-------|--------
[De Luca, Juan Manuel](https://github.com/juandl14) | 60103
[Konfederak, Sol](https://github.com/solkonfe) | 60255
[Dizenhaus, Manuel](https://github.com/ManuelDizen) | 61101
[Cornidez, Milagros](https://github.com/mcornidez) | 61432
