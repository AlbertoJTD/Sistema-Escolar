#include <stdio.h>
#include <stdlib.h>

struct fecha {
  int dia;
  int mes;
  int anio;
};

struct persona {
  char nombre[60];
  char apellidoP[50];
  char apellidoM[50];
  int edad;
  fecha nacimiento;
  char genero[10];
};

struct materia {
  char nombreMateria[60];
  float calificacion;
};

struct kardex {
  int numMaterias=7;
  materia mate[7];
  float promedioGeneral;
};

struct bachiller {
  char nombreBachiller[100];
  fecha inicioCurso;
  fecha terminoCurso;
  float promedioFinal;
};

struct universidad {
  char nombreUniversidad[100];
  char nombreCarrera[100];
  int matricula;
  persona tutor;
  persona alumno;
  int cuatrimestre;
  kardex cargaAcademica;
  bachiller certificado;
};


void registrarAlumno(universidad uni[], int n, int ma){
  for(int i=0; i<n; i++){
    fflush( stdin );
    printf("\n\nNombre de la universidad: ");
    gets(uni[i].nombreUniversidad);
    fflush( stdin );

    printf("Nombre de la carrera: ");
    gets(uni[i].nombreCarrera);//Recibe la cadena en donde se almacena el valor
    fflush( stdin );

    printf("Cuatrimestre: ");
    scanf("%i", &uni[i].cuatrimestre);


    printf("\n\n------------ Datos Tutor ------------\n" );
    fflush( stdin );
    printf("Nombre: ");
    gets(uni[i].tutor.nombre);
    fflush( stdin );

    printf("Apellido paterno: ");
    scanf(" %s",&uni[i].tutor.apellidoP);
    fflush( stdin );

    printf("Apellido materno: ");
    scanf(" %s",&uni[i].tutor.apellidoM);
    fflush( stdin );

    printf("Edad: ");
    scanf("%i",&uni[i].tutor.edad);

    printf("\n-- Fecha de nacimiento --\n");
    printf("Dia: ");
    scanf("%i",&uni[i].tutor.nacimiento.dia);

    printf("Mes: ");
    scanf("%i",&uni[i].tutor.nacimiento.mes);

    printf("Anio: ");
    scanf("%i",&uni[i].tutor.nacimiento.anio);

    fflush( stdin );
    printf("Genero: ");
    scanf(" %s", &uni[i].tutor.genero);


    printf("\n\n------------ Datos Alumno ------------\n" );
    uni[i].matricula=ma;
    printf("\nMatricula: %i\n",uni[i].matricula);
    fflush( stdin );

    fflush( stdin );
    printf("Nombre: ");
    gets(uni[i].alumno.nombre);
    fflush( stdin );

    printf("Apellido paterno: ");
    scanf(" %s",&uni[i].alumno.apellidoP);
    fflush( stdin );

    printf("Apellido materno: ");
    scanf(" %s",&uni[i].alumno.apellidoM);
    fflush( stdin );

    printf("Edad: ");
    scanf("%i",&uni[i].alumno.edad);

    printf("\n-- Fecha de nacimiento --\n");
    printf("Dia: ");
    scanf("%i",&uni[i].alumno.nacimiento.dia);

    printf("Mes: ");
    scanf("%i",&uni[i].alumno.nacimiento.mes);

    printf("Anio: ");
    scanf("%i",&uni[i].alumno.nacimiento.anio);

    fflush( stdin );
    printf("Genero: ");
    scanf(" %s", &uni[i].alumno.genero);


    printf("\n\n------------ Carga academica ------------\n" );
    fflush( stdin );
    printf("Numero de materias cargadas:  %i\n",uni[i].cargaAcademica.numMaterias);

    float calif;
    bool valor;
    for (int x = 0; x < 7; x++) {
      valor=false;
      printf("-- Materia %i --\n",x+1);
      printf("Nombre de la materia:");
      gets(uni[i].cargaAcademica.mate[x].nombreMateria);
      fflush( stdin );

      do{
        printf("Calificacion de la materia:");
        scanf("%f",&calif);
        if(calif >= 0 && calif<=10){
          uni[i].cargaAcademica.mate[x].calificacion=calif;
          valor = true;
        }else{
          printf("Error: La calificacion debe ser entre 0-10\n");
        }
      }while(valor == false);

      fflush( stdin );
      printf("\n");
    }

    float suma=0;
    for (int x = 0; x < 7; x++) {
      suma=suma+uni[i].cargaAcademica.mate[x].calificacion;
    }
    suma=suma/7;
    uni[i].cargaAcademica.promedioGeneral=suma;

    printf("Promedio general: %.2f\n",uni[i].cargaAcademica.promedioGeneral);


    printf("\n\n------------ Datos de certificado bachiller ------------\n" );
    fflush( stdin );
    printf("Nombre del bachiller:");
    gets(uni[i].certificado.nombreBachiller);

    printf("\n-- Fecha de inicio de curso --\n");
    printf("Dia: ");
    scanf("%i",&uni[i].certificado.inicioCurso.dia);

    printf("Mes: ");
    scanf("%i",&uni[i].certificado.inicioCurso.mes);

    printf("Anio: ");
    scanf("%i",&uni[i].certificado.inicioCurso.anio);

    printf("\n-- Fecha de termino de curso --\n");
    printf("Dia: ");
    scanf("%i",&uni[i].certificado.terminoCurso.dia);

    printf("Mes: ");
    scanf("%i",&uni[i].certificado.terminoCurso.mes);

    printf("Anio: ");
    scanf("%i",&uni[i].certificado.terminoCurso.anio);

    printf("\n-- Promedio final --\n");
    printf("Promedio obtenido: ");
    scanf("%f",&uni[i].certificado.promedioFinal);

    ma++;
  }
}

