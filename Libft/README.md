*Este proyecto ha sido creado como parte del currículo de 42 por jhannsil.*

---

## Descripción

**Libft** es el primer proyecto oficial del currículo principal de 42. El objetivo principal es reprogramar una serie de funciones estándar de la librería de C (`libc`), así como funciones adicionales que no están presentes en el sistema de forma nativa, para comprender a fondo el funcionamiento de la memoria, la manipulación de strings y la gestión de estructuras de datos básicas.


---

## Descripción detallada de la librería

La librería se compila como un archivo de archivo estático (`libft.a`) e incluye las siguientes categorías de funciones:

### 1. Funciones de la biblioteca estándar de C (`libc`)
Reimplementaciones de funciones clásicas con el prefijo `ft_`:
*   **Comprobación de caracteres:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`.
*   **Manipulación de caracteres:** `ft_toupper`, `ft_tolower`.
*   **Gestión de memoria:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`.
*   **Manipulación de strings:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`.

### 2. Funciones adicionales
Funciones que no pertenecen a la librería estándar o que se han adaptado para facilitar el desarrollo en C:
*   `ft_substr`: Extrae una subcadena de un string.
*   `ft_strjoin`: Concatena dos strings en una nueva zona de memoria.
*   `ft_strtrim`: Elimina caracteres específicos del principio y del final de un string.
*   `ft_split`: Divide un string en una matriz de strings utilizando un carácter delimitador.
*   `ft_itoa`: Convierte un número entero en un string.
*   `ft_strmapi` y `ft_striteri`: Aplican una función a cada carácter de un string.
*   `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`: Permiten escribir caracteres, strings o números en un descriptor de archivo específico.

### 3. Funciones de listas enlazadas
Funciones para manipular estructuras de datos de tipo lista enlazada simple (`t_list`):
*   `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

---
## 4. Recursos de Apoyo e Investigación

Para el desarrollo de este proyecto y la comprensión de la lógica de bajo nivel, se han utilizado tres fuentes de información clave:

1. **Manuales de Linux (`man`)**: Consulta directa en la terminal del campus (`man strlen`, `man memmove`, etc.) para comprobar los prototipos oficiales de la `libc`, el comportamiento de los parámetros y las especificaciones exactas del valor de retorno.
2. **Inteligencia Artificial (IA)**: Utilizada como tutor técnico interactivo para desatascar conceptos complejos, visualizar el movimiento de memoria en solapamientos (`ft_memmove`), revisar la gestión de punteros en listas enlazadas y corregir errores de desbordamiento en condiciones de bucles.
3. **Documentación Online**:
   * **Cplusplus.com / Cprogramming.com**: Referencia para ver ejemplos prácticos de funciones estándar.
   * **Python tutor**: Soporte visual para comprender linea a linea como se ejecuta el programa.
   * **Tutorialspoint**: Repaso teórico sobre la interacción del sistema operativo con los descriptores de archivo (`fd`).

## Instrucciones

### Requisitos previos
*   Compilador `cc` o `clang`.
*   Herramienta `make`.

### Compilación e Instalación
Para compilar la librería, clona el repositorio, navega a la raíz del proyecto y ejecuta uno de los siguientes comandos en la terminal:

```bash
# Compila las funciones obligatorias y genera libft.a
make

# Compila las funciones obligatorias más las funciones de listas enlazadas (Bonus)
make bonus

# Elimina los archivos objeto (.o) generados durante la compilación
make clean

# Elimina los archivos objeto y el archivo de la librería (libft.a)
make fclean

# Realiza una limpieza total y vuelve a compilar todo
make re
