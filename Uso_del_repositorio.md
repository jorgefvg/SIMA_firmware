## Uso del repositorio

Este repositorio utiliza las siguientes herramientas:

1. [clang-format](https://clang.llvm.org/docs/ClangFormat.html) para el mantenimiento de formato del código escrito en lenguaje C
2. [pre-commit](https://pre-commit.com) para validaciones generales de formato del repositorio
3. [ceedling](https://www.throwtheswitch.org/ceedling) para ejecutar las pruebas unitarias en forma automatizada
4. [lcov]() para generar los informes de cobertura de las pruebas unitarias

Después de clonar el repositorio usted debería ejecutar el siguiente comando:

```
pre-commit install
```

Para ejecutar las pruebas unitarias se utiliza el siguiente comando:

```
ceedling test:all
```

Para generar el informe de cobertura de las pruebas se utiliza el siguiente comando:

```
ceedling clobber gcov:all
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
doxygen doxyfile
```

Nota: Los reportes de cobertura por defecto se guardan en la carpeta build/artifacts/gcov/gcovr/GcovCoverageCobertura.html y los reportes de test se guardan en la carpeta build/artifacts/gcov/junit_tests_report.html. La documentacion con doxygen se guarda en la carpeta build/doc/html/index.html.
