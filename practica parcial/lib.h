
typedef struct
{
    int idAbonado;
    char nombre[50];
    char apellido[50];
    int flagEstado;

}eAbonado;

typedef struct
{
    int idLlamada;
    int idAbonado;
    int motivo;
    int estado;
    int tiempo;
    int flagEstado;

}eReclamo;

void cargarAbonados(eAbonado abonados[], int tamA);
void iniciarReclamos(eReclamo reclamo[], int tamR);
