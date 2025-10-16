template <typename T>
class MatrizDinamica {
private:
    T **datos;
    int filas;
    int columnas;

public:
    // Constructor, Destructor, Métodos de gestión y operaciones
    // Constructor
    MatrizDinamica(int filas, int columnas){
        this->filas = filas;
        this->columnas = columnas;
        datos = new T*[filas];
        for(int i = 0; i < filas; i++) {
            datos[i] = new T[columnas];
        }
    }
    //Metodos
    void llenarMatriz(){
        for(int i = 0; i < filas; i++) {
            for(int j = 0; j < columnas; j++) {
                std::cout << "Ingrese el valor para la posición [" << i << "][" << j << "]: ";
                std::cin >> datos[i][j];
            }
        }
    }
    void redimensionarMatriz(int newfls, int newcolmns){
        T **aux= new T*[newfls];//creamos la matriz auxiliar
        for(int i = 0; i < newfls; i++) {
            aux[i] = new T[newcolmns];//creamos las columnas de la matriz auxiliar
            for(int j = 0; j < newcolmns; j++) {
                aux[i][j] = 0;//inicializamos la matriz auxiliar en 0
            }    
        }
        //obtenemos la cantiddad de filas y columnas a copiar
        int minfls= (filas< newfls)?filas:newfls;
        int mincols= (columnas< newcolmns)?columnas:newcolmns;
        //ya creada le pasamos los datos de la matriz original a la auxiliar
        for(int i = 0; i < minfls; i++) {
            for(int j = 0; j < mincols; j++) {
                aux[i][j] = datos[i][j];
            }
        }
        //liberamos la memoria de la matriz original
        for(int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        delete[] datos;
        datos=aux;//apuntamos datos a la matriz auxiliar
        filas=newfls;//actualizamos filas y columnas
        columnas=newcolmns;
    }
    void imprimirMatriz(){
        for(int i = 0; i < filas; i++) {
            for(int j = 0; j < columnas; j++) {
                std::cout << datos[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    int getFilas(){
        return filas;
    }
    int getColumnas(){
        return columnas;
    }
    
    template <typename U>

    static MatrizDinamica<U> conversion(MatrizDinamica<T> &A){
        MatrizDinamica<U> Z(A.getFilas(), A.getColumnas());//se crea matriz auxiliar
        for(int i = 0; i < A.getFilas(); i++) {
            for(int j = 0; j < A.getColumnas(); j++) {
                Z.datos[i][j] = static_cast<U>(A.datos[i][j]);//static_cast hace conversion automatica de T a U
            }
        }
        return Z;
    }



    static MatrizDinamica<T> multiplicar(MatrizDinamica<T> &A, MatrizDinamica<U> &B){
        bool verificacion = (A.getColumnas() == B.getFilas()) ? true : false;
        if (verificacion){
            //como las dimensiones son compatibles se puede multiplicar
            MatrizDinamica<T> C(A.getFilas(), B.getColumnas());
            for(int i = 0; i < A.getFilas(); i++) {
                for(int j = 0; j < B.getColumnas(); j++) {
                    C.datos[i][j] = 0; // Inicializar el elemento con el fin de evitar valores basura
                    for(int k = 0; k < A.getColumnas(); k++) {
                        C.datos[i][j] += A.datos[i][k] * B.datos[k][j];
                    }
                }
            }
            return C;
        }else{
            std::cout<<" No se puede realizar la multiplicacion de las matrices A y B por incompatibilidad de dimensiones."<<"\n";
            return MatrizDinamica<T>(0, 0); // Devuelve una matriz de 0x0
        }
    }
    ~MatrizDinamica(){
        for(int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        delete[] datos;
    }
};