void mostrarAlumnos(universidad uni[], int n){
  printf("\n\n------------ Alumnos ------------\n" );
  for(int i=0; i<n; i++){
    printf("-- Alumno %i --",i+1);
    printf("\nMatricula: %i",uni[i].matricula);
    printf("\nCuatrimestre: %i",uni[i].cuatrimestre);
    printf("\nCarrera: %s",uni[i].nombreCarrera);
    printf("\nGenero: %s",uni[i].alumno.genero);
    printf("\nNombre: %s",uni[i].alumno.nombre);
    printf("\nApellido paterno: %s",uni[i].alumno.apellidoP);
    printf("\nApellido materno: %s",uni[i].alumno.apellidoM);
    printf("\nEdad: %i",uni[i].alumno.edad);
    printf("\n" );
  }
}

void mostrarTutores(universidad uni[], int n){
  printf("\n\n------------ Tutores ------------\n" );
  for(int i=0; i<n; i++){
    printf("-- Tutor %i --",i+1);
    printf("\nGenero: %s",uni[i].tutor.genero);
    printf("\nNombre: %s",uni[i].tutor.nombre);
    printf("\nApellido paterno: %s",uni[i].tutor.apellidoP);
    printf("\nApellido materno: %s",uni[i].tutor.apellidoM);
    printf("\nEdad: %i",uni[i].tutor.edad);
    printf("\n");
  }
}

