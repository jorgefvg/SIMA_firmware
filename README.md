# Sistema de Monitoreo Ambiental Inteligente (SIMA)

Proyecto de **sistemas embebidos** desarrollado sobre la placa **STM32 B-L475E-IOT01**, orientado al monitoreo ambiental inteligente. Este repositorio contiene el firmware del sistema, así como herramientas de automatización, pruebas unitarias y documentación técnica.

El objetivo del proyecto es construir una base escalable y bien estructurada para integrar sensores, procesamiento de datos y futuras funcionalidades (por ejemplo, conectividad o inteligencia artificial embebida).

## 📁 Estructura del repositorio

```
Estructura del proyecto:
SIMA_FIRMWARE/
│
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
├── Documentos/               ← Documentación técnica del proyecto.
|
└── test/                     ← Carpeta destinada a pruebas unitarias con la herramienta Ceedling.
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

* **Requisitos_previos.md**
  Lista de herramientas necesarias para trabajar con el proyecto (STM32CubeIDE, Ceedling, clang-format, etc.).

* **Uso_del_repositorio.md**
  Describe el flujo de trabajo recomendado, buenas prácticas y pasos para contribuir al proyecto.

---

## 🚀 Estado del proyecto

El proyecto se encuentra en **desarrollo activo**. De forma incremental se irán agregando nuevos módulos `.c` y `.h` en la carpeta `Drivers/API`, conforme se implementen las distintas funcionalidades soportadas por la placa B-L475E-IOT01.

---

## 👤 Autor

**Jorge F. Vasquez**
Ingeniero Electricista Industrial – Especialidad en Sistemas Embebidos

---
