[INICIO]({{ site.url }})  [ADMINISTRADORES]({{ site.admin }}) [EJERCICIOS]({{ site.ejer }}) [DOCUMENTACIÓN]({{ site.docu }}) [TUTORIALES]({{ site.tuto }}) [GRUPO DE TELEGRAM]({{ site.telegram }})

#   RESULTADO EJERCICIO_2

## Procedimiento

Aquí voy a detallar mi proceso, no es la única forma pero si la más clara a mi entender.

Voy a dividir este Resultado en 2 Partes para hacerlo más legible y no crear confusión 

1. Creación de Fichero **.config** En esta pagnina
2. Creación de script **Ejercicio_2.sh** [Sigguiente  pagina](2-2_RESULTADO.md)

Cualquier aclaración y/o comentario como siempre es bienvenido.

### Creación fichero de Configuración ".config"

Lo primero es crear nuestro archivo que va a contener las variables y funciones genéricas.
> Uso **nano** por comodidad para este ejercicio pero vale cualquier editor.

```bash 
$:>nano .config
```
Una vez dentro  insertamos como siempre _#!/bin/bash_
y empezamos a definir nuestras variables (yo, también inserto comentarios para facilitar mi propia lectura posterior.)

### Códigos de Colores Scripting (CSS)

Primero introducimos el nombre que le vamos a dar a la variable para los colores Ej: **Negro** y continuamos con **=** más la cadena de escape que se usa para controlar el cursor de la consola y el color del texto, entre otras cosas **\033[** y  el código de color según la tabla siempre encerrado entre quotes **" "**: 

| Negro      | 0;30 | Gris oscuro   | 1;30 |
| ---------- | ---- | ------------- | ---- |
| Azul       | 0;34 | Azul claro    | 1;3  |
| Verde      | 0;32 | Verde claro   | 1;32 |
| Cyan       | 0;36 | Cyan claro    | 1;36 |
| Rojo       | 0;31 | Rojo claro    | 1;31 |
| Púrpura    | 0;35 | Púrpura claro | 1;35 |
| Marron     | 0;33 | Amarillo      | 1;33 |
| Gris claro | 0;37 | Blanco        | 1;37 |

> Si queréis saber más sobre cadenas de escape y/o colores ved esta Wiki (https://en.wikipedia.org/wiki/ANSI_escape_code#Escape_sequences)

```bash
# Bash css! (Cadena de escape + Color +m) Ejemplo separado para entender: \033[ + 0;30 + m
Negro="\033[0;30m"
Grisoscuro="\033[1;30m"
Azul="\033[0;34m"
Azulclaro="\033[1;34m"
Verde="\033[0;32m"
Verdeclaro="\033[1;32m"
Cyan="\033[0;36m"
Cyanclaro="\033[1;36m"
Rojo="\033[0;31m"
Rojoclaro="\033[1;31m"
Purpura="\033[0;35m"
Purpuraclaro="\033[1;35m"
Marron="\033[0;33m"
Amarillo="\033[1;33m"
Grisclaro="\033[0;37m"
Blanco="\033[1;37m"
nc="\033[0m"
```

### Definición de Funciones

Despúes de las variables de Color (CSS), introducimós las funciones empezando por la de información:

1. Llamamos a la Función y la nominamos **function _Data(){**

2. Introducimos los datos que queramos sacar por pantalla con **printf "** más el color desde las variables creadas en el punto anterior **${Blanco}** el texto que queremos que aparezca, **Titulo :$TITULO ** y terminamos matando el color devolviéndolo al color original de la consola y al usar **printf** incluimos un salto de linea **${nc}\n"**, note se que este caso yo incluyo (*aunque no se pedía en el ejercicio* ) una variable **$TITULO**, esto me permite usar la misma función en todos los Scripts que haga en el futuro ya que como veremos más adelante este archivo genérico de configuración nos valdrá para muchas cosas chulas.

3. En este caso como los que queremos sacar si va a ser genérico lo introduzco directamente para poder cambiarlo unicamente en un solo sitio si en el futuro cambio algo. **printf "${Azul} Autor :Elías Nieva${nc}\n"**

4. Y así sucesivamente con todos los textos que quiera que aparezcan y al final cierro la función con **}**

```bash
   function _Data(){
   printf "${Azul} ================================================================${nc}\n"
   printf "${Blanco}Titulo 			    :$TITULO ${nc}\n"
   printf "${Amarillo}Descripción    :$DESCR ${nc}\n"
   printf "${Azul} Autor          :Elías Nieva${nc}\n"
   printf "${Azul} bash_version   :4.4.20(1)-release${nc}\n"
   printf "${Blanco}Versión		 	:$VERSION ${nc}${nc}\n"
   printf "${Azul} E-mail         :eliasnievap(at)protonmail(dot)com${nc}\n"
   printf "${Azul} Telegram       :@EliasNieva${nc}\n"
   printf "${Azul} Mastodon       :@EliasNieva@mastodon.social${nc}\n"
   printf "${Amarillo}Descripción   :$NOTAS ${nc}\n"
   printf "${Azul} ================================================================${nc}\n"
   }
```

Como veréis al final de este pagina yo incluyo una función Llamada **function _Logo**, que no se pedía en el ejercicio pero os la dejo para que veáis como puedes incluir más funciones y llamarlas a modo de ejemplo.

### Definición de Variables

Ahora vamos a definir las variables que podremos llamar para darnos información del sistema en futuros _Scripts_, se pueden llamar usando otras variables que el sistema ya incorpora en algunas pondré la opción corta pero como aquí se trata de aprender principalmente, os pongo la solución larga.

#### La fecha 

```bash
FECHA=`date +%Y-%m-%d`
FECHA="$(date '+%F')" # Esta tambien valdria si usaís el formato americano de fecha  ya que devuelve "2020-06-08"
```
#### La Hora 

```bash
HORA=`date +%H:%M`
```
####  UID o numero de usuario

```bash
USERID=`id -g`
USERID=`$UID` #Este es otra opción usando las variables internas del sistema 
```
####  Nombre de Usuario

Con esta variable vamos a usar lo aprendido con el **grep** y el **cut** aunque siempre podemos usar la variable de Sistema **$USER** que seria más fácil, pero como siempre digo es mejor saber de donde vienen las cosas.

- Primero hacemos un **cat** al fichero de usuarios ** /etc/passwd**
- Le pasamos el Resultado al **grep** para que nos busque el **UID** definido en la variable anterior de nuestro usuario.
- Después le pasamos la linea que contiene nuestro **UID** y la cortamos con **cut** para que se quede con la primera palabra antes del separador **:**

```bash
NOMBRE_USUARIO=$(cat /etc/passwd | grep $USERID | cut -d: -f1)
```

####  IP interna de nuestra tarjeta de red.

- Hacemos una llamada al Comando **hostname** y le pasamos la opción **-I** para que nos muestre la dirección IP de nuestra tarjeta de red
```bash
IP=\`hostname -I`
```
- Pero si teneos más de una Tarjeta de red tendremos que acotar esta información con un **cut** y elegir la que queremos y así asignar cada una a una variable diferente. Ejemplo:
```bash
IP1=\`hostname -I  | cut -d " " -f1\` # Esto nos da la 1ra IP
IP2=\`hostname -I  | cut -d " " -f2\` # Esto nos da la 2da IP
```
### La Versión del Sistema

Aqui nos vamos a basar en el Fichero **/etc/os-release ** el cual si lo listamos nos da mucha info de nuestra distribución pero como solo queremos la **versión** lo vamos a acotar usando **grep** y **sed**

- Primero hacemos un **cat** del archivo como deciamos "cat /etc/os-release"
- Seguido Pasamos esta info con un _pipeline_ por el **grep**
	```bash
	$:>cat /etc/os-release | grep VERSION= 
	VERSION="19.3 (Tricia)"
	$:>
	```
- Pero esto nos deja la linea completa así que eliminamos lo que no queremos con **sed**
- Eliminamos el Texto **VERSION=** añadiendo ```bash | sed 's/VERSION=//' ```
- Y Seguimos eliminando las quotes **" "** con ```bash | sed 's/"//g' ```
- lo que nos dejara como resultado solo el nombre de la versión y el numero así que lo incluimos todo junto en la variable como se muestra a continuación.

```bash
VERSION_SISTEMA=$(cat /etc/os-release | sed -n '1p' | sed 's/VERSION=//' | sed 's/"//g')
```

#### Nombre de la Distribución

Aquí hay varias soluciones en función de vuestra distro, pero al igual que las anteriores básicamente listamos el archivo que contiene la info y después acotamos y limpiamos lo que queremos que nos muestre.

```bash
NOM_DISTRO_C=$(cat /etc/os-release | grep NAME | grep -v "VERSION" | sed -n '2p' | cut -f2 -d\" | awk '{print $1}')
NOM_DISTRO_C=$(lsb_release -d | sed 's/Description://' | awk '{print $1}')
NOM_DISTRO_C=$(cat /etc/os-release | grep NAME | grep -v "VERSION" | sed -n '2p' | cut -f2 -d\")
```

#### Versión de BASH

Para no repetirme demasiado esta vez vamos a usar las salidas por defecto haciendo un **bash --version** acotando a la frase que quiete el numero de versión con **grep bash** y seleccionando solo la 4 palabra con **awk \'{print $4}\' **

```bash
VERSION_BASH=$(bash --version | grep bash | awk '{print $4}') 
```

### Notas Finales

Así quedaría lo que se pide en el ejercicio, pero por supuesto se podrían añadir tantas funciones  variables como queramos.

Continuación con la creación de Script **Ejercicio_2.sh** [Siguiente  pagina](2-2_RESULTADO.md)

Os dejo mi Script completo aquí para que lo veáis a modo de resumen.

## Script Completo

```bash

​```bash
#!/bin/bash

#░░▒▒▒▓▓▓▓███████████████████████████████████████████████████████████████████████████████████████████████████████████$
#				CSS PARA ENRRIQUECER TEXTO CON COLORES Y SALTOS DE LINEA			
#░░▒▒▒▓▓▓▓███████████████████████████████████████████████████████████████████████████████████████████████████████████$

# Bash css! ( Cadena de escape + Color +m ) Ejemplo separado para entender: \033[ + 0;30 + m
Negro="\033[0;30m"
Grisoscuro="\033[1;30m"
Azul="\033[0;34m"
Azulclaro="\033[1;34m"
Verde="\033[0;32m"
Verdeclaro="\033[1;32m"
Cyan="\033[0;36m"
Cyanclaro="\033[1;36m"
Rojo="\033[0;31m"
Rojoclaro="\033[1;31m"
Purpura="\033[0;35m"
Purpuraclaro="\033[1;35m"
Marron="\033[0;33m"
Amarillo="\033[1;33m"
Grisclaro="\033[0;37m"
Blanco="\033[1;37m"
nc="\033[0m"


#█████████████████████████████████████████████████████████$
#        DEFINICION DE FUNCIONES GENERICAS FIJAS          #
#█████████████████████████████████████████████████████████$

function _Data(){
printf "${Azul} ================================================================${nc}\n"
printf "${Blanco}Titulo 			    :$TITULO ${nc}\n"
printf "${Amarillo}Descripción    :$DESCR ${nc}\n"
printf "${Azul} Autor          :Elías Nieva${nc}\n"
printf "${Azul} bash_version   :4.4.20(1)-release${nc}\n"
printf "${Blanco}Versión		 	:$VERSION ${nc}${nc}\n"
printf "${Azul} E-mail         :eliasnievap(at)protonmail(dot)com${nc}\n"
printf "${Azul} Telegram       :@EliasNieva${nc}\n"
printf "${Azul} Mastodon       :@EliasNieva@mastodon.social${nc}\n"
printf "${Amarillo}Descripción   :$NOTAS ${nc}\n"
printf "${Azul} ================================================================${nc}\n"
}

##============================================================================@

function _Logo(){
printf "\033[1;34m ============================================================================@\e[0m\n"
printf "\033[1;34m                      ═══════════════════════════════════\e[0m\n"
printf "\033[1;34m                      ║█████████████████████████████████║\e[0m\n"
printf "\033[1;34m                      ║██╔═══╦╗███████╔═╗█╔╗████████████║\e[0m\n"
printf "\033[1;34m                      ║██║╔══╣║███████║║╚╗║║████████████║\e[0m\n"
printf "\033[1;34m                      ║██║╚══╣║╔╦══╦══╣╔╗╚╝╠╦══╦╗╔╦══╗██║\e[0m\n"
printf "\033[1;34m                      ║██║╔══╣║╠╣╔╗║══╣║╚╗║╠╣║═╣╚╝║╔╗║██║\e[0m\n"
printf "\033[1;34m                      ║██║╚══╣╚╣║╔╗╠══║║█║║║║║═╬╗╔╣╔╗║██║\e[0m\n"
printf "\033[1;34m                      ║██╚═══╩═╩╩╝╚╩══╩╝█╚═╩╩══╝╚╝╚╝╚╝██║\e[0m\n"
printf "\033[1;34m                      ║█████████████████████████████████║\e[0m\n"
printf "\033[1;34m                      ═══════════════════════════════════\e[0m\n"
printf "\033[1;34m                         -----------------------\e[0m\n"
printf "\033[1;34m                        https://EliasNp.github.io\e[0m\n"
printf "\033[1;34m ============================================================================@\e[0m\n"
}

#█████████████████████████████████████████████████████████$
#        DEFINICION DE VARIABLES GENERICAS FIJAS          #
#█████████████████████████████████████████████████████████$

FECHA=`date +%Y-%m-%d`
HORA=`date +%H:%M`
USERID=`id -g`
NOMBRE_USUARIO=$(cat /etc/passwd | grep $USERID | cut -d: -f1)
IP=`hostname -i  | cut -d " " -f1`
VERSION_SISTEMA=$(cat /etc/os-release | grep VERSION= | sed -n '1p' | sed 's/VERSION=//' | sed 's/"//g')
NOM_DISTRO_C=$(cat /etc/os-release | grep NAME | grep -v "VERSION" | sed -n '2p' | cut -f2 -d\")
VERSION_BASH=$(bash --version | grep bash | awk '{print $4}') 

```

------
<center>
<a href="https://t.me/shell_cli_bash_scripting"><img src="{{ site.img_telegram }}" alt="Telegram"/></a>
<a href="https://twitter.com/EliasNieva"><img src="{{ site.img_twitter }}" alt="Twitter"/></a>
<a href="https://mastodon.social/@EliasNieva"><img src="{{ site.img_mastodon }}" alt="Mastodon"/></a>
<a href="https://github.com/EliasNP"><img src="{{ site.img_github }}" alt="GitHub"/></a>
<a href="mailto:eliasnievap@protonmail.com"><img src="{{ site.img_mail }}" alt="E-mail"/></a>
<Br>
<a href="mailto:eliasnievap@protonmail.com"><img src="{{ site.img_creative }}" alt="cc"/></a>
</center>
------

