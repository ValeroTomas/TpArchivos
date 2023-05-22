#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
} stAlumno;

stAlumno cargarAlumno();
int abrirArchivo(FILE *alumnos);
void alumnoArchivo(FILE *alumnos);
void leerArchivo(FILE *alumnos);
int main()
{
    FILE *alumnos;
    abrirArchivo(alumnos);
    alumnoArchivo(alumnos);
    leerArchivo (alumnos);
}

int abrirArchivo(FILE *alumnos)
{
    int flag = 1;
    alumnos = fopen("datosAlumno.bin", "ab");
    if(alumnos == NULL)
    {
        printf("Error en el archivo");
        exit(1);
        flag = 0;
    }
    printf("Se abrio");
    fclose(alumnos);
    return flag;
}

stAlumno cargarAlumno()
{
    stAlumno alumno;
    int flag = 0;

    printf("\nIngrese el nombre y apellido (maximo 30 caracteres): \n");
    fflush(stdin);
    gets(alumno.nombreYapellido);
    printf("\nIngrese legajo:\n");
    fflush(stdin);
    scanf("%d", &alumno.legajo);
    printf("\nIngrese edad:\n");
    fflush(stdin);
    scanf("%d", &alumno.edad);
    printf("\nIngrese anio:\n");
    fflush(stdin);
    scanf("%d", &alumno.anio);
    return alumno;
}

void alumnoArchivo(FILE *alumnos)
{
    stAlumno alumno;
    if(abrirArchivo(alumnos) == 1)
    {
        alumnos = fopen("datosAlumno.bin", "ab");
        alumno = cargarAlumno();
        fwrite(&alumno, sizeof(stAlumno), 1, alumnos);
        fclose(alumnos);
    }
}

void leerArchivo(FILE *alumnos)
{

    stAlumno alumno;

    alumnos = fopen("datosAlumno.bin", "rb");
    if (alumnos!= NULL)
    {
        while(!feof(alumnos))
        {
            fread(&alumno, sizeof(stAlumno),1, alumnos);
            if(!feof(alumnos))
            {
                printf ("LEGAJO: %i\n", alumno.legajo);
                printf ("NOMBRE: %s\n", alumno.nombreYapellido);
                printf ("EDAD: %i\n", alumno.edad);
                printf ("ANIO: %i\n", alumno.anio);
            }

        }
        fclose(alumnos);
    }
    else
    {
        printf ("EL ALUMNO NO EXISTE\n");
    }


}
