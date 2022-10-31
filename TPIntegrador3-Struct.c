#include <stdio.h>
#include <stdlib.h>

/*LC1 - Ejercicio Integrador 3
Deseamos realizar un programa que gestione las notas de una clase de 10 alumnos de los
cuales sabemos el DNI y la nota. El programa debe mostrar un menú con las siguientes
opciones a resolver:
1. Cargar Alumnos
2. Buscar un alumno
3. Modificar la nota de un alumno
4. Mostrar un listado de los 10 alumnos
5. Salir

SÓLO se saldrá de la aplicación si se selecciona la opción 5.
*/

struct Alumno
{
    int dni;
    float nota;
};



void main()
{
int opc;
int tam = 2;
int dni1;
float nota1;
int validar;

struct Alumno alumnos[tam];

do
{
    printf ("1. Cargar Alumnos\n");
    printf ("2. Buscar un alumno\n");
    printf ("3. Modificar la nota de un alumno\n");
    printf ("4. Mostrar un listado de los 10 alumnos\n");
    printf ("5. Salir\n");
    scanf ("%i",&opc);
    while (opc < 1 || opc > 5)
    {
        printf ("Ingreso un numero incorrecto\n");
        scanf ("%i",&opc);
    }     
    
    switch (opc)
    {
    case 1:
        
        for (int i = 0; i < tam; i++)
        {
            printf ("Ingrese dni del alumno %i\n",i+1);
            scanf ("%i",&dni1);
            while (dni1<1000000 || dni1>99999999)
            {
                printf ("Dni invalido ingrese nuevamente\n");
                scanf ("%i",&dni1);
            }
            alumnos[i].dni=dni1;
            printf ("Ingrese nota\n");
            scanf ("%f",&nota1);
            while (nota1<1 || nota1>10)
            {
                printf ("Nota invalida ingrese nuevamente\n");
                scanf ("%f",&nota1);
            }
            alumnos[i].nota=nota1;

        }
        
        break;
    case 2:
      
            do
            {
            printf ("Ingrese dni\n");
            scanf ("%i",&dni1);
            validar = 0;
            for (int i = 0; i < tam; i++)
            {
                if (dni1 == alumnos[i].dni)
                {
                    printf ("Dni: %i , Nota: %.2f\n",dni1 ,alumnos[i].nota );
                }
                else
                {
                    validar = validar + 1;
                }
            }
            if (validar == tam)
            {
                printf ("Dni inexistente, vuelva a ingresar\n");
            }
            } while (validar == tam); 
            
        break;
    case 3:
           do
            {
            printf ("Ingrese dni\n");
            scanf ("%i",&dni1);
            validar = 0;
            for (int i = 0; i < tam; i++)
            {
                if (dni1 == alumnos[i].dni)
                {
                    printf ("Ingrese nueva nota\n");
                    scanf ("%f",&nota1);
                    while (nota1<1 || nota1>10)
                    {
                        printf("Nota invalida ingrese nuevamente\n");
                        scanf("%f", &nota1);
                    }
                    printf ("Nota cambiada con exito\n");
                    alumnos[i].nota = nota1;
                }
                else
                {
                    validar = validar + 1;
                }
            }
            if (validar == tam)
            {
                printf ("Dni inexistente, vuelva a ingresar\n");
            }
            } while (validar == tam);  
        break;
    case 4:
        for (int i = 0; i < tam; i++)
        {
            printf ("DNI: %i | NOTA: %.2f\n",alumnos[i].dni,alumnos[i].nota);
        }
        
        break;        
    case 5:
        break;
    }

} while (opc != 5);
system("pause");

}