typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

void initEmployees (eEmployee emptyInput[], int sizeArray, int value);
int buscarEspacio (eEmployee emptyInput[],int tamanio,int valor);



int getStringLetras(char mensaje[],char input[]);
int esSoloLetras(char str[]);
void getString(char mensaje[],char input[]);

void altas(char msg[],eEmployee employees[],int tam);
void mostrar (char msg [],eEmployee employees[], int tam);
int modificar (char msg[],eEmployee employees [],int tam);
int baja (char msg [],eEmployee employees[],int tam);


float getFloat(char msg[]);
int getInt (char msg[]);

int getStringNumeros(char mensaje[],char input[]);
int esNumerico(char str[]);

int getStringSalario(char mensaje[],char input[]);
int getStringNumerosSalario(char mensaje[],char input[]);
int isSalary(char str[]);
void sortEmployees(eEmployee employees[], int tam);
