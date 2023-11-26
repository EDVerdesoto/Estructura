//librerias

template <typename T>
class Operaciones {
    private:
            T valor1;
            T valor2;
    public:
            Operaciones(T v1, T v2) : valor1(v1), valor2(v2){};
            T suma();
            T resta();
            T multiplicacion();
            T division ();
            void calculo();

            };