void modificarAlumno(universidad uni[], int n, int op2, int matri){
  bool valor=false;
  bool existe=false;

  for (int i = 0; i < n; i++) {
    if(uni[i].matricula == matri){
      existe=true;
    }
  }
  fflush( stdin );

  if(existe == true){
      //Nombre
      if(op2 == 1){
        for (int i = 0; i < n; i++) {
          if(uni[i].matricula == matri){
            printf("Teclea el nuevo nombre para %s: ",uni[i].alumno.nombre);
            gets(uni[i].alumno.nombre);
            fflush( stdin );
            valor=true;
          }
        }

        if(valor == true){
          printf("Se ha cambio el nombre con exito\n");
        }else{
          printf("No se pudo cambiar el nombre\n");
        }


      //apellido paterno
      }else if(op2 == 2){
        for (int i = 0; i < n; i++) {
          if(uni[i].matricula == matri){
            printf("Teclea el apellido paterno de %s: ",uni[i].alumno.nombre);
            gets(uni[i].alumno.apellidoP);
            fflush( stdin );
            valor=true;
          }
        }

        if(valor == true){
          printf("Se ha cambio el apellido paterno con exito\n");
        }else{
          printf("No se pudo cambiar el apellido paterno\n");
        }


      //apellido materno
      }else if(op2 == 3){
        for (int i = 0; i < n; i++) {
          if(uni[i].matricula == matri){
            printf("Teclea el apellido materno de %s: ",uni[i].alumno.nombre);
            gets(uni[i].alumno.apellidoM);
            fflush( stdin );
            valor=true;
          }
        }

        if(valor == true){
          printf("Se ha cambio el apellido materno con exito\n");
        }else{
          printf("No se pudo cambiar el apellido materno\n");
        }


      //edad
      }else if(op2 == 4){
        for (int i = 0; i < n; i++) {
          if(uni[i].matricula == matri){
            printf("Teclea la edad de %s: ",uni[i].alumno.nombre);
            scanf("%i",&uni[i].alumno.edad);
            fflush( stdin );
            valor=true;
          }
        }

        if(valor == true){
          printf("Se ha cambio la edad con exito\n");
        }else{
          printf("No se pudo cambiar la edad\n");
        }


      //fecha de nacimiento
      }else if(op2 == 5){
        for (int i = 0; i < n; i++) {
          if(uni[i].matricula == matri){
            printf("Fecha de nacimiento de %s\n",uni[i].alumno.nombre);
            printf("Dia: ");
            scanf("%i",&uni[i].alumno.nacimiento.dia);

            printf("Mes: ");
            scanf("%i",&uni[i].alumno.nacimiento.mes);

            printf("Anio: ");
            scanf("%i",&uni[i].alumno.nacimiento.anio);

            fflush( stdin );
            valor=true;
          }
        }

        if(valor == true){
          printf("Se ha cambio la fecha de nacimiento con exito\n");
        }else{
          printf("No se pudo cambiar la fecha de nacimiento\n");
        }


      //actualizar calificaciones
    }else if(op2 == 6){

        int op;
        float calif;
        for (int i = 0; i < n; i++) {
          if(uni[i].matricula == matri){
            for (int x = 0; x < 7; x++) {
              valor=false;
              printf("\n-- Materia %i --\n",x+1);
              printf("La materia es: %s \n",uni[i].cargaAcademica.mate[x].nombreMateria);
              printf("La calificacion es: %f \n",uni[i].cargaAcademica.mate[x].calificacion);

              printf("Desea actualizar la calificacion de la materia %s? 1.- Si  2.- No --> ",uni[i].cargaAcademica.mate[x].nombreMateria);
              scanf("%i",&op);
              if(op == 1){
                do{
                  printf("Calificacion de la materia:");
                  scanf("%f",&calif);
                  if(calif>=0 && calif<=10){
                    uni[i].cargaAcademica.mate[x].calificacion=calif;
                    valor = true;
                  }else{
                    printf("Error: La calificacion debe ser entre 0-10\n");
                  }
                }while(valor == false);
              }
              printf("\n");
            }

            float suma=0;
            for (int x = 0; x < 7; x++) {
              suma=suma+uni[i].cargaAcademica.mate[x].calificacion;
            }
            suma=suma/7;
            uni[i].cargaAcademica.promedioGeneral=suma;

          }
        }

        fflush( stdin );
        printf("\n");


      //materias y calificaciones
      }else  if(op2 == 7){
        for (int i = 0; i < n; i++) {
            if(uni[i].matricula == matri){
              printf("\nMaterias del alumno: %s",uni[i].alumno.nombre);

              for (int x = 0; x < 7; x++) {
                printf("\n-- Materia %i --\n",x+1);
                printf("Materia: %s \n",uni[i].cargaAcademica.mate[x].nombreMateria);
                printf("Calificacion: %.2f \n",uni[i].cargaAcademica.mate[x].calificacion);
            }
            printf("Promedio general: %2.f\n",uni[i].cargaAcademica.promedioGeneral);
          }
        }


      //certificado de bachiller
      }else{
        for (int i = 0; i < n; i++) {
            if(uni[i].matricula == matri){
              printf("\nCertificado de bachiller del alumno: %s\n",uni[i].alumno.nombre);

              printf("\nNombre del bachiller: %s",uni[i].certificado.nombreBachiller);
              printf("\nFecha de inicio de curso: %i / %i / %i",uni[i].certificado.inicioCurso.dia, uni[i].certificado.inicioCurso.mes, uni[i].certificado.inicioCurso.anio);
              printf("\nFecha de termino de curso: %i / %i / %i",uni[i].certificado.terminoCurso.dia, uni[i].certificado.terminoCurso.mes, uni[i].certificado.terminoCurso.anio);
              printf("\nPromedio final obtenido: %.2f\n",uni[i].certificado.promedioFinal);
            }
        }
      }

  }else{
    printf("\nLa matricula %i no existe o no fue escrita correctamente\n\n",matri);
  }
}



