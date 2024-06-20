#include <string>
using namespace std;
class Favorito {

private:
  string url;
  string nombre;

public:

  Favorito(): url(""), nombre(""){};
  Favorito(string &urlEnviado, string &nombreEnviado);
  string getUrl() const;
  string getNombre() const;
};
