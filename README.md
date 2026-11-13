TRABAJO PRÁCTICO INTEGRADOR FINAL
Simulador de Misiones Artemis (Lenguaje C)
- Integrantes y comisión
Carrera: Ingeniería en Sistemas de Información
Universidad: Universidad Tecnológica Nacional – Facultad Regional Resistencia
Integrantes:
Integrante 1: BORDÓN GAUNA; Lautaro. 
Integrante 2: PERNOCHI; Valentino.
Integrante 3: TOMOFF, Julián.
Comisión: ISI K1.3

- Descripción del escenario
El proyecto consiste en desarrollar un simulador en lenguaje C basado en el lanzamiento del cohete Space Launch System (SLS), perteneciente al programa Artemis de la NASA, encargado de transportar la nave Orion.
El escenario representa un ascenso vertical rectilíneo que comienza desde el reposo en la plataforma de lanzamiento del Centro Espacial Kennedy, considerando una posición inicial de 0 m y una velocidad inicial de 0 m/s.
El movimiento se divide en dos fases:
Primera fase:
Durante los primeros segundos del vuelo, el cohete asciende con una aceleración constante de 20,0 m/s², impulsado por los motores principales y los dos cohetes aceleradores.
Al cumplirse los 120 segundos de vuelo, los SRB se desacoplan. El programa calcula la velocidad y la altura alcanzadas hasta ese momento.
Segunda fase:
Luego del desacople, el motor principal continúa impulsando la nave con una aceleración constante de 12,5 m/s² hasta alcanzar una altura de 160.000 metros.
Al llegar a dicha altura, los motores se apagan. A partir de ese momento, el simulador considera un movimiento de caída libre bajo la aceleración de la gravedad, cuyo valor es de 9,80 m/s², para calcular la altura máxima que podría alcanzar la nave antes de comenzar a descender.
El programa también determina la aceleración máxima experimentada durante la primera fase, expresada como múltiplo de la gravedad terrestre.

- Reglas del Juego

El programa presenta un menú interactivo que permite consultar los resultados, modificar los parámetros y visualizar la trayectoria del ascenso.
Las opciones disponibles son:
- Ver reporte de la misión: muestra los resultados de los cálculos realizados.
- Cambiar parámetros: permite ingresar nuevos valores para las aceleraciones, el tiempo de la primera fase y la altura objetivo.
- Ver trayectoria del ascenso: presenta una tabla con los valores de altura y velocidad registrados durante el vuelo.
- Salir: finaliza la ejecución del programa.
- Parámetros modificables
  
El usuario puede modificar los siguientes valores, respetando los rangos establecidos:
- Aceleración (a): 20,0 m/s², con un rango permitido de 5 a 50 m/s².
- Tiempo (t1): 120,0 s, con un rango permitido de 10 a 300 s.
- Segunda aceleración (a2): 12,5 m/s², con un rango permitido de 1 a 30 m/s².
- Altura objetivo: 160.000 m, con un rango permitido de 50.000 a 500.000 m.


El sistema utiliza los siguientes criterios al finalizar la simulación:
- Misión exitosa: cuando existe una segunda fase y la aceleración máxima no supera el límite establecido de 4 g.
- Aceleración excesiva: cuando la aceleración máxima de la primera fase supera los 4 g.
- Perfil de vuelo inválido: cuando la primera fase alcanza o supera la altura objetivo, por lo que no resulta necesaria una segunda fase.
El límite de 4 g es un criterio simplificado definido para este proyecto y no representa una certificación real de seguridad para vuelos tripulados.

- Funcionamiento del programa
Al iniciar el simulador, se establecen los valores iniciales de los parámetros y se realizan automáticamente los cálculos de la misión y la simulación del ascenso.
Posteriormente, se muestra un menú que permite al usuario interactuar con el programa.
El reporte presenta los siguientes resultados:

- Velocidad alcanzada al finalizar la primera fase (v1).
- Altura alcanzada al momento del desacople de los SRB (y1).
- Velocidad al momento del apagado de los motores (v2).
- Tiempo total transcurrido hasta el apagado de los motores.
- Altura máxima estimada durante la caída libre (hmáx).
- Aceleración máxima expresada en múltiplos de g.
- Veredicto de la misión según los criterios establecidos.