int main(int argc, char const *argv[]) {
  int n; //Numero de alumnos a registrar

  printf("Numero de alumnos a registrar:");
  scanf("%i", &n);

  universidad uni[n];

  int ma=111111111;
  int op, op2;

  do{
    printf("\n----- Menu de operaciones ------\n");
    printf("1.- Registrar alumno\n");
    printf("2.- Mostrar alumnos\n");
    printf("3.- Mostrar tutores\n");
    printf("4.- Modificar datos de alumno\n");
    printf("5.- Salir\n");
    printf("\nOpcion -> ");
    scanf("%d", &op);

    switch (op) {
      case 1: registrarAlumno(uni,n,ma);
              break;

      case 2: mostrarAlumnos(uni,n);
              break;

      case 3: mostrarTutores(uni,n);
              break;

      case 4:
              bool valor;
              int matri;
              do {
                printf("\n----- Menu de operaciones de alumno ------\n");
                printf("1.- Modificar nombre\n");
                printf("2.- Modificar apellido paterno\n");
                printf("3.- Modificar apellido materno\n");
                printf("4.- Modificar edad\n");
                printf("5.- Modificar fecha de nacimiento\n");
                printf("6.- Actualizar calificaciones\n");
                printf("7.- Mostrar materias y calificaciones de un alumno\n");
                printf("8.- Mostrar certificado de bachiller\n");
                printf("9.- Regresar al menu anterior\n");
                printf("\nOpcion -> ");
                scanf("%d", &op2);

                switch (op2) {
                  case 1:
                          valor=false;

                          do{
                            printf("NOTA: La primera matricula inicia en 111111111 \n");
                            printf("Teclea la matricula del alumno a modificar: ");
                            scanf("%i",&matri);

                            if(matri>=111111111 && matri<=999999999){
                              modificarAlumno(uni,n,op2,matri);
                              valor=true;
                            }else{
                              printf("Error: Matricula invalida\n\n");
                            }
                          }while(valor == false);

                          break;

                  case 2:
                          valor=false;

                          do{
                            printf("NOTA: La primera matricula inicia en 111111111 \n");
                            printf("Teclea la matricula del alumno a modificar: ");
                            scanf("%i",&matri);

                            if(matri>=111111111 && matri<=999999999){
                              modificarAlumno(uni,n,op2,matri);
                              valor=true;
                            }else{
                              printf("Error: Matricula invalida\n\n");
                            }
                          }while(valor == false);
                          break;

                  case 3:
                          valor=false;

                          do{
                            printf("NOTA: La primera matricula inicia en 111111111 \n");
                            printf("Teclea la matricula del alumno a modificar: ");
                            scanf("%i",&matri);

                            if(matri>=111111111 && matri<=999999999){
                              modificarAlumno(uni,n,op2,matri);
                              valor=true;
                            }else{
                              printf("Error: Matricula invalida\n\n");
                            }
                          }while(valor == false);
                          break;

                  case 4:
                          valor=false;

                          do{
                            printf("NOTA: La primera matricula inicia en 111111111 \n");
                            printf("Teclea la matricula del alumno a modificar: ");
                            scanf("%i",&matri);

                            if(matri>=111111111 && matri<=999999999){
                              modificarAlumno(uni,n,op2,matri);
                              valor=true;
                            }else{
                              printf("Error: Matricula invalida\n\n");
                            }
                          }while(valor == false);
                          break;

                  case 5:
                          valor=false;

                          do{
                            printf("NOTA: La primera matricula inicia en 111111111 \n");
                            printf("Teclea la matricula del alumno a modificar: ");
                            scanf("%i",&matri);

                            if(matri>=111111111 && matri<=999999999){
                              modificarAlumno(uni,n,op2,matri);
                              valor=true;
                            }else{
                              printf("Error: Matricula invalida\n\n");
                            }
                          }while(valor == false);
                          break;

                  case 6:
                          valor=false;

                          do{
                            printf("NOTA: La primera matricula inicia en 111111111 \n");
                            printf("Teclea la matricula del alumno a modificar: ");
                            scanf("%i",&matri);

                            if(matri>=111111111 && matri<=999999999){
                              modificarAlumno(uni,n,op2,matri);
                              valor=true;
                            }else{
                              printf("Error: Matricula invalida\n\n");
                            }
                          }while(valor == false);
                          break;

                  case 7:
                          valor=false;

                          do{
                              printf("NOTA: La primera matricula inicia en 111111111 \n");
                              printf("Teclea la matricula del alumno a modificar: ");
                              scanf("%i",&matri);

                              if(matri>=111111111 && matri<=999999999){
                                  modificarAlumno(uni,n,op2,matri);
                                  valor=true;
                              }else{
                                  printf("Error: Matricula invalida\n\n");
                              }
                            }while(valor == false);
                            break;

                    case 8:
                            valor=false;

                            do{
                                printf("NOTA: La primera matricula inicia en 111111111 \n");
                                printf("Teclea la matricula del alumno a modificar: ");
                                scanf("%i",&matri);

                                if(matri>=111111111 && matri<=999999999){
                                    modificarAlumno(uni,n,op2,matri);
                                    valor=true;
                                }else{
                                    printf("Error: Matricula invalida\n\n");
                                }
                              }while(valor == false);
                              break;

                }
              }while(op2 != 9);

              break;
    }

  }while(op != 5);

  return 0;
}
