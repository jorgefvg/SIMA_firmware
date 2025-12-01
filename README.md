## 📘 Documentación del código

### 🔧 Requisitos previos

Para comenzar a trabajar con este proyecto en C para STM32, es necesario instalar las siguientes herramientas:

---

### 1. **Clang-Format**

- Descarga **Clang-Format** desde la página oficial de LLVM:
  [https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.8](https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.8)
- En este proyecto se utilizó la versión **LLVM-18.1.8-win64.exe**.
- Se recomienda instalar la extensión de **VS Code**:
  **Clang-Format** — desarrollada por *Xaver Hellauer*.
  Esta extensión permite aplicar formato automáticamente al guardar los archivos fuente.

---

### 2. **Pre-commit**

- Para usar **pre-commit** en Windows es necesario tener instalados **Python**, **pip** y **Git**, y asegurarse de que estén agregados al **PATH** del sistema.
- Luego, desde la terminal (CMD o PowerShell), instala pre-commit con "pip install pre-commit"
- En este proyecto se utilizó la versión pre-commit 4.3.0.
- También se recomienda instalar la extensión de VS Code:
  GitHub Actions, para ejecutar automáticamente los hooks de pre-commit cada vez que se haga un pull request a la rama main.

---

### 3. **Doxygen**

- Descarga e instala Doxygen desde: [https://www.doxygen.nl/download.html](https://www.doxygen.nl/download.html)
- Agrega Doxygen al PATH del sistema para poder ejecutarlo desde la terminal.
- En VS Code se puede utilizar la extensión:
  Doxygen Documentation Generator — desarrollada por Christoph Schlosser, que facilita la creación de comentarios compatibles con Doxygen.
- En el archivo doxyfile se pueden cambiar las configuraciones de como queremos la documentacion, por ejemplo lo que mas nos interesa es las opciones de documentacion:
  Le indicamos en que carpeta queremos que se genere la documentacion, para esto hay que crear una carpeta de forma local en la pc, como por ejemplo:
  OUTPUT_DIRECTORY       = build/doc
  Le indicamos en que carpetas se encuentra el codigo a documentar
  - INPUT                  = Drivers/API/Inc
  Le indicamos que carpetas o archivos se deben de excluir en la generacion de la documentacion
  - EXCLUDE                = build
  Entre otras opciones mas revisar el archivo doxifile y cambiar lo que sea necesario.
---

### 4. **Ceedling**
Para realizar testing unitario se utiliza la herramienta Ceedling.
Esta no está disponible directamente en Windows, pero puede instalarse fácilmente a través de WSL (Ubuntu).

Instalación:

Ejecuta los siguientes comandos dentro de la terminal de WSL:
- Instalación de Ruby (requerido por Ceedling) y Gcovr (para reportes de cobertura)

  sudo apt-get install ruby gcovr

- Instalación de Ceedling mediante RubyGems

  sudo gem install ceedling

Dentro del repositorio, puedes crear un nuevo proyecto de Ceedling de dos formas:
- Crear un proyecto en una nueva carpeta:

  ceedling new "nombre_carpeta"

- Crear el proyecto en la carpeta actual:

  ceedling new .

Estos comandos generan automáticamente las carpetas y archivos por defecto:

  src/

  test/support/

  project.yml

Nota importante: en este repositorio ya existe el archivo project.yml, por lo que no es necesario crear un nuevo proyecto Ceedling. Simplemente coloca tus archivos de prueba dentro de la carpeta test/ — no deben crearse en otra ubicación. Tambien es importante revisar que dentro de la carpeta support se cree un archivo llamado .gitkeep (este archivo queda vacio), esto para que la carpeta test se guarde en el repo.

---

### 5. **PlantUML**
Es una herramineta para generar diagramas UML apartir de texto.
Se necesita tener instalado Java para generar los diagramas de UML con PlantUML.
- Para tener Java se puede descargar [Temurin](https://adoptium.net/) que es una distribución oficial y gratuita de Java (OpenJDK) mantenida por la fundación Eclipse.
En este proyecto se descargo la version:
openjdk version "25.0.1" 2025-10-21 LTS
- Descargar [plantuml.jar](https://plantuml.com/es/download#google_vignette) y guardalo en una carpeta.
En este proyecto se instalo la version plantuml-1.2025.10.jar.
- En el archivo doxyfile debemos de agregar la ruta en donde guardamos el archivo plantuml.jar, por ejemplo:
  PLANTUML_JAR_PATH      = /Users/jorgevasquez/Desktop/PlantUML/plantuml.jar

---

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
