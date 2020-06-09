[INICIO]({{ site.url }})  [ADMINISTRADORES]({{ site.admin }}) [EJERCICIOS]({{ site.ejer }}) [DOCUMENTACIÓN]({{ site.docu }}) [TUTORIALES]({{ site.tuto }}) [GRUPO DE TELEGRAM]({{ site.telegram }})

#   RESULTADO EJERCICIO_2-1


La explicacion empieza aquí

```bash
#!/bin/bash

TITULO="EJERCICIO 2 DEL GRUPO"
DESCR="La Salida nos muestra la información almacenada en variables y funciones del archivo.config"
VERSION="A.0.2"
NOTAS="Nada que ver aquí"
# Llamada al fichero común de configuración 
source ../.config

#█████████████████████████████████████████████████████████$
#        DEFINICION DE VARIABLES                         #
#█████████████████████████████████████████████████████████$

_Logo
sleep 1
_Data

echo -e "Muestra la fecha de hoy"
printf "${Verdeclaro}$FECHA${nc}\n"

echo -e "Muestra la hora actual"
printf "${Purpura}$HORA${nc}\n"

echo -e "Muestra el ID Usuario"
printf "${Cyan}$USERID${nc}\n"

echo -e "Muestra la IP"
printf "${Rojoclaro}$IP${nc}\n"

echo -e " Versión del Sistema Operativo"
printf "${Blanco}$VERSION_SISTEMA${nc}\n"

echo -e " Almacena el nombre corto de la Distro detectada."
printf "${Marron}$NOM_DISTRO_C${nc}\n"

echo -e " Almacenar la Versión del Bash Shell."
printf "${Amarillo}$VERSION_BASH${nc}\n"

echo -e " Nombre de Usuario creado por UID/GID (EJM. 1000) - VERSION SIMPLE"
printf "${Verde}"
cowsay "$NOMBRE_USUARIO"
printf "${nc}\n"
```

Resultado Final de Como Debería Quedar.
![](2_RESULTADO.png)

<img src="../nover.jpg" title="NADA QUE VER, ESTOS NO SON LOS RESULTADOS QUE BUSCAIS" style="zoom:150%;" />

------
<center>
<a href="{{ site.twitter }}"><img src="{{ site.img_telegram }}" alt="Telegram"/></a>
<a href="{{ site.twitter }}"><img src="{{ site.img_twitter }}" alt="Twitter"/></a>
<a href="{{ site.mastodon }}"><img src="{{ site.img_mastodon }}" alt="Mastodon"/></a>
<a href="{{ site.github }}"><img src="{{ site.img_github }}" alt="GitHub"/></a>
<a href="{{ site.mail }}"><img src="{{ site.img_mail }}" alt="E-mail"/></a>
<Br>
<a href="{{ site.mail }}"><img src="{{ site.img_creative }}" alt="cc"/></a>
</center>
------