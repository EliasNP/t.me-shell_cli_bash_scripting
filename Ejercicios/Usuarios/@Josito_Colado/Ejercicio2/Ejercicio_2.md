______________________________________________
				EJERCICIO_2
______________________________________________

### Creamos un archivo genérico con variables y funciones.
### El nombre del archivo es ".config" y lo guardamos en la raíz para poder llamarlo desde otros scripts (con el comando "source") que haremos mas adelante.

### En el archivo ".config", generamos las variables genéricas que serán fijas para que las podámos llamar al inicio de cualquier nuevo proyecto. Estas variables, hay algunas que ya son standard de BASH y van en mayusculas predecidas por "$", (Ej: $UID).
### Cuando queramos llamar a las variables que hemos creado desde el archivo ".sh", lo haremos precediendo el nombre de la variable con un "$" (Ej: $fecha). Esto nos devolverá el valor que le hemos asignado.

		fecha=`date +"%d/%m/%Y"`                        #Fecha de hoy
		hora=`date +"%H:%M"`                            #Hora actual
		userid=$UID                                     #Usuario
		ip=`hostname -I`                                #Muestra la IP
		version_sistema=`cat /etc/debian_version`       #Version S.O.
		nom_distro=`cat /etc/issue.net`                 #Distro del sistema
		version_bash=$BASH_VERSION                      #Versión Bash Shell
		nombre_usuario=`cowsay -f tux Josito`           #Usuario "con gracia"

### En este mismo archivo ".config", generamos también una función genérica fija la que le pondremos el color azul y se denominaremos "-Data".
### Al ponerle color, dejamos de usar el comando "echo" para usar el comando "printf".
### Para mas claridad de lectura, se ha combinado el color blanco.
### Al final de cada cadena le añadimos "\n" para que haga un sato de línea.
		
		function _Data(){
		
		printf "\033[1;34mTitulo:\e[0m""\033[1;37m Bash_Cli_Shell_Scripting\e[0m\n"
		printf "\033[1;34mDescripción:\e[0m""\033[1;37m  Mejorando lo presente\e[0m\n"
		printf "\033[1;34mAutor:\e[0m""\033[1;37m  Josito\e[0m\n"
		printf "\033[1;34mVersion:\e[0m""\033[1;37m  A.0.2 \e[0m\n"
		printf "\033[1;34mNotas:\e[0m""\033[1;37m       \e[0m\n"
		printf "\033[1;34mbash_version:\e[0m""\033[1;37m  5.0.3(1)-release\e[0m\n"
		printf "\033[1;34mE-mail:\e[0m""\033[1;37m  jcoladolafita(at)gmail(dot)com\e[0m\n"
		printf "\033[1;34mTelegram:\e[0m""\033[1;37m  @Josito_Colado\e[0m\n"
		
		}

### Depués crearemos el archivo "Ejercicio_2.sh".
### Donde usaremos el comando "source" para llamar al archivo ".config":

        source .config

### Luego llamamos también a la función fija nombrada "_Data".
### Como resultado, en la salida del programa nos aparecerán las líneas de tal función.

		_Data

### Seguidamente llamamos a los valores de las variables con "$" + "nombre de variable" y asignando colores diferentes a cada variable.

		printf "\033[32m$fecha\e[0m\n"
		printf "\033[35m$hora\e[0m\n"
		printf "\033[36m$userid\e[0m\n"
		printf "\033[1;31m$ip\e[0m\n"
		printf "\033[1;37m$version_sistema\e[0m\n"
		printf "\033[33m$nom_distro\e[0m\n"
		printf "\033[1;33m$BASH_VERSION\e[0m\n"
		printf "\033[1;32m$nombre_usuario\e[0m\n"

### FIN
