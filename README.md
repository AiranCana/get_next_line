*Este proyecto ha sido creado como parte del currículo de 42 por acanadil.*

# 📄 get_next_line

## 📌 Descripción

El objetivo de este proyecto es implementar la función `get_next_line`, que permite leer una línea completa desde un descriptor de archivo (`file descriptor`) cada vez que es llamada.

Este proyecto introduce el uso de **variables estáticas en C**, permitiendo conservar información entre llamadas a una función, y enseña a gestionar correctamente la memoria dinámica y la lectura incremental de archivos mediante la función `read()`.

La función devuelve la siguiente línea del archivo, incluyendo el carácter `\n` si existe, o `NULL` cuando no hay más líneas que leer o se produce un error.

---

## ⚙️ Instrucciones

### 🧩 Archivos del proyecto

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

### 🛠️ Compilación

La función debe compilarse junto a tus archivos fuente, definiendo el tamaño del buffer mediante la macro `BUFFER_SIZE`:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

---

## 📚 Recursos

Durante el desarrollo de este proyecto se han utilizado los siguientes recursos:

- 📄 Man pages

	```bash
	man 2 read
	man 3 malloc
	man 3 free
	```
- 🧠 Variables estáticas en C:

       https://es.wikipedia.org/wiki/Variable_est%C3%A1tica
