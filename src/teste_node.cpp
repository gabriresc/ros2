#include "rclcpp/rclcpp.hpp" //Biblioteca principal do ROS 2 para C++ — sempre necessária 

using namespace std;

class Meu_no : public rclcpp::Node //Classe que herda de Node, que é a classe base para todos os nós do ROS 2
{
  public:
  Meu_no()// Construtor da classe, que é chamado quando o objeto é criado
  :Node("meu_no") // Chama o construtor da classe base Node, passando o nome do nó como argumento
  {
    RCLCPP_INFO(this -> get_logger(),"No teste"); // Imprime uma mensagem de log no terminal, usando o logger do nó.
  }
};


int main(int argc, char ** argv) // Função principal do programa, que é chamada quando o programa é executado
{
  rclcpp :: init(argc,argv); // Inicializa o ROS 2, passando os argumentos da linha de comando como argumentos
  rclcpp :: spin(make_shared<Meu_no>()); // Cria um objeto do tipo Meu_no, que é o nó do ROS 2, e entra em um loop de execução, onde o nó fica ativo e processando eventos até que seja encerrado
  rclcpp :: shutdown(); // Encerra o ROS 2, liberando os recursos alocados pelo ROS 2
  return 0;
}
