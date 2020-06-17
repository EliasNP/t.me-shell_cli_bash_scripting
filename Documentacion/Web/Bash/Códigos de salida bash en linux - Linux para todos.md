Códigos de salida bash en linux - Linux para todos

Códigos de salida bash en linux

![Códigos de salida bash en linux](../_resources/3afdfede01d8412cb89c583785d92a53.png "Códigos de salida bash en linux 1")

**Códigos de salida [bash](#) en [linux](#).**

Cada vez que ejecutamos un comando o script, el sistema nos devuelve un código de retorno. Si no lo solicitas explícitamente, este código no es visible.

Los **códigos de salida bash** son numéricos, pero limitados entre 0 y 255 porque se utiliza un entero de ocho bits. En este artículo vemos como imprimir los códigos de retorno, además de conocer los más comunes.

Para visualizar las salidas debes usar la siguiente sintaxis.

```bash
comando/script ; echo $?
```

Por ejemplo…

```bash
date ; echo $?
```

Como date se ejecutó correctamente, la salida es «0».

```bash
user@localhost ~  $ date ; echo $?
mar jun 16  20:35:02 EEST 2020
user@localhost ~ $ date ; echo $? mar jun 16 20:35:02 EEST 2020 0 user@localhost ~ $
user@localhost ~ $ date ; echo $?
mar jun 16 20:35:02 EEST 2020
0
user@localhost ~ $
```

Si ejecutamos un comando inexistente…

```bash
fallo ; echo $?
```

Nos devuelve el código 127, que nos indica comando no encontrado.

```bash
user@localhost ~  $ fallo ; echo $?
fallo: no se encontró la orden
user@localhost ~ $ fallo ; echo $? fallo: no se encontró la orden 127 user@localhost ~ $
user@localhost ~ $ fallo ; echo $?
fallo: no se encontró la orden
127
user@localhost ~ $
```

Para concluir podemos revisar la siguiente tabla, en ella encontrarás los códigos de salida más comunes.

| Código de salida | Significado | Varios |
| --- | --- | --- |
| 0   | Ejecución exitosa |     |
| 1   | Error general no definido | Por ejemplo dividir por cero |
| 2   | Mal uso de caracteres | Faltan comandos o argumentos |
| 126 | No se puede ejecutar | No es ejecutable, o necesitas permisos |
| 127 | Comando no encontrado | Falta la herramienta o tienes un error tipográfico |
| 128 | Argumento de salida no válido | Salida no comprendida entre 0 y 255 (enteros) |
| 128 +n | Error fatal |     |
| 130 | Terminado por "Control-C" |     |
| 255* | Código de salida fuera de rango | Solo enteros entre 0 y 255 |

