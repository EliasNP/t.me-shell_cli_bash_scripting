[INICIO]({{ site.url }})  [ADMINISTRADORES]({{ site.admin }}) [EJERCICIOS]({{ site.ejer }}) [DOCUMENTACIÓN]({{ site.docu }}) [TUTORIALES]({{ site.tuto }}) [GRUPO DE TELEGRAM]({{ site.telegram }})

# EJERCICIO_2

## IMPORTANTE ANTES DE EMPEZAR
> Leed cuidadosamente las instruccionies del ejercicío ya que en el anterior habia gente que se saltaba cosas por leer diagonalmente. 😂😂😂



1. Vamos a crear un Archivo Generico con **variables y funciones** para los ejercicios que haremos de aqui en adelante.
Le llamaremos **.config** y tendremos que definir las siguientes **Variables** tal como se muestrán en los ejemplos de momento.

> Realmente le podeis poner el nombre que queraís pero tened en cuenta que mas adelante las llamaremos por lo que es conveniente que useís los mismos nombres para no liaros.

### CSS PARA ENRRIQUECER TEXTO CON COLORES Y SALTOS DE LINEA	

Negro, Grisoscuro, Azul, Azulclaro, Verde, Verdeclaro, Cyan, Cyanclaro, Rojo, Rojoclaro, Purpura, Purpuraclaro, Marron, Amarillo, Grisclaro, Blanco, nc

> Usaremos los valos standart para colores en "bash"

### DEFINICION DE VARIABLES GENERICAS FIJAS

La idea principal es que usemos unas **variables** que sean comunes para todos los ejercicios que preparemos en el futuro de momento definiremos estas que os propongo como ejemplo.

**_FECHA, HORA, USERID, IP, VERSION_SISTEMA, NOM_DISTRO_C, VERSION_BASH, NOMBRE_USUARIO_**

```bash
echo -e"
2020-05-29 - Muestra la fecha de hoy
17:43 - Muestra la hora actual
1000 - Muestra el Usuario
EliasNieva -  Nombre de Usuario creado por UID/GID (EJM. 1000) - VERSION SIMPLE
192.168.254.125 - Muestra la IP
19.3 (Tricia) -  Versión del Sistema Operativo
Linux Mint 19.3 -  Almacena el nombre corto de la Distro detectada.
4.4.20(1)-release -  Almacenar la Versión del Bash Shell."

```

### DEFINICIÓN DE FUNCIONES GENÉRICAS FIJAS

Al igual que las **variables** vamos a definir unas funciones a las que podremos llamar desde cualquier Script.
solamente a modo de Ejemplo crearemos una esta vez con nuestros datos para que aparezcan en todos los Scripts

Nombre de la function **_Data** con los siguientes datos 
- Titulo         :
- Descripción    :
- Autor          :
- Fecha          :
- Versión        :
- Notas          :       
- bash_version   :
- E-mail         :
- Telegram       :
- Mastodon       :
> Personalmente a mi me gusta Tabularlo para que queda más limpio, pero eso es una decisión personal

### SEGUNDO ARCHIVO.

 2. Crearemos un segundo **Script** con el nombre _Ejercicio\_2.sh_ en el cual llamaremos con el comando source (_NOTA: mirad bien como debe guardarse al final del texto_)por este orden a las funciones y Variables.

- Usando el comando **printf** y con los colores que hemos creado.

1. Función **_Data**, Azul
2. FECHA, Verde
3. HORA, Purpura
4. USERID,Cyan
5. IP, Rojoclaro
6. VERSION_SISTEMA, Blanco
7. NOM_DISTRO\_C,Marron
8. VERSION_BASH, Amarillo

- La ultima Variable NOMBRE\_USUARIO en Verdeclaro la sacaremos con _cowsay_
 ```
 _____________________________
< Asi Quedara:NOMBRE\_USUARIO >
 -----------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ```

Escaparemos el resultado del Script en un archivo en formato MarkDown, (si no sabéis no importa) podéis solamente sacarlo como _Ejercicio\_2.md_


Subiremos los dos archivos _Ejercicio\_2.sh_ y _Ejercicio\_2.md_ al SFTP del grupo que usasteis en el ejercicio anterior, a una nueva carpeta llamada Ejercicio\_2 el archivo **.config** a la carpeta de vuestro usuario raiz.

Voy a modificar las carpetas para que quede más organizado, la nueva estructura se detalla aquí abajo.

```bash 

SFTP>cd shell_Bash_Scripting/t.me-shell_cli_bash_scripting/Ejercicios/Usuarios/@Nombre_De_Usuario/
SFTP> ls
@Nombre_De_Usuario/:
	.config
	@Nombre_De_Usuario/Ejercicio_1:
		Ejercicio_1.md
		Ejercicio_1.out
		Ejercicio_1.sh
	@Nombre_De_Usuario/Ejercicio_2:
		Ejercicio_2.md
		Ejercicio_2.sh
```

# Cualquier Duda o pregunta como siempre por el Grupo.

## EJERCICIOS

- [EJERCICIO_1](Ejercicios/1_EJERCICIO.md) \_ [RESULTADO](Ejercicios/1_RESULTADO.md)
- [EJERCICIO_2](Ejercicios/2_EJERCICIO.md) \_ [RESULTADO](Ejercicios/2_RESULTADO.md)

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