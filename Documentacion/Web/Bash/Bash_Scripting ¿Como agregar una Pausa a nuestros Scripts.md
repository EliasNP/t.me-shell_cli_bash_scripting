# Bash_Scripting ¿Como agregar una _Pausa_ a nuestros Scripts?

Si alguno de vosotros alguna vez uso Scripts de DOS os sonara el comando **pause** , pues como sabéis en **Scripting** de **bash** no existe como tal, pero esto lo podemos solucionar fácilmente como detallo a continuación.

Con esto conseguiremos pausar nuestro proceso por lotes hasta que el usuario presione cualquier tecla, también veremos como pausar lo un determinado tiempo.

## Comando Bash _pause_ en Linux / UNIX / macOS

No hay un comando de pausa en el shell bash de Linux, pero podemos hacerlo fácilmente con el comando de lectura y la opción de lectura **-p** y mostrar un mensaje junto con la pausa.

En algunas distribuciones esto no funciona así que sacaremos un mensaje en pantalla con un **echo** y después el comando **read** con el nombre de una variable (Ej: _pausa_).

### Directamente en nuestro Script

Esto es tan simple como agregar las siguientes lineas a nuestro Script.

```bash
	## Bash agregamos la solicitud de pausa ## 
echo "Presione la tecla [Enter] para Continuar..." 
read pausa 
	## O por Ejemplo otra opción si nuestra distro lo permite ##
read -p "Presione cualquier tecla para reanudar ..." 
	## Bash agregue la solicitud de pausa durante 5 segundos ## 
echo "Voy esperar solo 5 segundos ... "	
read -t 5
```

Lo anterior suspenderá el procesamiento de un script de shell y mostrará un mensaje pidiéndole al usuario que presione la tecla [Enter] (o cualquier) para continuar. El último ejemplo esperará 5 segundos antes de ejecutar el siguiente comando (similar a **sleep 5**).

Otra de las opciones del comando **read** es la opción **-s** que evitara que nos devuelva por pantalla lo que escribamos.

### Metido en una _Función_

Declaramos la función la igual que lo hacemos en el Script directamente y luego la llamamos como se ve en el ejemplo, con lo que podremos llamarla siempre que queramos.

> NOTA: Si la metemos en un fichero general de funciones podremos llamarla desde cualquier Script solamente añadiendo al inicio del Script una llamada a dicho archivo de configuración (E: _source .config_ como en el ejercicio 2 que hemos realizado en nuestro grupo anteriormente)

```bash
function  _pause(){ 
 echo "Presione cualquier tecla para continuar..." 
 read -s -n 1
}
## Pausa ##
echo "Texto de ejemplo que nada tiene que ver antes de la Pausa"
_pasue  # Esto ejecutara la función en la parte del Script que nosotros queramos.
## resto del script a continuación
```

```bash
function _pause(){
   read  -s -p "$ *" 
}

# llame a la función _pausa
pausa 'Presione la tecla [Entrar] para continuar ...' # Esto ejecutara la función en la parte del Script que nosotros queramos.
## resto del script a continuación
```

También podemos jugar con variables dentro de la función para poder personalizarla cada vez que la llamemos .

```bash
function  _pause(){ 
 echo "$textoPausa" 
 read -t $time -s -n 1
}
## Pausa ##
echo "Texto de ejemplo que nada tiene que ver antes de la Pausa"
textoPausa="Texto 1 de Ejemplo Presione ENTER para continuar"
time=5 #Tiempo de esta primera pausa es de 5 segundos
_pasue  # Esto ejecutara la función en la parte del Script que nosotros queramos.

## resto del script a continuación

textoPausa="Texto 2 de Ejemplo: Press ENTER to continue"
time=10 #Tiempo de esta segunda pausa es de 10 segundos
_pasue  # Esto ejecutara la función en la parte del Script que nosotros queramos.

```

