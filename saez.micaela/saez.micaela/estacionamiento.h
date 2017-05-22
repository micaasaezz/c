
typedef struct
{
    char patente[8];
    int marca;
    char modelo[30];
    int idProfesor;
    int estado;

} eAutomovil;

typedef struct
{
    char nombre[30];
    int idIdentificacion;
    int estado;
    int estacionadoAhora;

} eProfesor;


/** \brief hardcodea datos de 10 profesores
 *
 * \param profesor[] eProfesor estructura a hardcodear
 * \return void
 *
 */
void hardcodeaProfesores(eProfesor profesor[]);


/** \brief hardcodea 6 altas de automoviles (juan, maria, pedro, octavio, romina, german)
 *
 * \param automoviles[] eAutomovil   estructura donde se van a guardar los datos
 * \param  profesores[] eProfesor    estructura donde se van a inicializar los estados de profesores
 * \return void
 *
 */
void hardcodea6altasAutomoviles(eAutomovil automoviles[], eProfesor profesores[]);


/** \brief hardcodea 4 ingresos a la playa de estacionamiento (juan, pedro, octavio, german)
 *
 * \param profesores[] eProfesor estructura donde se van a inicializar los estados de estacionamiento
 * \return void
 *
 */
void hardcodea4estacionamientos(eProfesor profesores[]);


/** \brief inicia los estados de automoviles
 *
 * \param automovil[] eAutomovil  estructura a iniciar estados
 * \param tamA int  tamaño de la estructura
 * \return void
 *
 */
void iniciarEstadosA(eAutomovil automovil[], int tamA);


/** \brief inicia los estados de los profesores
 *
 * \param profesores[] eProfesor  estructura a iniciar estados
 * \param tamP int  tamaño de la estructura
 * \return void
 *
 */
void iniciarEstadosP(eProfesor profesores[], int tamP);


/** \brief buscar un lugar libre
 *
 * \param automovil[] eAutomovil estructura donde se busca lugar
 * \param tamA int tamaño de la estructura
 * \return int -1 si no hay lugar / la posicion libre
 *
 */
int buscarLugar(eAutomovil automovil[], int tamA);



/** \brief valida una patente (3letras-3num / 4letras-3num)
 *
 * \param patenteaValidar[] char  Array con la cadena a ser analizada
 * \return int   1 si es una patente valida, 0 si no lo es
 *
 */
int validaPatente(char patenteaValidar[]);


/** \brief da de alta una estructura de automovil
 *
 * \param automovil[] eAutomovil estructura a dar de alta
 * \param posicion int posicion en la que se va a cargar la estructura
 * \param profesor[] eProfesor esructurta de profesor para guardar el nombre
 * \param tamP int tamaño de la estructura de profesores
 * \return int 1 si se pudo realizar el alta, 0 si no se pudo
 *
 */
int altaAutomovil(eAutomovil automovil[], int posicion, eProfesor profesor[], int tamP);


/** \brief da de baja una estructura de automovil
 *
 * \param automovil[] eAutomovil  estructura a dar de baja
 * \param tamA int tamaño de la estructura de automoviles
 * \param profesores[] eProfesor esructurta de profesor para guardar cambiar el estado
 * \param tamP int tamaño de la estructura de profesores
 * \return void
 *
 */
void bajaAutomovil(eAutomovil automovil[], int tamA, eProfesor profesores[], int tamP);


/** \brief registra un ingreso a la Playa de Estacionamiento
 *
 * \param profesores[] eProfesor estructura de profesor que va a ingresar
 * \param tamP int tamaño de la estructura de profesores
 * \return void
 *
 */
void ingresoPlayaEstacionamiento(eProfesor profesores[], int tamP);



/** \brief registra un egreso de la Playa de Estacionamiento
 *
 * \param profesores[] eProfesor profesor que se retira
 * \param tamP int tamaño de la estructuura de profesores
 * \return int 1 si se pudo realizar el alta, 0 si no se pudo
 *
 */
int egresoPlayaEstacionamiento(eProfesor profesores[], int tamP);


/** \brief listar autos segun 4 criterios dif
 *
 * \param automoviles[] eAutomovil automoviles a listar
 * \param tamA int tamaño de la estructura de automoviles
 * \param profesores[] eProfesor profesorres a listar
 * \param tamP int  tamaño de la estructura de profesores
 * \return void
 *
 */
void listarAutos(eAutomovil automoviles[], int tamA, eProfesor profesores[], int tamP);

