# Sistema de Monitoreo Ambiental Inteligente (SIMA)

SIMA es un proyecto de **sistemas embebidos** desarrollado sobre la placa **STM32 B-L475E-IOT01A**, orientado al monitoreo inteligente de variables ambientales. La versión más reciente de la documentación del diseño se encuentra disponible en este [sitio web](https://jorgefvg.github.io/SIMA_documentation/).

El sistema integra un **modelo de Inteligencia Artificial embebido**, ejecutado directamente en el microcontrolador, capaz de realizar inferencias en tiempo real.
Actualmente, el firmware implementa un modelo entrenado con el dataset **Iris**, utilizado como caso de prueba para la clasificación de especies de flores (Setosa, Versicolor y Virginica) a partir de datos de entrada.

![iris_model_ia_embebida_stm32](https://github.com/user-attachments/assets/65982c61-aa31-4704-af7b-d1839fe4694a)

El repositorio incluye:
- Firmware en lenguaje **C** para microcontroladores STM32
- Integración de un modelo de IA convertido de **Python a C** mediante STM32Cube.AI
- Arquitectura de firmware modular y escalable
- Pruebas unitarias, herramientas de automatización y documentación técnica

## 📁 Estructura del repositorio

```
Estructura del proyecto:
SIMA_FIRMWARE/
│
├── .ai/                      ← Archivo de configuracion que permite al IDE gestionar el modelo de IA.
|
├── .github/workflows/        ← Configuración de GitHub Actions para integración continua.
|                               Incluyendo verificación de formato del código y ejecución de pruebas unitarias.
|
├── .settings/                ← Archivos de configuración interna del proyecto en STM32CubeIDE.
|
├── .vscode/                  ← Archivo que le indica a vscode como aplicar formato con clang-format.
|
├── Core/                     ← Contiene el código base del firmware generado y gestionado por STM32CubeIDE.
|   └─/Inc                    ← Archivos de cabecera principales del proyecto STM32.
|   └─/Src                    ← Incluye main.c y la configuración de los periféricos.
|   └─/Startup                ← Archivos de arranque y configuración inicial del microcontrolador.
|
└── Drivers/                  ← Implementa la lógica de la aplicación SIMA.
|   └─/API                    ← Contiene los archivos `.c` y `.h` de la aplicacion.
|   └─/CMSIS                  ← Librerías CMSIS proporcionadas por ARM.
|   └─/STM32L4xx_HAL_Driver   ← Librerías HAL de STMicroelectronics para la familia STM32L4.
|
├── Middlewares/ST/AI         ← Capa que permite que el modelo en C se ejecute sobre el hardware STM32.
|
├── Documentos/               ← Documentación técnica del proyecto.
|
├── test/                     ← Carpeta destinada a pruebas unitarias con la herramienta Ceedling.
|
└── X-CUBE-AI/                ← Incluye los archivos del modelo convertido a C (network.c, network_data.c, etc.).
```

---

## 📄 Archivos de configuración importantes

* **.clang-format**
  Define las reglas de formato del código fuente.

* **.pre-commit-config.yaml**
  Configura validaciones automáticas que se ejecutan antes de cada *commit* o *push*.

* **project.yml**
  Archivo de configuración del proyecto **Ceedling** para pruebas unitarias.

* **doxyfile**
  Configuración para generar documentación automática con **Doxygen**.

---

## 📄 Archivos generados por STM32CubeIDE

* **.project / .cproject / .mxproject**
  Archivos internos del proyecto generados por STM32CubeIDE.

* **SIMA_firmware.ioc**
  Archivo principal de configuración del proyecto en CubeIDE (pines, clocks, periféricos, middleware).

* **SIMA_firmware.launch**
  Configuración de lanzamiento y depuración del proyecto en el entorno de desarrollo.

* **STM32L475VGTX_FLASH.ld**
  Script de *linker* para la memoria Flash del microcontrolador.

* **STM32L475VGTX_RAM.ld**
  Script de *linker* para la memoria RAM del microcontrolador.

---

## 📘 Documentación adicional

- [Requisitos previos](PREREQUISITES.md)
  Lista de herramientas necesarias para trabajar con el proyecto (STM32CubeIDE, Ceedling, clang-format, etc.).

- [Uso del repositorio](USAGE.md)
  Describe el flujo de trabajo recomendado, buenas prácticas y pasos para contribuir al proyecto.

---

## 🚀 Estado del proyecto

El proyecto se encuentra en **desarrollo activo**. De forma incremental se irán agregando nuevos módulos `.c` y `.h` en la carpeta `Drivers/API`, conforme se implementen las distintas funcionalidades soportadas por la placa B-L475E-IOT01.

---

## 👤 Autor

**Jorge F. Vasquez**
Ingeniero Electricista Industrial – Especialidad en Sistemas Embebidos

---