Además, el usuario puede consultar una tabla que representa la trayectoria del ascenso, mostrando los valores de altura y velocidad registrados.
Cuando se modifican los parámetros, el programa vuelve a calcular los resultados y genera una nueva trayectoria.
También se contemplan situaciones particulares, como el caso en el que la primera fase alcanza o supera directamente la altura objetivo. En ese caso, se informa que no existe una segunda fase válida.

- Arquitectura y modularización
El programa fue desarrollado en lenguaje C y organizado en diferentes archivos para separar las responsabilidades y facilitar su comprensión.
La estructura del proyecto es la siguiente:

Simulador-Artemis/
│
├── main.c
├── simulador.c
├── simulador.h
├── validaciones.c
├── validaciones.h

Descripción de los archivos: 

- main.c: Contiene la función principal main(). Se encarga de inicializar la estructura de simulación, ejecutar los cálculos iniciales y controlar el menú de opciones mediante una estructura repetitiva do-while y estructuras condicionales.
- simulador.c: Contiene las funciones encargadas de realizar los cálculos físicos y presentar los resultados:
calcular_mision(): calcula las velocidades, alturas, tiempo de apagado y altura máxima.
simular_ascenso(): genera los datos de la trayectoria del cohete.
mostrar_reporte(): presenta los resultados obtenidos.
mostrar_trayectoria(): muestra los datos de altura y velocidad durante el ascenso.
- simulador.h: Define la estructura SimulacionSLS, que almacena los parámetros de entrada, los resultados y los datos de la trayectoria. También contiene constantes y declaraciones de funciones utilizadas en el módulo.
- validaciones.c: Contiene las funciones destinadas a controlar las entradas ingresadas por el usuario. Verifica que los datos sean numéricos y que los valores se encuentren dentro de los rangos permitidos.
validaciones.h
Contiene las declaraciones de las funciones de validación utilizadas desde el programa principal.
Esta organización permite dividir el programa en módulos independientes, facilitando la reutilización de funciones. 

- Compilación y ejecución
Requisitos: 
Para compilar y ejecutar el programa se necesita:
Un sistema operativo Windows, Linux o equivalente.
Un compilador de lenguaje C, como GCC.
Visual Studio Code u otro editor de código (opcional).
En Windows se puede utilizar GCC mediante MSYS2.
Compilación: 
Ubicarse desde la terminal en la carpeta raíz del proyecto y ejecutar:
gcc main.c simulador.c validaciones.c -o simulador -lm
Ejecución: 
En Windows:./simulador.exe
En Linux: ./simulador
Una vez ejecutado, aparecerá el menú principal del simulador.

- Registro del uso de Inteligencia Artificial
Durante el desarrollo del simulador se utilizaron herramientas de Inteligencia Artificial, como Gemini y Claude, para obtener comprender de mejor manera la sintaxis del lenguaje C y generar ideas que contribuyeran al desarrollo del programa.
Los principales usos de estas herramientas fueron:
Explicación de conceptos y de la sintaxis del lenguaje C.
Generación de ideas para lograr un desarrollo más creativo y organizado del programa.
Asistencia en la identificación de los comandos necesarios para realizar operaciones de Git, como los commits y el envío de archivos al repositorio.
Interpretación de mensajes de error del compilador GCC.
Identificación y corrección de errores en el código.

- Conclusión
El desarrollo de este simulador permitió aplicar conceptos de programación en C, como estructuras, funciones, modularización, estructuras condicionales y repetitivas, validación de datos y manejo de arreglos.
Además, permitió relacionar los contenidos de programación con conceptos físicos del movimiento rectilíneo uniformemente acelerado y la caída libre.
Consideramos que este trabajo final integrador fue una oportunidad para integrar los conocimientos adquiridos durante la cursada y trabajar en equipo para desarrollar una aplicación interactiva que resuelve el escenario planteado.
